#include "CDocPRIMITE.h"
#include "CDocACCEPTATE.h"


CDocPRIMITE::CDocPRIMITE()
{
}

CDocPRIMITE::CDocPRIMITE(char* u)
{
	this->username = _strdup(u);
}

CDocPRIMITE::~CDocPRIMITE()
{
}

char* CDocPRIMITE::getUsername()
{
	return this->username;
}

std::list<CDocument>* CDocPRIMITE::get_docPrimite()
{
	return &this->docPrimite;
}






