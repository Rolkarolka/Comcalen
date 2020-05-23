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
        string ID;
        const string cline = line;
        istringstream tokenStream(cline);
        if (getline(tokenStream, token, delimiter))
        {
            ID = token;
        }
        Company* companyy = new Company(ID);
        tokenStream >> *companyy;
        string name = companyy->get_company_name();
        database.insert(pair <string, Company*>(ID, companyy));
        database_of_company_ID.push_back(make_tuple(name, ID));
        num_line++;
    } 
    file.close();
}

CompanyDatabase::CompanyDatabase(string name)
{
    set_filename(name);
    open_file();
}
CompanyDatabase::~CompanyDatabase()
{
    database.clear();
}

string CompanyDatabase::add_company(Company& company)
{
    string ID = set_ID();
    company.set_ID(ID);
    database.insert(pair<string, Company*>(ID, &company));
    database_of_company_ID.push_back(make_tuple(company.get_company_name(), ID));
    return ID;
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
        file << itr->second->get_company_ID();
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
    return "";
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
    database_of_company_ID.push_back(make_tuple(name, ID));
    return ID;
}

bool CompanyDatabase::delete_company(string ID)
{
    database.erase(string(ID));
    int found_index = -1;
    for (int i = 0; i < database_of_company_ID.size(); i++)
    {
        if (get<0>(database_of_company_ID[i]) == ID)
            found_index = i;

    }
    if (found_index == -1)
        return false;
    else
    {
        database_of_company_ID.erase(database_of_company_ID.begin() + found_index);
        return true;
    }
}

void CompanyDatabase::set_filename(string name)
{
    filename = name;
}

string CompanyDatabase::get_filename()
{
    return filename;
}

