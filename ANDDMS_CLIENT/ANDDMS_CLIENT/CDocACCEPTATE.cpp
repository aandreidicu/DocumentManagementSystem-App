#include "CDocACCEPTATE.h"

CDocACCEPTATE::CDocACCEPTATE()
{
}

CDocACCEPTATE::CDocACCEPTATE(char* u)
{
	this->username = _strdup(u);
}

CDocACCEPTATE::~CDocACCEPTATE()
{
}

char* CDocACCEPTATE::getUsername()
{
	return this->username;
}

std::list<CDocument>* CDocACCEPTATE::get_docAcc()
{
	return &this->docAcceptate;
}
