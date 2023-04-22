#include "CDocRESPINSE.h"

CDocRESPINSE::CDocRESPINSE()
{
}

CDocRESPINSE::CDocRESPINSE(char* u)
{
	this->username = _strdup(u);
}

CDocRESPINSE::~CDocRESPINSE()
{
}

char* CDocRESPINSE::getUsername()
{
	return this->username;
}

std::list<CDocument>* CDocRESPINSE::get_docRe()
{
	return &this->docRespinse;
}
