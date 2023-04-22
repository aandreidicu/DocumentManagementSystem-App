#include "Sablon.h"
#include "DataBase.h"
#include <fstream>
#include <sstream>

Sablon::Sablon(std::string buffer) :
    Document(buffer)
{
    //characteristics.insert({ "tip", "s" });
    std::string mail = characteristics["expeditor"];
    int pos = mail.find(".");
    int pos2 = mail.find("@");
    std::string nume = mail.substr(pos + 1, pos2 - pos - 1); //m-am poz fix pe litera
    pos = mail.find(".");
    std::string prenume = mail.substr(0, pos);
    nume[0] = toupper(nume[0]);
    for (int i = 1; i < nume.length(); i++)
        nume[i] = tolower(nume[i]);
    prenume[0] = toupper(prenume[0]);
    for (int i = 1; i < prenume.length(); i++)
        prenume[i] = tolower(prenume[i]);
    characteristics.insert({ "nume", nume });
    characteristics.insert({ "prenume", prenume });
    characteristics.insert({ "status","A" });

    add_continut();

};
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;

string readFileIntoString(const string& path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}


void Sablon::add_continut()
{
    //aici o sa am un switch pentru tipurile de sabloane
    //nu merge string in switch
    string filename;
    if (characteristics["subtip"] == "1")
    {
        filename = "Permisie.txt";
    }
    else
        //if (characteristics["subtip"] == "2")
    {
        filename = "Raport_parasire_tara.txt";
    }
    string file_contents;

    file_contents = readFileIntoString(filename);

    //acum in filecontents pun datele din characteristics
    /*string s = "miau miau";
    cout << s.find("miau") << " " << s.find("ham") << "\n";
    if (s.find("ham") == string::npos) cout << "aliluia";*/

    for (auto it = characteristics.begin(); it != characteristics.end(); ++it)
    {
        if (file_contents.find(":" + it->first + ":") != string::npos)
            file_contents.replace(file_contents.find(":" + it->first + ":"), (":" + it->first + ":").length(), it->second);
    }
    //cout << file_contents << endl;
    characteristics.insert({ "continut", file_contents });


    //std::ofstream out("output.doc");
    //out << file_contents;
    //out.close();
}

void Sablon::send(DataBase& db)
{
    //std::cout << "Aici trebuie trimitere catre superior!\n"; 
    ///status: u-unknown(default); a-accepted; r-rejected

    std::string sup = db.get_superior(db.MailToID(characteristics["expeditor"]), 0);
    if (sup == "")
    {
        std::cout << "Nu exista niciun cont de superior creat catre care sa se trimita sablonul\n";
    }
    else
    {
            std::string query = "INSERT INTO documente_destinatari(id_document,id_client,is_read,status) VALUES ( '" + characteristics["id"] + "','" + db.get_superior(db.MailToID(characteristics["expeditor"]), 0) + "',0,'A')";
            //std::cout << query << "\n";
            const char* q = query.c_str();
            db.qstate = mysql_query(db.conn, q);
            if (db.qstate) cout << "Query failed sending doc: " << mysql_error(db.conn) << endl;
    }
}