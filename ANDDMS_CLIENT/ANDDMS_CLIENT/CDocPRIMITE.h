#pragma once
#include <iostream>
#include "CDocument.h"
#include <list>
#include <string.h>


class CDocPRIMITE
{
private:
	char* username;
	std::list<CDocument> docPrimite;
public:
	CDocPRIMITE();
	CDocPRIMITE(char*);
	~CDocPRIMITE();

	char* getUsername();
	std::list<CDocument>* get_docPrimite();
};

