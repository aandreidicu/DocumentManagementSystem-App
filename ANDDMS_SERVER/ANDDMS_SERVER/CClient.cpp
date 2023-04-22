#define _CRT_SECURE_NO_WARNINGS
#include "CClient.h"

CClient::CClient(char* username, char* parola, int sock)
{
	Username = _strdup(username);
	Parola = _strdup(parola);
	Socket_client = SOCKET(sock);

}

CClient::CClient(int sock)
{
	Socket_client = SOCKET(sock);
	Username = NULL;
	Parola = NULL;
}

int CClient::get_sock()
{
	return Socket_client;
}

char** CClient::get_buff()
{
	return &buffer;
}

void CClient::set_sock(int sock)
{
	Socket_client = sock;
}

void CClient::set_thread(std::thread* t)
{
	thrd = t;
}

char* CClient::get_nume()
{	
	return Username;
}

bool CClient::Log_in(char* pass)
{
	if (!strcmp(Parola, pass))
	{
		strcpy(stare, "online");
		return true;
	}
	return false;
}




