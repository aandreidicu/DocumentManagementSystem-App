#pragma once
#include <iostream>
#include "CDocument.h"
#include <list>
#include <string.h>


class CDocTRIMISE
{
private:
	char* username;
	std::list<CDocument> docTrimise;
public:
	CDocTRIMISE();
	CDocTRIMISE(char*);
	~CDocTRIMISE();

	char* getUsername();
	std::list<CDocument>* get_docTr();
};

