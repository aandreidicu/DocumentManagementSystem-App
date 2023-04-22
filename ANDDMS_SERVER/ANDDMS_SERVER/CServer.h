#define _CRT_SECURE_NO_WARNINGS
#pragma once
# include <stdio.h>
# include <iostream>
# include <stdlib.h>
# include <WS2tcpip.h>
# include <WinSock2.h>
# include <string.h>
# include <thread>
# include <list>

# pragma comment(lib,"Ws2_32.lib")

#define DEFAULT_PORT "1001"
#define DEFAULT_BUFFER_LENGTH 10000
#define NR_MAX_CLIENTI 60

#include "CClient.h"

class CServer
{
private:
	SOCKET Server;
	int lista_socket[60];
	std::list<CClient> lista_clienti;

	friend void AscThr(int sock, CServer* s);
	friend void CopThr(int nr,char** sursa, CServer* s, int sock);

public:
	
	CServer();
	void Stop_Sock(int sock);
	bool START_SERVER();	

	CClient* get_Client(int sock);

	void LOGARE(int sock, char* mesaj);
	void INREGISTRARE(int sock, char* mesaj);
	void DECONECTARE(int sock, char* mesaj);

	void SEMNAL_PRIMIRE_DOC_PRIMITE(int sock, char* mesaj);
	void SEMNAL_AFISARE_CONTINUT_DOCUMENTE(int sock,char* mesaj);
	void SEMNAL_TRIMITE_DOCUMENT(int sock, char* mesaj);
	void SEMNAL_ACCEPTA_DOCUMENT(int sock, char* mesaj);
	void SEMNAL_RESPINGE_DOCUMENT(int sock, char* mesaj);

	void SEMNAL_PRIMIRE_DOC_ACCEPTATE(int sock, char* mesaj);
	void SEMNAL_PRIMIRE_DOC_RESPINSE(int sock, char* mesaj);
	void SEMNAL_PRIMIRE_DOC_TRIMISE(int sock, char* mesaj);
};

