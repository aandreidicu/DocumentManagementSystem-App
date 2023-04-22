#include "Custom.h"

Custom::Custom(std::string buffer)
{
    //characteristics.insert({ "tip", "c" });
    toTeam = 0;
    int ok = 1;
    while (ok)
    {
        std::string aux = buffer;
        std::string field_content;
        int pos = aux.find(":");
        aux = aux.substr(0, pos);
        while (aux[pos] != ' ' && pos > 0) pos--;
        std::string field_name = aux.substr(pos);

        if (field_name == "destinatar")
        {
            aux = buffer;
            pos = aux.find(":");
            aux = aux.substr(pos + 1);
            pos = 0;
            while (aux[pos] != ' ' && aux[pos] != '\0') pos++;
            aux = aux.substr(0, pos);
            destinatari.push_back(aux);
        }
        else
            if (field_name == "toTeam")
            {
                toTeam = 1;
            }
            else
            {
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
            }
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

};


void Custom::send(DataBase& db)
{
    //iau fiecare destinatar si trimit
    //verif daca toflux e un si trimit si pe team atunci
};

