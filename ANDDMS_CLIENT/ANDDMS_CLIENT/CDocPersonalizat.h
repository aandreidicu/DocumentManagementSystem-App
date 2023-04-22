#pragma once
#include "CDocument.h"
#include <string>

class CDocPersonalizat :
    public CDocument
{
private:
    std::string Path;
public:
    CDocPersonalizat();
};

