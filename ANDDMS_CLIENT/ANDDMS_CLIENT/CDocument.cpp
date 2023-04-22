#include "CDocument.h"
#include <iostream>




CDocument::CDocument(std::string i, std::string t, std::string e, std::string d, std::string da, std::string or)
{
	this->id = i;
	this->titlu = t;
	this->expeditor = e;
	this->destinatar = d;
	this->data = da;
	this->ora = or ;

}

CDocument::~CDocument()
{
}


