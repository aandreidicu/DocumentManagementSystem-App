#pragma once
#include <iostream>
#include "CDocument.h"
#include <list>
#include <string.h>


class CDocRESPINSE
{
private:
	char* username;
	std::list<CDocument> docRespinse;
public:
	CDocRESPINSE();
	CDocRESPINSE(char*);
	~CDocRESPINSE();

	char* getUsername();
	std::list<CDocument>* get_docRe();
};

