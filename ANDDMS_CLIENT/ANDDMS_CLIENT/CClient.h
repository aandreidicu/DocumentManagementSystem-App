#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <WS2tcpip.h>
#include <WinSock2.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <lmcons.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::Threading;
using namespace std;

# pragma comment(lib,"Ws2_32.lib")
#define DEFAULT_PORT "1001"
#define DEFAULT_BUFFER_LENGTH 512

#include "CTeam.h"
#include <string>
#include <list>
#include "CDocPRIMITE.h"
#include "CDocACCEPTATE.h"
#include "CDocRESPINSE.h"
#include "CDocTRIMISE.h"


class CClient
{
private:
	char* NumeServer;
	char* User;
	SOCKET server;

	int stare;

	std::string username;
	std::string passw;
	
	//std::list<CTeam> teams;
	std::string	ultmesaj;
	CDocPRIMITE docPrim;
	int numar_docprimite = 0;
	std::string afisProv="";

	CDocACCEPTATE docAcceptate;
	CDocRESPINSE docRespinse;
	CDocTRIMISE docTrimise;

public:
	
	CDocPRIMITE* get_docPrim();
	CDocACCEPTATE* get_docAcceptate();
	CDocRESPINSE* get_docRespinse();
	CDocTRIMISE* get_docTrimise();

	CClient(char* NumeServ);

	bool Start();
	void Stop();
	bool Trimite(char* msg);
	bool Primeste();

	int get_server();
	int* get_stare();
	char* getUser();

	std::string getUsername();
	std::string getPassword();
	void setUsername(std::string);
	void setPassword(std::string);

	std::string get_afisProv();
	void set_afisProv(std::string c);
	int get_numar_doc_prim();

	//CDocPRIMITE* get_docPrimiteClient();

	void F_LOGIN(std::string email, std::string parola);
	void R_LOGIN_SUCCES();
	void R_LOGIN_ESUAT();

	void F_INREGISTRARE(std::string emailSI, std::string parolaSI);
	void R_INREGISTRARE_SUCCES();
	void R_INREGISTRARE_ESUAT_DEJA_INREGISTRAT();
	void R_INREGISTRARE_ESUAT_NUEXISTA();

	void F_DECONECTARE();
	void R_DECONECTARE();

	void F_SEMNAL_PRIMIRE_DOC_PRIMITE();
	void R_SEMNAL_PRIMIRE_DOC_PRIMITE(std::string buffer);
	int R_SEMNAL_PRIMIRE_NRDOC_PRIMITE(std::string buffer);
	void setNrDocPrimite(int);

	void F_SEMNAL_PRIMIRE_DOC_ACCEPTATE();
	void R_SEMNAL_PRIMIRE_DOC_ACCEPTATE(std::string buffer);

	void F_SEMNAL_PRIMIRE_DOC_RESPINSE();
	void R_SEMNAL_PRIMIRE_DOC_RESPINSE(std::string buffer);

	void F_SEMNAL_PRIMIRE_DOC_TRIMISE();
	void R_SEMNAL_PRIMIRE_DOC_TRIMISE(std::string buffer);

	void F_SEMNAL_AFISEAZA_CONTINUT_DOCUMENT(std::string id);
	std::string R_SEMNAL_AFISEAZA_CONTINUT_DOC(std::string buffer);


	void F_TRIMITE_DOCUMENT(std::string tip, std::string subtip, std::string titlu, std::string expeditor, std::string nrTel, std::string data1, std::string data2, std::string local, std::string jud_tr, std::string scop);
	void F_ACCEPTA_DOCUMENT(std::string id, std::string email);
	void F_RESPINGE_DOCUMENT(std::string id, std::string email);

	void string_to_doc(std::string continut);
};

ref class Pachet
{
	int Server;
	int stare;
	static Mutex^ mut = gcnew Mutex();
	

public:
	bool continua = true;
	int newform = 0;
	int noform = 0;

	int newformSI = 0;
	int noformSI = 0;

	int liber = 0;

	int nr_inregistrare = 0;

	bool flagafis = false;

	CClient* c;
	Pachet(int Serv, int* sta, CClient* c1)
	{
		c = c1;
		Server = Serv;
		stare = *sta;
	}

	void AscThr()
	{
		char test[] = "0123456789";
		struct sockaddr_in address;
		int addrlen;
		address.sin_family = AF_INET;
		address.sin_port = htons(24050);
		addrlen = sizeof(address);
		fd_set activity;
		int valread;
		int sd = Server;
		FD_ZERO(&activity);
		FD_SET(sd, &activity);
		//FD_ISSET(b.get_sock(),&activity);
		while (true)
		{

			if (FD_ISSET(sd, &activity))
			{
				char buffer[10000];
				memset(buffer, NULL, sizeof(buffer)); //&
				if ((valread = recv(sd, buffer, sizeof(buffer), 0)) < 0)
				{
					cout << "erori la primire";
					exit(1);
				}
				else
				{
					char mesaj[10000];
					//std::cout << "*"<<strlen(buffer) << "*\n";
					//char* mesaj = new char[strlen(buffer)];
					memset(mesaj, NULL, sizeof(mesaj)); //&
					strncpy(mesaj, buffer, valread);
					if (strchr(test, mesaj[0]) != NULL)
					{
						char head[5];
						strncpy(head, mesaj, 2);
						strcpy(head + 2, "\0");
						int headi = atoi(head);
						char expeditor[15];
						char gr[15];
						int i = 3;
						int k = 0;
						if (headi == 10 || headi == 11 || headi == 17)
						{
							while (mesaj[i] != ' ' && i < strlen(mesaj))
							{
								expeditor[k] = mesaj[i];
								i++;
								k++;
							}
							expeditor[k] = '\0';
							i++;
						}
						if (headi == 10)
						{
							k = 0;
							while (mesaj[i] != ' ' && i < strlen(mesaj))
							{
								gr[k] = mesaj[i];
								i++;
								k++;
							}
							gr[k] = '\0';
							i++;
						}
						else
							i++;
						char msg[100];
						memset(msg, NULL, sizeof(msg));
						if (headi != 20)
						{
							int nr = 0;
							strcpy(msg, "");
							for (int k = i; k < strlen(mesaj); k++)
							{
								msg[nr] = mesaj[k];
								nr++;
							}
							if (nr != 0)
								msg[nr] = '\0';
						}
						std::string mesaj1(mesaj);
						//cout << mesaj1 << endl;
						switch (headi)
						{
						case 0:
						{
							c->R_DECONECTARE();
							break;
						}
						case 4:
						{
							
							c->R_LOGIN_SUCCES();
							this->newform = 1;
							break;
						}
						case 5:
						{	
							c->R_LOGIN_ESUAT();
							this->noform = 1;
							break;
						}
						case 7:
						{
							c->R_INREGISTRARE_SUCCES();
							this->newformSI = 1;
							break;
						}
						case 6:
						{
							c->R_INREGISTRARE_ESUAT_DEJA_INREGISTRAT();
							this->noformSI = 1;
							this->nr_inregistrare = 6;
							break;
						}
						case 8:
						{
							c->R_INREGISTRARE_ESUAT_NUEXISTA();
							this->noformSI = 1;
							this->nr_inregistrare = 8;
							break;
						}
						case 9:
						{
							c->get_docPrim()->get_docPrimite()->clear();
							c->R_SEMNAL_PRIMIRE_DOC_PRIMITE(mesaj1);
							break;
						}
						case 3:
						{
							c->setNrDocPrimite(c->R_SEMNAL_PRIMIRE_NRDOC_PRIMITE(mesaj1));
							break;
						}
						case 1:
						{
							std::string continutDoc = c->R_SEMNAL_AFISEAZA_CONTINUT_DOC(mesaj1);
							this->c->set_afisProv(continutDoc);
							this->flagafis = true;
							break;
						}
						case 12:
						{
							c->get_docAcceptate()->get_docAcc()->clear();
							c->R_SEMNAL_PRIMIRE_DOC_ACCEPTATE(mesaj1);
							break;
						}
						case 13:
						{
							c->get_docRespinse()->get_docRe()->clear();
							c->R_SEMNAL_PRIMIRE_DOC_RESPINSE(mesaj1);
							break;
						}
						case 14:
						{
							c->get_docTrimise()->get_docTr()->clear();
							c->R_SEMNAL_PRIMIRE_DOC_TRIMISE(mesaj1);
							break;
						}
						default:
							break;
						}
						
					}
					else
					{
						string erroare;
						erroare = "13";
						erroare.append("\0");
						send(Server, (char*)erroare.c_str(), erroare.length(), 0);
						cout << "Eroare la primirea mesajelor... Mesaj distorsionat!\n";
						cout << "a fost trimisa o cerere de rertansmitere a ultimului mesaj\n";
					}
				}
			}
		}
	}

};

