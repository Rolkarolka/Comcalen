#ifndef company_h
#define company_h
#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include "Employee.h"
#include "Employer.h"
using namespace std;

class Company
{
private:
	string company_name;
	string company_ID;
	int payday = 10;
	map <string, Employee> employees;
	map <string, Employer> employers;
	vector<string> news;
	int size_shift_table = 0;
	string* shift_table = nullptr;
	void set_name(string name);
	string set_ID();
	void set_company_ID(string ID);
	Company(const Company& company) {};
public:
	Company(string cname, string cID);
	~Company();
	void change_name();
	void add_employee(string name,string surname, double salary, int hours_limit);
	void delete_employee(string ID);
	void set_payday();
	void get_payday();
	void add_employer();
	void delete_employer();
	void set_shift_table();
	void change_employee_attri();
	void add_news();
	void delete_news();
	void show_news();

	friend fstream& operator <<(fstream& file, Company& company);
	friend Company& operator >>(istringstream& tokenStream, Company& company);

	void operator +=(Employee* employee);
	void operator -=(Employee* employee);

	void operator +=(Employer* employer);
	void operator -=(Employer* employer);

};
#endif