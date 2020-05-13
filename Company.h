#ifndef company_h
#define company_h
#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include "Employee.h"
#include "Employer.h"
#include <memory>

using namespace std;

class Company
{
private:
	string company_name;
	string company_ID = "000";
	int payday = 10;
	map <string, Employee*> employees;
	map <string, Employer*> employers;
	vector<tuple<string, string>> database_of_ID; // 1) name + surname 2) ID
	vector<string> news;
	int size_shift_table = 0;
	string* shift_table = nullptr;
	void set_name(string name);
	string set_employee_ID();
	string set_employer_ID();
	Company(const Company& company) {};
public:

	Company() {};
	Company(string cname, string cID);
	~Company();

	friend void Employer::add_employee();
	friend void Employer::remove_employee();
	friend void Employer::set_shift_hours();

	void change_employee_attri();  //potrzeba?

	string add_employee(string name,string surname, double salary, int hours_limit);
	bool delete_employee(string ID);
	void set_payday(int day);
	int get_payday();
	string get_company_ID();
	string add_employer(string name, string surnam);			// return ID
	void delete_employer(string ID);
	void add_news(string new_news);
	bool delete_news(string old_news);
	string get_ID_having_name_and_surname(string name, string surname);	// do testow employees

	void set_shift_table();

	int get_number_of_news();
	int get_number_of_managment();
	int get_number_of_staff();
	//string get_ID_having_name(string name);	// do testow employees

	friend fstream& operator <<(fstream& file, Company& company);
	friend Company& operator >>(istringstream& tokenStream, Company& company);

	//void operator +=(Employee* employee);
	//void operator -=(Employee* employee);

	//void operator +=(Employer* employer);
	//void operator -=(Employer* employer);

};
#endif