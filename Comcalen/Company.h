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
	/**
	* @class Company stores informations about basic data.
	* Methods starting with the word "get" allow to retrive the attribute value
	* Methods starting with the word "set" allow to set the attribute value
	*/

private:
	string company_name = "Unknown";
	string company_ID = "000";					    /// unique number of company

	vector<tuple<string, string>> database_of_ID;   /// 1) name + surname 2) ID
	string set_employee_ID();					    /// generate unique ID of employee which start with company ID
	string set_employer_ID();						/// generate unique ID of employer which start with company ID, contains special character

	vector<string> news = {};							/// contain information about changes
	int size_shift_table = 0;						
	string* shift_table = nullptr;					/// table containing the shift system
	
	map <string, Employee*> employees;				/// contains all employees of company
	map <string, Employer*> employers;				/// contains all employers of company
	map <string, string> calendar;					/// contains informations about calendar

	int payday = 10;								/// information about payday, to remind employer about this
	void set_name(string name);
	Company(const Company& company) {};				/// lock operator



public:

	Company(string cID) { company_ID = cID; };
	Company() {};
	Company(string cname, string cID);
	~Company();
	Company(string cname, string employer_name, string employer_surname);
	string get_company_name();
	int get_payday();
	Employer* get_employer(string ID);
	Employee* get_employee(string ID);
	string get_company_ID();
	vector<tuple<string, string>> get_log_info();

	bool CrewMember_exist(string ID);

	void change_employee_attri();					// potrzeba? Chyba niezbyt

	string add_employee(string name,string surname, double salary, int hours_limit, Company* compan);  //! add employees to company and return ID for login
	bool delete_employee(string ID);
	bool delete_employee(string name, string surname);

	string add_employer(Employer& employer);
	string add_employer(string name, string surnam);			//! add employers to company and return ID for login
	bool delete_employer(string ID);
	bool delete_employer(string name, string surname);

	void add_news(string new_news);						//! called if there are changes in the company
	bool delete_news(string old_news);

	void set_ID(string new_ID);
	void set_payday(int day);
	void set_shift_table();
	void set_company_name(string name);

	friend fstream& operator <<(fstream& file, Company& company);
	friend Company& operator >>(istringstream& tokenStream, Company& company);

	friend void Employer::add_employee();
	friend void Employer::remove_employee();
	friend void Employer::set_shift_hours();
	friend string Employer::show_news(int index);
	friend void Employee::set_reserved_hours(string date);


	void present_company();										// for tests
	string get_ID_having_name_and_surname(string name, string surname);
	int get_number_of_news();
	int get_number_of_managment();
	int get_number_of_staff();

	//void operator +=(Employee* employee);
	//void operator -=(Employee* employee);

	//void operator +=(Employer* employer);
	//void operator -=(Employer* employer);

};
#endif