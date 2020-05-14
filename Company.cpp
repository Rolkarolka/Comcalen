#include "Company.h"
using namespace std;

void Company::set_payday(int day)
{
	payday = day;
}

string Company::get_company_ID()
{
	return company_ID;
}

void Company::set_shift_table()
{

}
void Company::change_employee_attri()
{

}

string Company::get_company_name()
{
	return company_name;
}

string Company::get_ID_having_name_and_surname(string name, string surname)
{
	string names = surname + " " + name;
	for (const auto& i : database_of_ID)
	{
		if (get<0>(i) == names)
			return get<1>(i);
	}
	return "";
}

void Company::set_name(string name)
{
	company_name = name;
}

string Company::add_employee(string name, string surname, double salary, int hours_limit, Company* company)
{
	string ID = set_employee_ID();
	string names = surname + " " + name;
	database_of_ID.push_back({ names, ID });
	Employee* employee = new Employee(name, surname, ID, company_name, salary, hours_limit, company);
	employees.insert(pair<string, Employee*>(ID, employee));
	return ID;
}

string Company::set_employee_ID()
{
	string ID = company_ID;
	do
	{
		int ID_i = rand() % 1000;
		ID += to_string(ID_i);
	} while (employees.count(ID) != 0);
	return ID;
}

int Company::get_number_of_news()
{
	return news.size();
}
int Company::get_number_of_managment()
{
	return employers.size();
}

bool Company::delete_employee(string ID)
{
	int index = 0;
	for (const auto& i : database_of_ID)
	{
		if (get<1>(i) == ID)
		{
			news.erase(news.begin() + index);
			employees.erase(string(ID));
			return true;
		}
		index++;
	}
	return false;
}

Company::Company(string cname, string cID)
{
	company_name = cname;
	company_ID = cID;
}

Company::~Company()
{
	if (shift_table != nullptr)
		delete[] this->shift_table;
	employees.clear();
	employers.clear();
}

int Company::get_payday()
{
	return payday;
}

string Company::add_employer(string name, string surname)
{
	string ID = set_employer_ID();
	string names = surname + " " + name;
	database_of_ID.push_back({ names, ID });
	Employer* employer = new Employer(name, surname, ID, company_name, this);
	employers.insert(pair<string, Employer*>(ID, employer));
	return ID;
}

Employer* Company::get_employer(string ID)
{ 
	return employers[ID];
}

Employee* Company::get_employee(string ID)
{
	return employees[ID];

}


void Company::delete_employer(string ID)
{
	employers.erase(string(ID));
}

void Company::present_company()
{
	map <string, Employee*>::iterator itr1;
	for (itr1 = employees.begin(); itr1 != employees.end(); ++itr1)
	{
		itr1->second->present();
	}

	map <string, Employer*>::iterator itr2;

	for (itr2 = employers.begin(); itr2 != employers.end(); ++itr2)
	{
		itr2->second->present();
	}
}

string Company::set_employer_ID()
{
	string ID = company_ID;
	do
	{
		int ID_i = rand() % 1000;
		ID += "//";
		ID += to_string(ID_i);
	} while (employers.count(ID) != 0);

	return ID;
}

void Company::add_news(string new_news)
{
	news.push_back(new_news);
}

bool Company::delete_news(string old_news)
{
	int found_index = -1;
	for (int i = 0; i < news.size(); i++)
	{
		if (news[i] == old_news)
			found_index = i;
			
	}
	if (found_index == -1)
		return false;
	else
	{
		news.erase(news.begin() + found_index);
		return true;
	}
}


fstream& operator <<(fstream& file, Company& company)
{
	file << company.company_ID  << "\t" << company.company_name << "\t" << company.payday << "\t";
	map <string, Employee*>::iterator itr1;
	file << company.employees.size() << "\t";
	file << company.employers.size() << "\t";
	file << company.size_shift_table << "\t";
	file << company.news.size() << "\t";

	for (itr1 = company.employees.begin(); itr1 != company.employees.end(); ++itr1)
	{
		file << itr1->first << "\t";
		file << *itr1->second << "\t";
	}

	map <string, Employer*>::iterator itr2;

	for (itr2 = company.employers.begin(); itr2 != company.employers.end(); ++itr2)
	{
		file << itr2->first << "\t";
		file << *itr2->second << "\t";
	}

	for (int i = 0; i < company.size_shift_table; i++)
		file << company.shift_table[i] << '\t';

	for (int i = 0; i < company.news.size(); i++)
		file << company.news[i] << '\t';
	return file;
}

Company& operator >>(istringstream& tokenStream, Company& company)
{
	string token, ID;
	int news_size, employees_size, employers_size;
	int start_news = 7, start_employers = 7, start_shift_table = 7;
	char delimiter = '\t';
	int num_word = 0, counter_shift = 0;
	while (getline(tokenStream, token, delimiter))
	{
		switch (num_word)
		{
		case 0: company.company_ID = (token.c_str()); break;
		case 1: company.company_name = (token.c_str()); break;
		case 2: company.payday = stoi(token.c_str()); break;
		case 3: employees_size = stoi(token.c_str()); start_employers += employees_size; start_news += employees_size; start_shift_table += employees_size;  break;
		case 4: employers_size = stoi(token.c_str()); start_news += employers_size; start_shift_table += employers_size; break;
		case 5: company.size_shift_table = stoi(token.c_str()); company.shift_table = new string[company.size_shift_table]; start_news += company.size_shift_table; break;
		case 6: news_size = stoi(token.c_str()); break;
		}
		if (num_word > 6 && num_word < start_employers)
		{
			ID = token.c_str();
			Employee* employee = new Employee();
			tokenStream >> *employee;
			string names = employee->get_surname() + " " + employee->get_name();
			company.database_of_ID.push_back({ names, ID });
			company.employees.insert(pair<string, Employee*>(ID, employee));
		}
		if (num_word >= start_employers && num_word < start_shift_table)
		{
			ID = token.c_str();
			Employer* employer = new Employer();
			tokenStream >> *employer;
			string names = employer->get_surname() + " " + employer->get_name();
			company.database_of_ID.push_back({ names, ID });
			company.employers.insert(pair<string, Employer*>(ID, employer));
		}
		if (num_word >= start_shift_table && num_word < start_news)
		{
			company.shift_table[counter_shift] = token.c_str();
			counter_shift++;
		}
		if (num_word >= start_news)
			company.news.push_back(token.c_str());
		num_word++;
	}
	return company;

}

//void Company::operator +=(Employee* employee)
//{
//	string ID = set_employee_ID();
//	employees.insert(pair<string, Employee>(ID, *employee));
//}
//
//void Company::operator -=(Employee* employee)
//{
//	employees.erase(string(employee->get_ID()));
//}
//
//void Company::operator +=(Employer* employer)
//{
//	string ID = set_employer_ID();
//	employers.insert(pair<string, Employer>(ID, *employer));
//}
//
//void Company::operator -=(Employer* employer)
//{
//	employers.erase(string(employer->get_ID()));
//}

int Company::get_number_of_staff()
{
	return employees.size();
}
