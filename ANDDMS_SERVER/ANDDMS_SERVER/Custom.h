#pragma once
#include "Document.h"
class Custom :
    public Document
{
protected:
    std::list<std::string> destinatari;
    bool toTeam;
public:
    Custom(std::string buffer);
    //void add_to_database() {};
    void send(DataBase& db);
};

