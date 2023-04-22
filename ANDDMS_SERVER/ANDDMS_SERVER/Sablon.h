#pragma once
#include "Document.h"
class Sablon :
    public Document
{
public:
    Sablon(std::string buffer);
    //void add_to_database();
    void send(DataBase& db);
    void add_continut();
    //void change_status(); //tot aici daca e aprobat, se trimite la superior; nu aici, ci in db
};

