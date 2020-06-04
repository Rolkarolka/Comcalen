#include <QDebug>
#ifndef company_h
#define company_h
#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include "Employee.h"
#include "Employer.h"
#include <memory>
#include "Shift.h"
#include "ManageShift.h"
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
	
	map <string, Employee*> employees;				/// contains all employees of company
	map <string, Employer*> employers;				/// contains all employers of company
	map <QDate, vector<Shift*>> calendar;					/// contains informations about calendar

	int payday = 10;								/// information about payday, to remind employer about this
	void set_name(string name);
	Company(const Company& company) {};				/// lock operator



public:
	vector<QString> get_hours_employer(QDate date);
	vector <string> get_shifts_employees(QDate d, QString h);
	vector<Shift*> shift_table;					/// table containing the shift system
	Company(string cID);
	Company();
	Company(string cname, string cID);
	~Company();
	Company(string cname, string employer_name, string employer_surname);

	void add_shift(int no_emplo, QString h);
	string get_company_name();
	int get_payday();
	bool delete_data_in_database_of_ID(string ID);
	bool add_data_in_database_of_ID(string ID, string name, string surname);
	bool change_data_in_database_of_ID(string ID, string new_name, string new_surname, string name, string surname);
	Employer* get_employer(string ID);
	Employee* get_employee(string ID);
	string get_company_ID();
	map<QDate, vector<Shift*>> get_calendar();
	vector<tuple<string, string>> get_log_info();
	bool CrewMember_exist(string ID);
	vector<QString> avaible_shifts(QDate date);


	string get_new_employer_ID();
	string get_new_employee_ID();
	string add_employee(string name,string surname, double salary, int hours_limit, Company* compan);  //! add employees to company and return ID for login
	bool delete_employee(string ID);
	bool delete_employee(string name, string surname);

	string add_employer(Employer& employer);					//! add employees to company and return ID for login
	string add_employer(string name, string surnam);			//! add employers to company and return ID for login
	bool delete_employer(string ID);
	bool delete_employer(string name, string surname);

	void add_news(string new_news);						//! called if there are changes in the company
	bool delete_news(int index);
	void delete_shift(int idex);
	void set_ID(string new_ID);
	void set_payday(int day);
	void set_company_name(string name);
	void update_calendar();

	friend fstream& operator <<(fstream& file, Company& company);
	friend Company& operator >>(istringstream& tokenStream, Company& company);


	friend void Employer::add_employee();
	friend void Employer::remove_employee();
	friend string Employer::show_news(int index);
	friend bool Employer::delete_news(int index);
	friend bool Employee::set_reserved_hours(QDate date, QString hours);
	friend bool Employee::shift_avaible(QDate date, QString hours);
	friend bool Employer::change_employee_name_surname_ID(string name, string surname, string new_name, string new_surname, string ID);



	void present_company();										// for tests
	string get_ID_having_name_and_surname(string name, string surname);	// for tests
	string get_name_surname_id(string id);	// for tests
	int get_number_of_news();		// for tests
	int get_number_of_managment();	// for tests
	int get_number_of_staff();		// for tests


};
#endif