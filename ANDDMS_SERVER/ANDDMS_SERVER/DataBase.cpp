#include "DataBase.h"
//#include "Document.h"

DataBase* DataBase::instance = nullptr;
MYSQL* DataBase::conn = nullptr;
int DataBase::qstate = 0;
using namespace std;


DataBase::DataBase()
{
	std::cout << "===================SERVER===================" << std::endl;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "Andrei011001", "dms", 3306, NULL, 0); //aici trebuie sa vad cum ne legam amandoi la acelasi database sau rulez eu ca server
	//in loc de localhost trebuie adresa ip a hostului pentru conexiuni remote
	if (conn)
	{
		cout << "Successful connection to database\n";
		//runQUERY();
	}
	else cout << "Connection to database failed!\n";
	//aici va trebui un throw - sa ne stabilim codul de erori

}

DataBase& DataBase::getInstance()
{
	if (!instance)
	{
		instance = new DataBase();
	}
	return *instance;
}

void DataBase::destroyInstance()
{
	if (!instance)
	{
		delete instance;
		instance = nullptr;
	}
}

bool DataBase::exists_in_DB(string val, string coloana, string tabel)
{
	bool ok = 0;
	MYSQL_ROW row;
	MYSQL_RES* res;
	string query = "SELECT * FROM " + tabel + " WHERE " + coloana + " = \"" + val + "\"";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	//cout << query << "*\n";
	if (!qstate)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		if (row)
		{
			//mysql_free_result(res);
			ok = 1;

		}
		mysql_free_result(res);
		return ok;
	}
	return (bool)0;
}

void DataBase::deleteAccount(string mail)
{
	if (!exists_in_DB(mail, "email", "conturi"))
	{
		cout << "Email incorect la stergerea contului!\n";
		return;
	}
	else
	{

		string query = "DELETE FROM conturi WHERE email = '" + mail + "'";
		const char* q = query.c_str();
		mysql_query(conn, q);
		string id = MailToID(mail);
		//cout << "\n"<<id << "\n";
		query = "DELETE FROM teams_clienti WHERE ID_Client = '" + id + "'";
		q = query.c_str();
		mysql_query(conn, q);
	}
}

string DataBase::MailToID(string mail)
{
	if (!exists_in_DB(mail, "email", "personal_mta"))
	{
		cout << "email invalid\n";
	}
	else
	{
		MYSQL_ROW row;
		MYSQL_RES* res;
		string query = "SELECT id_persoana FROM personal_mta where email = '" + mail + "'";
		const char* q = query.c_str();
		int qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			string rez = row[0];
			mysql_free_result(res);

			//cout << rez << "\n";
			return rez;
		}
		else cout << "Query failed: " << mysql_error(conn) << endl;
	}
	return NULL;
}

int DataBase::NumberOfRows(string NumeTabel)
{
	int rez = 0;
	//MYSQL_ROW row;
	MYSQL_RES* res;
	string query = "SELECT * FROM " + NumeTabel;
	//cout << query << "*\n";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate)
	{
		rez++;
		res = mysql_store_result(conn);
		/*row = mysql_fetch_row(res);
		for (; row = mysql_fetch_row(res); rez++);*/
		rez = mysql_num_rows(res);
		mysql_free_result(res);
	}
	return rez;
}

bool DataBase::existsAccount(string mail, string passw)
{
	int ok = 0;
	MYSQL_ROW row;
	MYSQL_RES* res;
	string query = "SELECT * FROM Conturi WHERE email = \"" + mail + "\" and parola= \"" + passw + "\"";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	//cout << query << "*\n";
	if (!qstate)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		if (row)
		{
			//mysql_free_result(res);
			//sa pun aici is_connected=1?
			ok = 1;

		}
		mysql_free_result(res);
		return ok;
	}
	return 0;
}

void DataBase::change_connection_state(string mail, string password, int connect)
{
	string query = "UPDATE Conturi SET is_connected=" + string(1, (connect + '0')) + " WHERE email = \"" + mail + "\" and parola= \"" + password + "\"";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
}

void DataBase::changePassword(string mail, string passw) //done
{
	if (!exists_in_DB(mail, "email", "Conturi"))
	{
		cout << "Email incorect la schimbarea parolei!\n";
		return;
	}
	else
	{
		string query = "UPDATE Conturi SET parola= '" + passw + "' where email = '" + mail + "'";
		const char* q = query.c_str();
		mysql_query(conn, q);
	}
}

void extractData_from_EMAIL(string email, string& nume, string& prenume) //done
{
	char aux[30];
	strcpy(aux, email.c_str());
	prenume = strtok(aux, ".");
	nume = strtok(NULL, "@");

}

std::string DataBase::get_superior(string id_curr, int ok)
{
	if (!exists_in_DB(id_curr, "id_persoana", "personal_mta"))
	{
		cout << "ID incorect la cautarea superiorului!\n";
		return "";
	}
	if (exists_in_DB(id_curr, "id_client", "conturi") && ok)
		return id_curr;
	else
	{
		//std::cout<<id_curr;
		std::string id_sup;

		MYSQL_ROW row;
		MYSQL_RES* res;
		string query = "select id_superior from personal_mta where id_persoana = \"" + id_curr + "\"";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			if (*row == NULL)
				return "";
			id_sup = row[0];
			return get_superior(id_sup, 1);
		}
		else cout << "Query failed getting id_sup: " << mysql_error(conn) << endl;
		//std::cout << id_curr << "*\n";
	}
	return "";

}

int DataBase::get_rolID(std::string numeRol)
{
	char* dup = _strdup(numeRol.c_str());
	char* token = strtok(dup, "_");
	/*for (int i = 0; i < strlen(token); i++)
		token[i] = tolower(token[i]);*/
	for (int i = 0; i < strlen(token); i++)
		if (isupper(token[i + 1]))
		{
			char aux[45];
			strcpy(aux, token + i + 1);
			token[i + 1] = ' ';
			strcpy(token + i + 2, aux);
			i++;
		}
	token[strlen(token)] = '\0';
	numeRol = token;
	//free(dup); free(token);
	//cout << "*" << numeRol << "*\n";
	if (exists_in_DB(numeRol, "denumire", "roluri"))
	{
		//return id
		MYSQL_ROW row;
		MYSQL_RES* res;
		string query = "SELECT * FROM roluri WHERE denumire = \"" + numeRol + "\"";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			return atoi(row[0]);
		}
		else cout << "Query failed getting rolID(existing row): " << mysql_error(conn) << endl;
	}
	else
	{
		//insert into db
		//inserez rolul in tabela roluri
		int id;
		MYSQL_ROW row;
		MYSQL_RES* res;
		string query = "SELECT MAX(id_rol) FROM roluri";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			id = atoi(row[0]) + 1;
			char* dup = _strdup(numeRol.c_str());
			char* token = strtok(dup, "_");
			for (int i = 0; i < strlen(token); i++)
				token[i] = tolower(token[i]);
			//free(dup);
			////cout <<"\n****"<< numeRol << "--->" << token << '\n';
			//if(!strcmp(token,"student")||!strcmp(token,"profesor"))
			//	strcpy(token, "cadru militar")
			query = "INSERT INTO roluri VALUES ( '" + to_string(id) + "','" + token + "')";
			const char* q = query.c_str();
			mysql_query(conn, q);
			return id;

		}
		else cout << "Query failed getting rolID(new row): " << mysql_error(conn) << endl;
	}
	cout << "Eroare";
	return -1;
}

std::string DataBase::get_rol(std::string mail)
{
	std::string query = "select rol from personal_mta where email=\"" + mail + "\"";
	//std::cout << query << "\n";
	const char* q = query.c_str();
	MYSQL_RES* res;
	MYSQL_ROW row;
	qstate = mysql_query(conn, q);
	res = mysql_store_result(conn);
	row = mysql_fetch_row(res);
	std::string rol = row[0];
	mysql_free_result(res);
	return rol;
}

void DataBase::add_to_team(string id, string numeRol)
{
	char* dup = _strdup(numeRol.c_str());
	char* token = strtok(dup, "_");
	/*for (int i = 0; i < strlen(token); i++)
		token[i] = tolower(token[i]);*/
	for (int i = 0; i < strlen(token); i++)
		if (isupper(token[i + 1]))
		{
			char aux[45];
			strcpy(aux, token + i + 1);
			token[i + 1] = ' ';
			strcpy(token + i + 2, aux);
			i++;
		}
	token[strlen(token)] = '\0';
	numeRol = token;
	string idFlux;
	if (numeRol == "Student")
	{
		idFlux = '1';
	}
	else
		if (numeRol == "Profesor")
		{
			idFlux = '2';
		}
		else
		{
			idFlux = '3';
		}
	string query = "INSERT INTO teams_clienti(id_flux, id_client) VALUES ('" + idFlux + "','" + id + "')";
	const char* q = query.c_str();
	mysql_query(conn, q);
}

bool DataBase::newAccount(string mail, string passw)
{
	//cand adaug cont verific daca rolul exista deja
	if (exists_in_DB(mail, "email", "Conturi"))
	{
		cout << "Cont deja existent!\n";
		return 0;
	}
	else
	{
		if (!exists_in_DB(mail, "email", "personal_mta"))
		{
			cout << "Email incorect!\n";
			return 0;
		}
		else
		{
			MYSQL_ROW row;
			MYSQL_RES* res;
			string query = "SELECT * FROM personal_mta WHERE email = \"" + mail + "\"";
			const char* q = query.c_str();
			qstate = mysql_query(conn, q);
			if (!qstate)
			{
				res = mysql_store_result(conn);
				row = mysql_fetch_row(res);
				//aici fac insertul
				string id = row[0]; //id=cod rol
				//string email=row[1];
				//string rol = getRolFromID(row[2]);
				//mysql_free_result(res);

				cout << id << " " << mail << " " << row[2];
				query = "INSERT INTO conturi VALUES ( '" + id + "','" + mail + "','" + passw + "','" + to_string(get_rolID(row[2])) + "', 0)";
				const char* q = query.c_str();
				mysql_query(conn, q);

				mysql_free_result(res);
				//de bagat intrare si in teams_clienti
				add_to_team(id, row[2]);
			}
			else cout << "Query failed: " << mysql_error(conn) << endl;
		}
	}
	return 1;
}


///status: u-unknown(default); a-accepted; r-rejected
void DataBase::read_doc(std::string mail, std::string id_doc)
{
	std::string query = "update documente_destinatari set is_read = 1 where id_document = " + id_doc + " and id_client = " + MailToID(mail);
	//std::cout << query << "\n";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
}

void DataBase::accept_doc(std::string mail, std::string id_doc)
{
	std::string id_client = MailToID(mail);
	std::string query = "update documente_destinatari set status = 'A' where status='U' and id_document = " + id_doc + " and id_client = " + id_client;
	//std::cout << query << "\n";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);

	//inserare in tabela pentru urmatorul superior
	std::string id_sup = get_superior(id_client, 0);
	if (id_sup == "")
	{
		std::string query = "update documente_destinatari set status = 'F' where id_document = " + id_doc + " and id_client = " + id_client;
		q = query.c_str();
		qstate = mysql_query(conn, q);
	}
	else
	{
		query = "INSERT INTO documente_destinatari(id_document, id_client, is_read, status) VALUES('" + id_doc + "', '" + id_sup + "', 0, 'U')";
		//std::cout << query << "\n";
		q = query.c_str();
		qstate = mysql_query(conn, q);
	}
}

void DataBase::reject_doc(std::string mail, std::string id_doc)
{
	std::string query = "update documente_destinatari set status = 'R' where status='U' and id_document = " + id_doc + " and id_client = " + MailToID(mail);
	//std::cout << query << "\n";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
}

//
//std::string DataBase::show_doc_primite(std::string mail)
//{
//	std::string client_id = MailToID(mail);
//	std::string output="";
//	MYSQL_RES* res;
//	MYSQL_ROW row;
//	string query = "select documente.id_document, documente.titlu, documente.data, documente.ora, documente.expeditor, documente_destinatari.is_read, documente.continut from documente_destinatari inner join documente on documente.id_document=documente_destinatari.id_document where id_client = " + client_id;// +" limit 1";
//	const char* q = query.c_str();
//	qstate = mysql_query(conn, q);
//	if (!qstate)
//	{
//		res = mysql_store_result(conn);
//		while (row = mysql_fetch_row(res))
//		{
//			/*for(int i=0;i<6;i++)
//				std::cout << row[i] << " ";
//			std::cout << "\n";*/
//			output.append("id:"); output.append(row[0]);
//			output.append(" titlu:"); output.append(row[1]);
//			output.append(" data:"); output.append(row[2]);
//			output.append(" ora:"); output.append(row[3]);
//			output.append(" expeditor:"); output.append(row[4]);
//			output.append(" is_read:"); output.append(row[5]);
//			output.append(" continut:"); output.append(row[6]);
//			output.append("$");
//		}
//
//		mysql_free_result(res);
//	}
//	else cout << "Query failed getting received documents: " << mysql_error(conn) << endl;
//	//std::cout << id_curr << "*\n";
//	return output;
//}

void DataBase::get_nr_doc_primite(std::string mail)
{
	std::string client_id = MailToID(mail);
	std::string output = "";
	//string query = "select documente.id_document, documente.titlu, documente.data, documente.ora, documente.expeditor, documente_destinatari.is_read, documente.continut from documente_destinatari inner join documente on documente.id_document=documente_destinatari.id_document where id_client = " + client_id;// +" limit 1";
	string query = "select count(*) from documente_destinatari inner join documente on documente.id_document=documente_destinatari.id_document where id_client = " + client_id;// +" limit 1";
	MYSQL_RES* res;
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
}

std::string DataBase::show_doc_primite(std::string mail)
{
	std::string client_id = MailToID(mail);
	std::string output = "";
	MYSQL_RES* res;
	MYSQL_ROW row;
	string query = "select documente.id_document, documente.titlu, documente.data, documente.ora, documente.expeditor, documente_destinatari.is_read from documente_destinatari inner join documente on documente.id_document=documente_destinatari.id_document where id_client = " + client_id + " and documente_destinatari.status<> \"R\" ";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	res = mysql_store_result(conn);
	while (row = mysql_fetch_row(res))
	{
		//output = "";
		output.append("id:"); output.append(row[0]);
		output.append(" titlu:"); output.append(row[1]);
		output.append(" data:"); output.append(row[2]);
		output.append(" ora:"); output.append(row[3]);
		output.append(" expeditor:"); output.append(row[4]);
		output.append(" is_read:"); output.append(row[5]);
		//output.append(" continut:"); output.append(row[6]);
		output.append("$");
	}

	mysql_free_result(res);
	return output;
}

std::string DataBase::show_doc_trimise(std::string mail)
{
	std::string client_id = MailToID(mail);
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string output = "";
	//string query = "select documente.id_document, max(documente.titlu), max(documente.data), max(documente.ora), max(conturi.email), max(documente_destinatari.status), max(documente.continut) from documente_destinatari inner join documente on documente.id_document=documente_destinatari.id_document inner join conturi on conturi.id_client=documente_destinatari.id_client where documente.expeditor = \"" + mail + "\"  group by documente.id_document order by documente_destinatari.id_documente_destinatari desc";// , documente.titlu, documente.data, documente.ora, conturi.email";// limit 1";
	//string query = "select documente.id_document, documente.titlu, documente.data, documente.ora, conturi.email, documente_destinatari.status, documente.continut from documente_destinatari inner join documente on documente.id_document=documente_destinatari.id_document inner join conturi on conturi.id_client=documente_destinatari.id_client where documente.expeditor = \"" + mail + "\"  group by documente.id_document, documente.titlu, documente.data, documente.ora, conturi.email order by documente_destinatari.id_documente_destinatari desc limit 1";// 
	//string query = "select documente.id_document, documente.titlu, documente.data, documente.ora, max(conturi.email), documente_destinatari.status, documente.continut from documente_destinatari inner join documente on documente.id_document = documente_destinatari.id_document inner join conturi on conturi.id_client = documente_destinatari.id_client where documente.expeditor = \"" + mail + "\" group by documente.id_document, documente.titlu, documente.data, documente.ora order by documente_destinatari.id_documente_destinatari desc";
	string query = "with d as	(select documente_destinatari.id_document, max(documente_destinatari.id_client) as id_client from documente_destinatari	group by documente_destinatari.id_document)	select d.id_document, documente.titlu, documente.data, documente.ora, conturi.email, documente_destinatari.status, documente.continut from d inner join conturi	on d.id_client = conturi.id_client inner join documente_destinatari	on conturi.id_client = documente_destinatari.id_client and d.id_document = documente_destinatari.id_document inner join documente on documente.id_document = documente_destinatari.id_document where documente.expeditor =  \"" + mail + "\"";
	std::cout << query<<'\n';
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate)
	{
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			output.append("id:"); output.append(row[0]);
			output.append(" titlu:"); output.append(row[1]);
			output.append(" data:"); output.append(row[2]);
			output.append(" ora:"); output.append(row[3]);
			output.append(" destinatar:"); output.append(row[4]);
			output.append(" status:"); output.append(row[5]);
			//output.append(" continut:"); output.append(row[6]);
			output.append("$");
		}

		mysql_free_result(res);
	}
	else cout << "Query failed getting received documents: " << mysql_error(conn) << endl;
	//std::cout << id_curr << "*\n";
	return output;
}

std::string DataBase::show_doc_acceptate(std::string mail)
{
	std::string client_id = MailToID(mail);
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string output = "";
	string query = "select documente.id_document, documente.titlu, documente.data, documente.ora, conturi.email, documente.continut from documente_destinatari inner join documente on documente.id_document=documente_destinatari.id_document inner join conturi on conturi.id_client=documente_destinatari.id_client where status='F' and documente.expeditor = \"" + mail + "\"";// limit 1";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate)
	{
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			output.append("id:"); output.append(row[0]);
			output.append(" titlu:"); output.append(row[1]);
			output.append(" data:"); output.append(row[2]);
			output.append(" ora:"); output.append(row[3]);
			output.append(" destinatar:"); output.append(row[4]);
			//output.append(" continut:"); output.append(row[5]);
			output.append("$");
		}

		mysql_free_result(res);
	}
	else cout << "Query failed getting received documents: " << mysql_error(conn) << endl;
	//std::cout << id_curr << "*\n";
	return output;
}

std::string DataBase::show_doc_respinse(std::string mail)
{
	std::string client_id = MailToID(mail);
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string output = "";
	string query = "select documente.id_document, documente.titlu, documente.data, documente.ora, conturi.email, documente.continut from documente_destinatari inner join documente on documente.id_document=documente_destinatari.id_document inner join conturi on conturi.id_client=documente_destinatari.id_client where status='R' and documente.expeditor = \"" + mail + "\"";// limit 1";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate)
	{
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			output.append("id:"); output.append(row[0]);
			output.append(" titlu:"); output.append(row[1]);
			output.append(" data:"); output.append(row[2]);
			output.append(" ora:"); output.append(row[3]);
			output.append(" destinatar:"); output.append(row[4]);
			//output.append(" continut:"); output.append(row[5]);
			output.append("$");
		}

		mysql_free_result(res);
	}
	else cout << "Query failed getting received documents: " << mysql_error(conn) << endl;
	//std::cout << id_curr << "*\n";
	return output;
}


std::string DataBase::get_continut( std::string idDoc)
{
	//read_doc(mail, idDoc);
	MYSQL_ROW row;
	MYSQL_RES* res;
	string query = "select documente.continut from documente where documente.id_document = " + idDoc;// limit 1";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		return row[0];

		mysql_free_result(res);
	}
	else cout << "Query failed getting received documents: " << mysql_error(conn) << endl;
	//std::cout << id_curr << "*\n";
	return "";
}

//
//string DataBase::getRolFromID(string id) //done
//{
//	if (!exists_in_DB(id, "id", "personal_mta"))
//	{
//		cout << "id invalid\n";
//	}
//	else
//	{
//		MYSQL_ROW row;
//		MYSQL_RES* res;
//		string query = "SELECT rol FROM Roluri where IDRol = '" + id + "'";
//		const char* q = query.c_str();
//		int qstate = mysql_query(conn, q);
//		if (!qstate)
//		{
//			res = mysql_store_result(conn);
//			row = mysql_fetch_row(res);
//			string rol = row[0];
//			mysql_free_result(res);
//
//			cout << rol << "\n";
//			return rol;
//		}
//		else cout << "Query failed: " << mysql_error(conn) << endl;
//	}
//	return NULL;
//}

//string DataBase::getIDFluxFromID(string id) //aici am gresit -- trebuie sa caut in rol_flux, nu flux_clienti
//{
//
//	MYSQL_ROW row;
//	MYSQL_RES* res;
//	string query = "SELECT IDFlux FROM flux_clienti where IDClient = " + id;
//	const char* q = query.c_str();
//	int qstate = mysql_query(conn, q);
//	if (!qstate)
//	{
//		res = mysql_store_result(conn);
//		row = mysql_fetch_row(res);
//		string idflux = row[0];
//		mysql_free_result(res);
//
//		//cout << idflux << "\n";
//		return idflux;
//	}
//	else cout << "Query failed: " << mysql_error(conn) << endl;
//	return NULL;
//}
//
//void DataBase::createFluxList() //done
//{
//	for (int i = 1; i <= NumberOfRows("flux"); i++)
//	{
//		Flux f(i, conn, qstate); //si cand o fi in server, fac pushback la asta si gata lista de fluxuri
//	}
//}