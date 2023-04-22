#pragma once
#include "IDocument.h"
//#include "DataBase.h"
class DataBase;
class Document :
    public IDocument
{
protected:
    /* std::string titlu;
     std::string expeditor;
     std::string data;
     std::string continut;
     std::string tip;*/
    std::map<std::string, std::string> characteristics;
public:
    Document(std::string buffer);
    Document() {};
    void add_to_database(DataBase& db);
    void send(DataBase& db) { std::cout << "Eroare trimitere! Tip document nespecificat!\n"; };
    //void extract_nume_prenume(std::string mail, std::string nume, std::string prenume);
};
