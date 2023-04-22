#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <thread>
#include <WS2tcpip.h>
#include <WinSock2.h>


class CClient
{
private:
	char* Username;
	char* Parola;
	int Socket_client;
	char* stare;
	int loged;
	char* buffer;
	
	std::thread* thrd;

public:
	CClient(char* username, char* parola, int sock);
	CClient(int sock);

	int get_sock();
	char** get_buff();
	void set_sock(int sock);
	void set_thread(std::thread* t);


	char* get_nume();
	bool Log_in(char* pass);
};

