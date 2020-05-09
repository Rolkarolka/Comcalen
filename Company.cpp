#include "Company.h"
using namespace std;

void Company::set_name(string name)
{
	company_name = name;
}

void Company::add_employee(string name,string surname, double salary, int hours_limit)
{
	string ID = set_ID();
	Employee* employee = new Employee(name, surname, ID, company_name, salary, hours_limit);
	employees.insert(pair<string, Employee>(ID, *employee));
}

string Company::set_ID()
{
	string ID = company_ID;
	ID += employees.size();
	ID += employers.size();
	return ID;
}

void Company::delete_employee(string ID)
{
	employees.erase(string(ID));
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

}

void Company::change_name()
{

}

void Company::set_payday()
{

}

int Company::get_payday()
{
	return payday;
}

void Company::add_employer()
{

}

void Company::delete_employer()
{

}

void Company::set_shift_table()
{

}
void Company::set_company_ID(string ID)
{

}
void Company::change_employee_attri()
{

}

void Company::add_news()
{

}

void Company::delete_news()
{

}

void Company::show_news()
{

}

fstream& operator <<(fstream& file, Company& company)
{
	file << company.company_name << "\t" << company.company_ID << "\t" << company.payday << "\t";
	map <string, Employee>::iterator itr1;
	file << company.employees.size() << "\t";
	file << company.employers.size() << "\t";
	file << company.size_shift_table << "\t";
	file << company.news.size() << "\t";

	for (itr1 = company.employees.begin(); itr1 != company.employees.end(); ++itr1)
	{
		file << itr1->first << "\t";
		file << itr1->second << "\t";
	}

	map <string, Employer>::iterator itr2;

	for (itr2 = company.employers.begin(); itr2 != company.employers.end(); ++itr2)
	{
		file << itr2->first << "\t";
		file << itr2->second << "\t";
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
	int num_word = 1, counter_shift = 0;
	while (getline(tokenStream, token, delimiter))
	{
		switch (num_word)
		{
		case 1: company.company_name = (token.c_str()); break;
		case 2: company.company_ID = (token.c_str()); break;
		case 3: company.payday = stoi(token.c_str()); break;
		case 4: employees_size = stoi(token.c_str()) * 2; start_employers += employees_size; start_news += employees_size; start_shift_table += employees_size;  break;
		case 5: employers_size = stoi(token.c_str()) * 2; start_news += employers_size; start_shift_table += employers_size; break;
		case 6: company.size_shift_table = stoi(token.c_str()); company.shift_table = new string[company.size_shift_table]; start_news += company.size_shift_table; break;
		case 7: news_size = stoi(token.c_str()); break;
		}
		if (num_word > 7 && num_word < start_employers)
		{
			if (num_word % 2 == 0)
				ID = token.c_str();
			else
			{
				Employee* employee = new Employee();
				tokenStream >> *employee;
				company.employees.insert(pair<string, Employee>(ID, *employee));
			}

		}
		if (num_word >= start_employers && num_word < start_news)
		{
			if (num_word % 2 == 0)
				ID = token.c_str();
			else
			{
				Employer* employer = new Employer();
				tokenStream >> *employer;
				company.employers.insert(pair<string, Employer>(ID, *employer));
			}
		}
		if (num_word >= start_shift_table && num_word < start_news)
		{
			company.shift_table[counter_shift] = token.c_str();
			counter_shift++;
		}

		if (num_word >= start_news)
			company.news.push_back(token.c_str());

	}
	return company;

}

void Company::operator +=(Employee* employee)
{
	string ID = set_ID();
	employees.insert(pair<string, Employee>(ID, *employee));
}

void Company::operator -=(Employee* employee)
{
	employees.erase(string(employee->get_ID()));
}

void Company::operator +=(Employer* employer)
{
	string ID = set_ID();
	employers.insert(pair<string, Employer>(ID, *employer));
}

void Company::operator -=(Employer* employer)
{
	employers.erase(string(employer->get_ID()));
}
