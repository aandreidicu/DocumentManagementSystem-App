#pragma once
#include "IDocument.h"
class DocumentFactory
{
public:
	static IDocument* getDocument(std::string buffer); //pt sablon continut va fi stringul cu datele primite pe socket
		//std::string titlu, std::string expeditor, std::string destinatar, std::string data, std::string continut, std::string status); //status aprobat, respins, neraspuns//vazut/nevazut
};

