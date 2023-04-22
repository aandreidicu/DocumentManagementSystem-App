#include "Document.h"
#include "DataBase.h"
#include <ctime>

Document::Document(std::string buffer)
{
    int ok = 1;
    while (ok)
    {
        std::string aux = buffer;
        std::string field_content;
        int pos = aux.find(":");
        aux = aux.substr(0, pos);
        while (aux[pos] != ' ' && pos > 0) pos--;
        std::string field_name = aux.substr(pos);

        if (field_name != "continut" && field_name != "scop")
        {
            aux = buffer;
            pos = aux.find(":");
            aux = aux.substr(pos + 1);
            pos = 0;
            while (aux[pos] != ' ' && aux[pos] != '\0') pos++;
            aux = aux.substr(0, pos);
            field_content = aux;
        }
        else
        {
            aux = buffer;
            pos = aux.find(":");
            aux = aux.substr(pos + 1);
            field_content = aux;
            buffer = "";
        }
        characteristics.insert({ field_name, field_content });
        if (buffer.empty()) break;
        buffer = buffer.substr(field_content.length() + 2 + field_name.length()); //2 caract - ':'+' '
    }
    //add date and time

    time_t rawtime;
    struct tm* timeinfo;
    char data[80]; char ora[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(data, sizeof(data), "%Y-%m-%d", timeinfo);
    std::string str1(data);

    strftime(ora, sizeof(ora), "%H:%M:%S", timeinfo);
    std::string str2(ora);

    //std::cout << str1 << " " << str2;
    characteristics.insert({ "data", data });
    characteristics.insert({ "ora", ora });
    //std::cout << "\n*data:"<<characteristics["data"] << " ora:" << characteristics["ora"]<<"\n";
}

std::string blanc_spaces(std::string str)
{
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '_') {
            str[i] = ' ';
        }
    }
    return str;
}

void Document::add_to_database(DataBase& db)
{
    if (characteristics["tip"] == "s")
    {
        std::string sup = db.get_superior(db.MailToID(characteristics["expeditor"]), 0);
        if (sup == "")
            return;
    }
    if (characteristics["tip"] == "s" && characteristics["continut"].find(":rol:") != std::string::npos)
        characteristics["continut"].replace(characteristics["continut"].find(":rol:"), 5, blanc_spaces(db.get_rol(characteristics["expeditor"])));

    characteristics.insert({ "id", std::to_string(db.NumberOfRows("documente") + 1) });
    std::string query = "INSERT INTO documente VALUES ( '" + characteristics["id"] + "','" + characteristics["titlu"] + "','" + characteristics["expeditor"] +
        "','" + characteristics["data"] + "','" + characteristics["ora"] + "','" + characteristics["continut"] + "','" +
        characteristics["tip"] + "')";
    //std::cout << query << "\n";
    const char* q = query.c_str();
    db.qstate = mysql_query(db.conn, q);
}


//
//Document::Document(std::string buffer)
//{
//    int ok = 1;
//    while (ok)
//    {
//        std::string aux = buffer;
//        int pos = aux.find(":");
//        aux = aux.substr(0, pos);
//        while (aux[pos] != ' ' && pos > 0) pos--;
//        std::string field_name = aux.substr(pos);
//        aux = buffer;
//        pos = aux.find(":");
//        aux = aux.substr(pos+1);
//        pos = 0;
//        while (aux[pos] !=' ' && aux[pos]!='\0') pos++;
//        aux = aux.substr(0,pos);
//        std::string field_content = aux;
//        characteristics.insert({ field_name, field_content });
//    }
//}

//Document::Document(std::string buffer)//titlu, std::string expeditor, std::string data, std::string continut)
//{
    //char* copy = new char(buffer.length());
    //strcpy(copy, buffer.c_str());
    //copy=strstr(copy, (char*)"titlu:");
    //copy = copy + 7;
    //char* aux = copy;
    ////copy=strstr
    //std::cout << copy;
    //this->titlu = titlu;
    //this->expeditor = expeditor;
    //this->data = data;
    //this->continut = continut;
//}

