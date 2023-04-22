#pragma once
#include <iostream>
#include "CDocument.h"
#include <list>
#include <string.h>


class CDocACCEPTATE
{
private:
	char* username;
	std::list<CDocument> docAcceptate;
public:
	CDocACCEPTATE();
	CDocACCEPTATE(char*);
	~CDocACCEPTATE();

	char* getUsername();
	std::list<CDocument>* get_docAcc();
};

