#include "CompanyDatabase.h"
using namespace std;

void CompanyDatabase::open_file()
{
    fstream file;
    string name;
    string line, token;
    int num_line = 0;
    char delimiter = '\t';

    file.open(filename, ios::in);
    if (file.good() == false)
    {
        file.open(filename, ios::out);
    }

    while (getline(file, line))
    {
        string type;
        const string cline = line;
        istringstream tokenStream(cline);
        Company* companyy = new Company();
        tokenStream >> *companyy;
        string ID = companyy->get_company_ID();
        database.insert(pair <string, Company*> (ID, companyy));
        num_line++;
    } 
    file.close();
}

CompanyDatabase::CompanyDatabase(string name)
{
    set_filename(name);
}
CompanyDatabase::~CompanyDatabase()
{
    database.clear();
}

string CompanyDatabase::set_ID()
{
    string ID;
    do
    {
        int ID_i = rand() % 1000;
        ID = to_string(ID_i);
    } while (database.count(ID) != 0);
    return ID;
}

int CompanyDatabase::get_size_of_database()
{
    return database.size();
}


void CompanyDatabase::save_file()
{
    fstream file;
    file.open(filename, ios::out);
    map <string, Company*>::iterator itr; 
    for (itr = database.begin(); itr != database.end(); ++ itr)
    {
         //v = dynamic_cast<Company*>();
        file << *itr->second << endl;
    }
    file.close();
}

string CompanyDatabase::get_ID_having_name_company(string name)
{
    for (const auto& i : database_of_company_ID)
    {
        if (get<0>(i) == name)
            return get<1>(i);
    }
    return NULL;
}

Company* CompanyDatabase::get_company_with_ID(string ID)
{
    return database[ID];
}

Company* CompanyDatabase::get_company_with_name(string name)
{
    string ID = get_ID_having_name_company(name);
    if (ID != "")
        return database[ID];
    return NULL;
}

string CompanyDatabase::add_company(string name)
{
    string namee, surname;
    cout << "Your name: ";
    cin >> namee;
    cout << "\nYour surname: ";
    cin >> surname;
    string ID = set_ID();
    Company* company = new Company(name, ID);
    company->add_employer(namee, surname);
    database.insert(pair<string, Company*>(ID, company));
    return ID;
}

void CompanyDatabase::delete_company(string ID)
{
    database.erase(string(ID));
}

void CompanyDatabase::set_filename(string name)
{
    filename = name;
}

string CompanyDatabase::get_filename()
{
    return filename;
}

