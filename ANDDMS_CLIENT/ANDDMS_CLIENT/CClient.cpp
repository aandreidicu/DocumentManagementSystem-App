#include "CClient.h"


CDocPRIMITE* CClient::get_docPrim()
{
	return &docPrim;
}

CDocACCEPTATE* CClient::get_docAcceptate()
{
	return &docAcceptate;
}

CDocRESPINSE* CClient::get_docRespinse()
{
	return &docRespinse;
}

CDocTRIMISE* CClient::get_docTrimise()
{
	return &docTrimise;
}

CClient::CClient(char* NumeServ)
{
	NumeServer = strdup(NumeServ);
	server = INVALID_SOCKET;
}

bool CClient::Start()
{
	WSADATA wsaData;

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		cout << "WSAStartup esuat " << iResult << "\n";
		return false;
	}

	struct addrinfo* result = NULL,
		* ptr = NULL,
		hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo(NumeServer, DEFAULT_PORT, &hints, &result);
	if (iResult != 0)
	{
		cout << "get addrinfo esuat " << iResult << "\n";
		WSACleanup();
		return false;
	}

	ptr = result;

	server = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
	if (server == INVALID_SOCKET)
	{
		cout << "Eroare la socket() " << WSAGetLastError() << "\n";
		freeaddrinfo(result);
		WSACleanup();
		return false;
	}

	iResult = connect(server, ptr->ai_addr, ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR)
	{
		cout << "Eroare la conectare...\n";
		closesocket(server);
		server = INVALID_SOCKET;
	}

	freeaddrinfo(result);

	if (server == INVALID_SOCKET)
	{
		cout << "Eroare la conectarea cu serverul...\n";
		WSACleanup();
		return false;
	}

	return true;
}

void CClient::Stop()
{
	int iResult = shutdown(server, SD_SEND);

	if (iResult == SOCKET_ERROR)
	{
		cout << "Eroare la inchiderea clientului... (" << WSAGetLastError() << ")\n";
	}

	closesocket(server);
	WSACleanup();
}

bool CClient::Trimite(char* msg)
{
	ultmesaj.erase();
	//cout << "val cu strlen " << strlen(msg) << endl;
	//cout << "val cu sizeof " << sizeof(msg) << endl;

	int iResult;
	
	iResult = send(server, msg, strlen(msg), 0);
	//cout << iResult << endl;
	ultmesaj.append(msg);
	//cout << ultmesaj << endl;

	if (iResult == SOCKET_ERROR)
	{
		cout << "Trimitere esuata.. (" << WSAGetLastError() << ")\n";
		Stop();
		return false;
	}
	return true;
}

bool CClient::Primeste()
{
	fd_set activity;
	FD_ZERO(&activity);
	FD_SET(server, &activity);
	char primite[DEFAULT_BUFFER_LENGTH];
	if (FD_ISSET(server, &activity))
	{
		int iResult = recv(server, primite, strlen(primite), 0);

		if (iResult > 0)
		{
			char mesaj[DEFAULT_BUFFER_LENGTH];
			memset(&mesaj, 0, sizeof(mesaj));
			strncpy(mesaj, primite, iResult);
			cout << "Primit : " << mesaj << "\n";
			return true;
		}
	}
	return false;
}

int CClient::get_server()
{
	return server;
}

int* CClient::get_stare()
{
	return &stare;
}

char* CClient::getUser()
{
	return User;
}

std::string CClient::getUsername()
{
	return username;
}

std::string CClient::getPassword()
{
	return passw;
}

void CClient::setUsername(std::string u)
{
	this->username = u;
}

void CClient::setPassword(std::string p)
{
	this->passw = p;
}

std::string CClient::get_afisProv()
{
	return this->afisProv;
}

void CClient::set_afisProv(std::string c)
{
	this->afisProv = c;
}

int CClient::get_numar_doc_prim()
{
	return this->numar_docprimite;
}

//CDocPRIMITE* CClient::get_docPrimiteClient()
//{
//	return &this->docPrimite;
//}


std::string extract(std::string field, std::string buffer)
{
	std::string rez;
	if (field == "continut")
	{
		rez = buffer;
		int pos = rez.find(field);
		rez = rez.substr(pos + field.length() + 1);
	}
	else
	{
		rez = buffer;
		int pos = rez.find(field);
		rez = rez.substr(pos + field.length() + 1); //m-am poz fix pe litera
		pos = rez.find(" ");
		rez = rez.substr(0, pos);
		//std::cout << field << rez << "\n"; 
	}
	return rez;
}

//AUTENTIFICARE 02

void CClient::F_LOGIN(string name, string pass)
{
	this->username = name;
	string mesaj;
	mesaj = "02";

	mesaj.append(" email:");
	mesaj.append(name);

	mesaj.append(" pass:");
	mesaj.append(pass);

	std::cout << mesaj << std::endl;

	Trimite((char*)mesaj.c_str());
}

void CClient::R_LOGIN_SUCCES()
{
	cout << "AUTENTIFICARE REUSITA!" << std::endl;
}

void CClient::R_LOGIN_ESUAT()
{
	cout << "AUTENTIFICARE ESUATA!" << std::endl;
}

//INREGISTRARE 01

void CClient::F_INREGISTRARE(std::string eSI, std::string pSI)
{
	string mesaj;
	mesaj = "01";

	mesaj.append(" email:"); 
	mesaj.append(eSI);

	mesaj.append(" pass:");
	mesaj.append(pSI);

	std::cout << mesaj << std::endl;
	Trimite((char*)mesaj.c_str());
}

void CClient::R_INREGISTRARE_SUCCES()
{
	cout << "INREGISTRAREA REUSITA!" << endl;
}

void CClient::R_INREGISTRARE_ESUAT_DEJA_INREGISTRAT()
{
	cout << "INREGISTRARE ESUATA!(CONTUL ESTE DEJA INREGISTRAT)" << endl;
}

void CClient::R_INREGISTRARE_ESUAT_NUEXISTA()
{
	cout << "INREGISTRARE ESUATA!(CONTUL NU SE AFLA IN BAZA DE DATE.PERSONAL_MTA)" << endl;
}

//DECONECTARE 00
void CClient::F_DECONECTARE()
{
	string mesaj;
	mesaj = "00";
	mesaj.append(" email:");
	mesaj.append(this->getUsername());

	mesaj.append(" pass:");
	mesaj.append(this->getPassword());

	std::cout << mesaj << std::endl;
	Trimite((char*)mesaj.c_str());
}

void CClient::R_DECONECTARE()
{
	cout << "TE-AI DECONECTAT!" << endl;
}

//TRIMITERE SEMNAL PENTRU PRIMIREA DOCUMENTELOR PRIMITE 03
void CClient::F_SEMNAL_PRIMIRE_DOC_PRIMITE()
{
	string mesaj;
	mesaj = "03";
	mesaj.append(" email:");
	mesaj.append(this->getUsername());

	std::cout << mesaj << std::endl;
	Trimite((char*)mesaj.c_str());
}

void CClient::F_SEMNAL_PRIMIRE_DOC_ACCEPTATE()
{
	string mesaj;
	mesaj = "08";
	mesaj.append(" email:");
	mesaj.append(this->getUsername());

	std::cout << mesaj << std::endl;
	Trimite((char*)mesaj.c_str());
}

void CClient::F_SEMNAL_PRIMIRE_DOC_RESPINSE()
{
	string mesaj;
	mesaj = "09";
	mesaj.append(" email:");
	mesaj.append(this->getUsername());

	std::cout << mesaj << std::endl;
	Trimite((char*)mesaj.c_str());
}

void CClient::R_SEMNAL_PRIMIRE_DOC_RESPINSE(std::string buffer)
{
	int ok = 1;
	if (buffer.size() > 5) {
		while (ok)
		{

			std::string aux = buffer;
			int pos = aux.find("$");
			aux = aux.substr(0, pos);
			std::string id = extract("id", aux);
			std::string titlu = extract("titlu", aux);
			std::string data = extract("data", aux);
			std::string ora = extract("ora", aux);
			std::string expeditor = extract("expeditor", aux);
			std::string is_read = extract("is_read", aux);
			//std::string continut = extract("continut", aux);
			std::cout << titlu << " " << data << " " << ora << " " << expeditor << " " << is_read << " " << '\n';
			buffer = buffer.substr(aux.length() + 1);
			if (buffer.empty()) ok = 0;

			CDocument docP(id, titlu, " ", " ", data, ora);
			//this->docPrim.get_docPrimite()->push_back(docP);
			this->get_docRespinse()->get_docRe()->push_back(docP);
		}
	}
}

void CClient::F_SEMNAL_PRIMIRE_DOC_TRIMISE()
{
	string mesaj;
	mesaj = "10";
	mesaj.append(" email:");
	mesaj.append(this->getUsername());

	std::cout << mesaj << std::endl;
	Trimite((char*)mesaj.c_str());
}

void CClient::R_SEMNAL_PRIMIRE_DOC_TRIMISE(std::string buffer)
{
	int ok = 1;
	if (buffer.size() > 5) {
		while (ok)
		{

			std::string aux = buffer;
			int pos = aux.find("$");
			aux = aux.substr(0, pos);
			std::string id = extract("id", aux);
			std::string titlu = extract("titlu", aux);
			std::string data = extract("data", aux);
			std::string ora = extract("ora", aux);
			std::string destinatar = extract("destinatar", aux);
			std::string is_read = extract("is_read", aux);
			std::cout << titlu << " " << data << " " << ora << " " << destinatar << " " << is_read << " " << '\n';
			buffer = buffer.substr(aux.length() + 1);
			if (buffer.empty()) ok = 0;

			CDocument docP(id, titlu, destinatar, " ", data, ora);
			this->get_docTrimise()->get_docTr()->push_back(docP);
		}
	}
}

void CClient::R_SEMNAL_PRIMIRE_DOC_ACCEPTATE(std::string buffer)
{
	int ok = 1;
	if (buffer.size() > 5) {
		while (ok)
		{

			std::string aux = buffer;
			int pos = aux.find("$");
			aux = aux.substr(0, pos);
			std::string id = extract("id", aux);
			std::string titlu = extract("titlu", aux);
			std::string data = extract("data", aux);
			std::string ora = extract("ora", aux);
			std::string expeditor = extract("expeditor", aux);
			std::string is_read = extract("is_read", aux);
			//std::string continut = extract("continut", aux);
			std::cout << titlu << " " << data << " " << ora << " " << expeditor << " " << is_read << " " << '\n';
			buffer = buffer.substr(aux.length() + 1);
			if (buffer.empty()) ok = 0;

			CDocument docP(id, titlu, " ", " ", data, ora);
			//this->docPrim.get_docPrimite()->push_back(docP);
			this->get_docAcceptate()->get_docAcc()->push_back(docP);
		}
	}
}



void CClient::R_SEMNAL_PRIMIRE_DOC_PRIMITE(std::string buffer)
{
	
	int ok = 1;
	if (buffer.size() > 5) {
		while (ok)
		{

			std::string aux = buffer;
			int pos = aux.find("$");
			aux = aux.substr(0, pos);
			std::string id = extract("id", aux);
			std::string titlu = extract("titlu", aux);
			std::string data = extract("data", aux);
			std::string ora = extract("ora", aux);
			std::string expeditor = extract("expeditor", aux);
			std::string is_read = extract("is_read", aux);
			//std::string continut = extract("continut", aux);
			std::cout << titlu << " " << data << " " << ora << " " << expeditor << " " << is_read << " " << '\n';
			buffer = buffer.substr(aux.length() + 1);
			if (buffer.empty()) ok = 0;

			CDocument docP(id, titlu, expeditor, " ", data, ora);
			//this->docPrim.get_docPrimite()->push_back(docP);
			this->get_docPrim()->get_docPrimite()->push_back(docP);
		}
	}
}

int CClient::R_SEMNAL_PRIMIRE_NRDOC_PRIMITE(std::string buffer)
{
	std::string nr = extract("Numar_documente_primite", buffer);
	int nrdoc = stoi(nr);

	return nrdoc;
}

void CClient::setNrDocPrimite(int x)
{
	this->numar_docprimite = x;
	std::cout << "nr doc primite: " << x << '\n';
}
//
//void CClient::R_SEMNAL_PRIMIRE_DOC_PRIMITE(std::string buffer)
//{
//
//
//	std::string id = extract("id", buffer);
//	std::string titlu = extract("titlu", buffer);
//	std::string data = extract("data", buffer);
//	std::string ora = extract("ora", buffer);
//	std::string expeditor = extract("expeditor", buffer);
//	std::string is_read = extract("is_read", buffer);
//
//	CDocument cdoc(id, titlu, expeditor, " ", data, ora);
//	this->get_docPrim()->get_docPrimite()->push_back(cdoc);
//
//}


void CClient::F_SEMNAL_AFISEAZA_CONTINUT_DOCUMENT(std::string id)
{
	string mesaj;
	mesaj = "04";
	mesaj.append(" id:");
	mesaj.append(id);

	std::cout << mesaj << std::endl;
	Trimite((char*)mesaj.c_str());
}

std::string CClient::R_SEMNAL_AFISEAZA_CONTINUT_DOC(std::string buffer)
{
	std::string cont = buffer.substr(3);
	return cont;
}

void CClient::F_TRIMITE_DOCUMENT(std::string tip, std::string subtip, std::string titlu, std::string expeditor, std::string nrTel, std::string data1, std::string data2, std::string local, std::string jud_tr, std::string scop)
{
	string mesaj;
	mesaj = "05";
	mesaj.append(" tip:");
	mesaj.append(tip);

	mesaj.append(" subtip:");
	mesaj.append(subtip);

	mesaj.append(" titlu:");
	mesaj.append(titlu);

	mesaj.append(" expeditor:");
	mesaj.append(this->username);

	mesaj.append(" telefon:");
	mesaj.append(nrTel);

	mesaj.append(" data1:");
	mesaj.append(data1);

	mesaj.append(" data2:");
	mesaj.append(data2);

	mesaj.append(" localitate:");
	mesaj.append(local);

	if (subtip == "1") {
		mesaj.append(" judet:");
		mesaj.append(jud_tr);
	}
	if (subtip == "2")
	{
		mesaj.append(" tara:");
		mesaj.append(jud_tr);
	}

	mesaj.append(" scop:");
	mesaj.append(scop);

	std::cout << mesaj << std::endl;
	Trimite((char*)mesaj.c_str());
}


void CClient::F_ACCEPTA_DOCUMENT(std::string id, std::string email)
{
	std::string fct = "06";
	fct.append(" id:");
	fct.append(id);

	fct.append(" email:");
	fct.append(this->username);

	std::cout << fct << std::endl;
	Trimite((char*)fct.c_str());
}

void CClient::F_RESPINGE_DOCUMENT(std::string id, std::string email)
{
	std::string fct = "07";
	fct.append(" id:");
	fct.append(id);

	fct.append(" email:");
	fct.append(this->username);

	std::cout << fct << std::endl;
	Trimite((char*)fct.c_str());
}

void CClient::string_to_doc(std::string continut)
{
	CHAR username[UNLEN + 1];
	DWORD size = UNLEN + 1;
	GetUserName((TCHAR*)username, &size); //trebuie neaparat modificat sa nu avem caracterele in unicode
	string s(username);
	//std::cout << username << "\n";
	/*if (_mkdir("\\FilesNew") == -1)
		cerr << " Error : " << strerror(errno) << endl;

	else
		cout << "File Created\n";*/
	std::string numeFis = "C:\\users\\" + s + "\\Downloads\\Document";
	//std::cout << numeFis << "\n";
	if (std::ifstream(numeFis + ".doc"))
	{
		//fis 
		int i = 1;
		while (std::ifstream(numeFis + "(" + to_string(i) + ").doc")) i++;
		numeFis.append("(");
		numeFis.append(to_string(i));
		numeFis.append(")");
	}

	std::ofstream file(numeFis + ".doc");
	if (!file)
	{
		std::cout << "File could not be created" << std::endl;
		return;
	}
	file << continut;
	file.close();
}
