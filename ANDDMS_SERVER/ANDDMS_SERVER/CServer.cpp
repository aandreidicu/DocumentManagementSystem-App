#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "CServer.h"
#include <iostream>
#include "DataBase.h"
#include "IDocument.h"
#include "DocumentFactory.h"

using namespace std;
DataBase& db = DataBase::getInstance();

void AscThr(int sock, CServer* s)
{
	struct sockaddr_in address;
	int addrlen;
	address.sin_family = AF_INET;
	address.sin_port = htons(1001);
	addrlen = sizeof(address);
	fd_set activity;
	int valread;
	int sd = sock;
	FD_ZERO(&activity);
	FD_SET(sd, &activity);


	while (TRUE)
	{

		if (FD_ISSET(sd, &activity))
		{
			char  buffer[10000];
			memset(buffer, NULL, sizeof(buffer));
			if ((valread = recv(sd, buffer, sizeof(buffer), 0)) <= 0)
			{
				getpeername(sd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
				cout << "client deconectat: ip=" << inet_ntoa(address.sin_addr) << ", port=" << ntohs(address.sin_port) << " ---> Client SOCK= " << sd << "\n";
				s->Stop_Sock(sd);
				closesocket(sd);
				break;
				exit;
			}
			else
			{
				//cout << valread << endl;
				char  mesaj[DEFAULT_BUFFER_LENGTH];
				memset(mesaj, NULL, sizeof(mesaj));
				strncpy(mesaj, buffer, valread);
				char header[10];
				strncpy(header, mesaj, 2);
				strcpy(header + 2, "\0");
				int val;
				val = atoi(header);
				cout << val;
				//cout << mesaj;
				switch (val)
				{
				case 0:
					cout << " DECONECTARE " << " ---> Client SOCK= " << sd << "\n" <<endl;
					s->DECONECTARE(sd, mesaj);
					break;
				case 1:
					cout << " INREGISTRARE  ---> Client SOCK= " << sd << "\n" << endl;
					s->INREGISTRARE(sd, mesaj);
					break;
				case 2:
					cout << " LOGARE  ---> Client SOCK= " << sd << "\n" << endl;
					s->LOGARE(sd, mesaj);
					break;
				case 3:
					cout << " SEMNAL PRIMIRE DOCUMENTE  ---> Client SOCK= " << sd << "\n" << endl;
					s->SEMNAL_PRIMIRE_DOC_PRIMITE(sd, mesaj);
					break;
				case 4:
					cout << " SEMNAL AFISARE CONTINUT DOCUMENT  ---> Client SOCK= " << sd << "\n" << endl;
					s->SEMNAL_AFISARE_CONTINUT_DOCUMENTE(sd, mesaj);
					break;
				case 5:
					cout << " SEMNAL TRIMITE DOCUMENT  ---> Client SOCK= " << sd << "\n" << endl;
					s->SEMNAL_TRIMITE_DOCUMENT(sd, mesaj);
					break;
				case 6:
					cout << " SEMNAL ACCEPTARE DOCUMENT  ---> Client SOCK= " << sd << "\n" << endl;
					s->SEMNAL_ACCEPTA_DOCUMENT(sd, mesaj);
					break;
				case 7:
					cout << " SEMNAL RESPINGE DOCUMENT  ---> Client SOCK= " << sd << "\n" << endl;
					s->SEMNAL_RESPINGE_DOCUMENT(sd, mesaj);
					break;
				case 8:
					cout << " SEMNAL PRIMIRE DOCUMENTE ACCEPTATE  ---> Client SOCK= " << sd << "\n" << endl;
					s->SEMNAL_PRIMIRE_DOC_ACCEPTATE(sd, mesaj);
					break;
				case 9:
					cout << " SEMNAL PRIMIRE DOCUMENTE RESPINSE  ---> Client SOCK= " << sd << "\n" << endl;
					s->SEMNAL_PRIMIRE_DOC_RESPINSE(sd, mesaj);
					break;
				case 10:
					cout << " SEMNAL PRIMIRE DOCUMENTE TRIMISE  ---> Client SOCK= " << sd << "\n" << endl;
					s->SEMNAL_PRIMIRE_DOC_TRIMISE(sd, mesaj);
					break;
				default:
					break;
				}
			}
			FD_ZERO(&activity);
			FD_SET(sd, &activity);
		}
	}
}

void CopThr(int nr, char** sursa, CServer* s, int sock)
{
	int i, k;
	char* mes;

	for (i = nr * 1323, k = 0; k < 1323; i++, k++)
	{

		*s->get_Client(sock)->get_buff()[i] = (*sursa)[k];
	}
	*s->get_Client(sock)->get_buff()[i] = '\0';
}

void CServer::Stop_Sock(int sock)
{
	for (int i = 0; i < NR_MAX_CLIENTI; i++)
	{
		if (lista_socket[i] = sock)
			lista_socket[i] = 0;
		break;
	}
}

bool CServer::START_SERVER()
{
	int nr_maxim;
	char buffer[DEFAULT_BUFFER_LENGTH];
	struct sockaddr_in address;
	fd_set readfds;
	int addrlen;

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("172.16.7.81");
	address.sin_port = htons(1001);
	addrlen = sizeof(address);

	

	WSADATA wsaData;

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		cout << "WSAStartup failed with error: " << iResult << "\n";
		return false;
	}

	struct addrinfo* result = NULL,
		hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0)
	{
		cout << "getaddrinfo failed with error: " << iResult << "\n";
		WSACleanup();
		return false;
	}
	struct in_addr addr;

	addr.s_addr = ((struct sockaddr_in *)(result->ai_addr))->sin_addr.s_addr;

	Server = INVALID_SOCKET;

	Server = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (Server == INVALID_SOCKET)
	{
		cout << "socket failed with error: " << WSAGetLastError() << "\n";
		freeaddrinfo(result);
		WSACleanup();
		return false;
	}

	int opt = TRUE;
	iResult = setsockopt(Server, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));
	if (iResult == SOCKET_ERROR)
	{
		cout << "Eroare la setarea conexiunii multiple..\n";
		return false;
	}

	iResult = ::bind(Server, (struct sockaddr*)&address, sizeof(address));

	if (iResult == SOCKET_ERROR)
	{
		cout << "bind failed with error: " << WSAGetLastError() << "\n";
		freeaddrinfo(result);
		closesocket(Server);
		WSACleanup();
		return false;
	}

	if (listen(Server, SOMAXCONN) == SOCKET_ERROR)
	{
		cout << "listen failed with error: " << WSAGetLastError() << "\n";
		closesocket(Server);
		WSACleanup();
		return false;
	}

	cout << "Server pornit pe adresa ip: " << inet_ntoa(address.sin_addr) << "\n";
	nr_maxim = NR_MAX_CLIENTI;
	for (int i = 0; i < nr_maxim; i++)
	{
		lista_socket[i] = 0;
	}

	int max_sd, sd;
	int client;
	cout << "Asteptare conexiuni...\n";

	while (TRUE)
	{
		FD_ZERO(&readfds);

		FD_SET(Server, &readfds);
		max_sd = Server;

		for (int i = 0; i < nr_maxim; i++)
		{
			sd = lista_socket[i];

			if (sd > 0)
				FD_SET(sd, &readfds);

			if (sd > max_sd)
				max_sd = sd;
		}

		iResult = select(max_sd + 1, &readfds, NULL, NULL, NULL);

		if ((iResult < 0) && WSAGetLastError() == EINTR)
		{
			cout << "eroare la selectare..\n";
		}

		if (FD_ISSET(Server, &readfds))
		{
			client = accept(Server, NULL, NULL);
			if (client == SOCKET_ERROR)
			{
				cout << "acceptare client esuata... (" << WSAGetLastError() << ")\n";
				closesocket(Server);
				WSACleanup();
				return false;
			}
			cout << "socket nou conectat..."<<"\n";

			for (int i = 0; i < nr_maxim; i++)
			{
				if (lista_socket[i] == 0)
				{
					lista_socket[i] = client;

					std::thread* t = new thread(AscThr, client, this);


					cout << "socket adaugat in lista..." << " Socket = " << lista_socket[i]<<"\n";
					break;
				}
			}
		}
	}
}

CClient* CServer::get_Client(int sock)
{
	int gasit = 0;
	for (std::list<CClient>::iterator i = lista_clienti.begin(); i != lista_clienti.end(); i++)
		if (i->get_sock() == sock)
		{
			gasit = 1;
			return &(*i);
		}
}

void CServer::LOGARE(int sock, char* mesaj)
{
	char user[30];
	char pass[30];
	char* u = strstr(mesaj, "email:");
	char* p = strstr(mesaj, "pass:");
	strncpy(user, mesaj + 9, (p - u) - 7);
	strcpy(user + (p - u) - 7, "\0");
	strcpy(pass, p + 5);

	std::string email(user);
	std::string parola(pass);

	bool gasit=db.existsAccount(email, parola);
	if (gasit == 1)
	{
		//CONTUL A FOST GASIT IN TABELA CONTURI
		cout << "Autentificare REUSITA a utilizatorului: '"<<email<<"'"<<" : '"<<parola<<"' --->"<< "Client SOCK = " << sock <<"\n" << endl;
		char mesajtrimis[10000];
		strcpy(mesajtrimis, "04 ");
		strcat(mesajtrimis, user);
		char buf2[100] = " s-a autentificat cu succes!";
		strcat(mesajtrimis, buf2);
		send(sock, mesajtrimis, strlen(mesajtrimis), 0);
	}
	else
	{
		//contul nu a fost gasit in tabela CONTURI
		cout << "Autentificare NEREUSITA cu credentialele: '" << email << "'" << " : '" << parola << "' --->" << "Client SOCK = " << sock << "\n" << endl;
		char mesajtrimis[10000];
		strcpy(mesajtrimis, "05");
		send(sock, mesajtrimis, strlen(mesajtrimis), 0);
	}
}

void CServer::INREGISTRARE(int sock, char* mesaj)
{
	char user[30];
	char pass[30];
	char* u = strstr(mesaj, "email:");
	char* p = strstr(mesaj, "pass:");
	strncpy(user, mesaj + 9, (p - u) - 7);
	strcpy(user + (p - u) - 7, "\0");
	strcpy(pass, p + 5);

	std::string email(user);
	std::string parola(pass);

	bool gasit_PersonalMTA = db.exists_in_DB(email, "email", "personal_mta");
	bool gasit_Conturi = db.exists_in_DB(email, "email","conturi");
	if (gasit_PersonalMTA == 1)
	{
		if (gasit_Conturi == 1)
		{
			//CONTUL EXISTA DEJA SI ESTE INREGISTRAT
			cout << "INREGISTRARE ESUATA : CONTUL CU EMAIL-UL " << email << " ESTE DEJA INREGISTRAT" << endl;
			char mesajtrimis[10000];
			strcpy(mesajtrimis, "06");
			send(sock, mesajtrimis, strlen(mesajtrimis), 0);
		}
		if (gasit_Conturi == 0)
		{
			//CONTUL EXISTA IN BAZA DE DATE SI NU ESTE INREGISTRAT
			cout << "INREGISTRARE REUSITA : CONTUL CU EMAIL: " << email << " PAROLA: " << parola << endl;
			char mesajtrimis[10000];
			strcpy(mesajtrimis, "07 ");
			strcat(mesajtrimis, user);
			char buf2[100] = " s-a inregistrat cu succes!";
			strcat(mesajtrimis, buf2);
			db.newAccount(email, parola);
			send(sock, mesajtrimis, strlen(mesajtrimis), 0);
		}
	}
	else
	{
		//CONTUL NU EXISTA IN BAZA DE DATE
		cout << "INREGISTRARE ESUATA : CONTUL NU EXISTA IN BAZA DE DATE.TABELA PERSONAL_MTA!" << endl;
		char mesajtrimis[10000];
		strcpy(mesajtrimis, "08");
		send(sock, mesajtrimis, strlen(mesajtrimis), 0);
	}
}

void CServer::DECONECTARE(int sock, char* mesaj)
{
	char user[30];
	char pass[30];
	char* u = strstr(mesaj, "email:");
	char* p = strstr(mesaj, "pass:"); 
	strncpy(user, mesaj + 9, (p - u) - 7);
	strcpy(user + (p - u) - 7, "\0");
	strcpy(pass, p + 5);

	std::string email(user);
	std::string parola(pass);

	cout << "UTILIZATORUL CU CONTUL CU EMAIL: '" << email<<"'" << " S-A DECONECTAT!" << "' --->" << "Client SOCK = " << sock << "\n" << endl;

	char mesajtrimis[10000];
	strcpy(mesajtrimis, "00");
	send(sock, mesajtrimis, strlen(mesajtrimis), 0);
}



void CServer::SEMNAL_PRIMIRE_DOC_PRIMITE(int sock, char* mesaj)
{
	std::string mesaj1(mesaj);
	std::size_t pos = mesaj1.find("email:");
	std::string userstr = mesaj1.substr(pos+6);

	cout << userstr << endl;

	std::string msjstr1 = "09 ";
	std::string msjstr = db.show_doc_primite(userstr);

	msjstr1.append(msjstr);

	send(sock, msjstr1.c_str(), msjstr1.size(), 0);

	std::cout << msjstr1.size() << '\n';
}

void CServer::SEMNAL_PRIMIRE_DOC_ACCEPTATE(int sock, char* mesaj)
{
	std::string mesaj1(mesaj);
	std::size_t pos = mesaj1.find("email:");
	std::string userstr = mesaj1.substr(pos + 6);

	cout << userstr << endl;

	std::string msjstr1 = "12 ";
	std::string msjstr = db.show_doc_acceptate(userstr);
	msjstr1.append(msjstr);

	send(sock, msjstr1.c_str(), msjstr1.size(), 0);
	std::cout << msjstr1.size() << '\n';
}

void CServer::SEMNAL_PRIMIRE_DOC_RESPINSE(int sock, char* mesaj)
{
	std::string mesaj1(mesaj);
	std::size_t pos = mesaj1.find("email:");
	std::string userstr = mesaj1.substr(pos + 6);

	cout << userstr << endl;

	std::string msjstr1 = "13 ";
	std::string msjstr = db.show_doc_respinse(userstr);
	msjstr1.append(msjstr);

	send(sock, msjstr1.c_str(), msjstr1.size(), 0);
	std::cout << msjstr1.size() << '\n';
}

void CServer::SEMNAL_PRIMIRE_DOC_TRIMISE(int sock, char* mesaj)
{
	std::string mesaj1(mesaj);
	std::size_t pos = mesaj1.find("email:");
	std::string userstr = mesaj1.substr(pos + 6);

	cout << userstr << endl;

	std::string msjstr1 = "14 ";
	std::string msjstr = db.show_doc_trimise(userstr);
	msjstr1.append(msjstr);

	send(sock, msjstr1.c_str(), msjstr1.size(), 0);
	std::cout << msjstr1.size() << '\n';
}



void CServer::SEMNAL_AFISARE_CONTINUT_DOCUMENTE(int sock, char* mesaj)
{
	std::string mesaj1(mesaj);
	std::size_t pos = mesaj1.find("id:");
	std::string idstr = mesaj1.substr(pos + 3);


	std::string ft = "01 ";
	std::string continut = db.get_continut(idstr);

	ft.append(continut);
	std::cout << ft << '\n';

	send(sock, ft.c_str(), ft.size(), 0);
}

void CServer::SEMNAL_TRIMITE_DOCUMENT(int sock, char* mesaj)
{
	std::string strmsj(mesaj);
	std::string strmsjF = strmsj.substr(3);

	IDocument* doc = DocumentFactory::getDocument(strmsjF);
	doc->add_to_database(db);
	doc->send(db);
}

void CServer::SEMNAL_ACCEPTA_DOCUMENT(int sock, char* mesaj)
{
	
	std::string strmsj(mesaj);
	std::size_t pos = strmsj.find("id:");
	std::string id = strmsj.substr(pos+3);
	pos = id.find(" ");
	id = id.substr(0, pos);
	std::cout << id << std::endl;

	std::size_t posemail = strmsj.find("email:");
	std::string email = strmsj.substr(posemail + 6);
	std::cout << email << std::endl;

	//fct
	db.accept_doc(email, id);
}

void CServer::SEMNAL_RESPINGE_DOCUMENT(int sock, char* mesaj)
{

	std::string strmsj(mesaj);
	std::size_t pos = strmsj.find("id:");
	std::string id = strmsj.substr(pos + 3);
	pos = id.find(" ");
	id = id.substr(0, pos);
	std::cout << id << std::endl;

	std::size_t posemail = strmsj.find("e	ail:");
	std::string email = strmsj.substr(posemail + 6);
	std::cout << email << std::endl;

	//fct
	db.reject_doc(email, id);
}






CServer::CServer()
{
}
