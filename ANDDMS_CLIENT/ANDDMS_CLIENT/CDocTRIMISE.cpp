#include "CDocTRIMISE.h"

CDocTRIMISE::CDocTRIMISE()
{
}

CDocTRIMISE::CDocTRIMISE(char* u)
{
	this->username = _strdup(u);
}

CDocTRIMISE::~CDocTRIMISE()
{
}

char* CDocTRIMISE::getUsername()
{
	return this->username;
}

std::list<CDocument>* CDocTRIMISE::get_docTr()
{
	return &this->docTrimise;
}
