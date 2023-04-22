#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mysql.h>
#include <string>
//#include "Flux.h"
#include "Document.h"
#include "Sablon.h"
#include "Custom.h"
//class Document;
class DataBase
{
private:

	static int qstate;
	static MYSQL* conn;

	static DataBase* instance;
	DataBase();
	DataBase(const DataBase&) {};
	~DataBase() { destroyInstance(); };

public:
	static DataBase& getInstance();
	static void destroyInstance();

	bool newAccount(std::string mail, std::string passw);
	bool existsAccount(std::string mail, std::string passw);
	void changePassword(std::string mail, std::string passw);
	void deleteAccount(std::string mail);
	void change_connection_state(std::string mail, std::string passw, int connect);

	//void createFluxList();
	void add_to_team(std::string id, std::string rol);

	bool exists_in_DB(std::string val, std::string coloana, std::string tabel);

	//mail = mailul persoanei care a acceptat/refuzat/citit
	void read_doc(std::string mail, std::string id_doc);
	void accept_doc(std::string mail, std::string id_doc);
	void reject_doc(std::string mail, std::string id_doc);

	void get_nr_doc_primite(std::string mail);
	//void show_doc_primite(std::string mail);
	std::string show_doc_primite(std::string mail);
	std::string show_doc_trimise(std::string mail);
	std::string show_doc_acceptate(std::string mail);
	std::string show_doc_respinse(std::string mail);

	std::string get_continut(std::string idDoc);

	std::string MailToID(std::string mail);
	int NumberOfRows(std::string NumeTabel);
	//std::string getRolFromID(std::string id);
	//std::string getIDFluxFromID(std::string id);
	std::string get_superior(std::string mail, int ok);
	int get_rolID(std::string rol);
	std::string get_rol(std::string mail);

	//friend class Document;
	friend void Document::add_to_database(DataBase& db);
	friend void Document::send(DataBase& db);
	friend void Sablon::send(DataBase& db);
	friend void Custom::send(DataBase& db);
};
