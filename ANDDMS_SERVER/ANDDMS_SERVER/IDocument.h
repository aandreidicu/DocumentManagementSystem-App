#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <map>
#include <list>
#include <iostream>
//#include "DataBase.h"
class DataBase;
class IDocument
{
public:
	virtual void add_to_database(DataBase& db) = 0;
	virtual void send(DataBase& db) = 0;
};
