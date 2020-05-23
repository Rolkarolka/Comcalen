#ifndef companydatabase_h
#define companydatabase_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <string>
#include "Company.h"

using namespace std;

class CompanyDatabase
{
private:
	string filename;
	map <string, Company*> database;
	vector<tuple<string, string>> database_of_company_ID;  /// 1) name 2) ID
	string set_ID();									   //! generate unique ID of company
public:
	CompanyDatabase(string name);
	~CompanyDatabase();

	void open_file();
	void save_file();

	string add_company(string name);					//! add company to database
	string add_company(Company& company);		
	bool delete_company(string ID);

	Company* get_company_with_ID(string ID);			//! get pointer on wanted company
	string get_ID_having_name_company(string name);		
	Company* get_company_with_name(string name);

	void set_filename(string name);

	int get_size_of_database();
	string get_filename();
};

#endif
