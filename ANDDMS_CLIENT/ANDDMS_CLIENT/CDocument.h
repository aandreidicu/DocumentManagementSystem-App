#pragma once
#include <string>
class CDocument
{
public:
	std::string id;
	std::string titlu;
	std::string expeditor;
	std::string destinatar;
	std::string data;
	std::string ora;
public:
	CDocument(std::string i, std::string t, std::string e, std::string d, std::string da, std::string or);
	~CDocument();

};

