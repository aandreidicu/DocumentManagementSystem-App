#pragma once
#include "CDocument.h"
#include <list>
#include <string>

class CSablon :
    public CDocument
{
private:
    char* Tip;
    std::list<std::string> ElementeDeInserat;
public:
    CSablon();

};

