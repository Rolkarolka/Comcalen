#pragma once
#include "CrewMember.h"
#include <vector>
#include <string>
#include <iostream>
#include "Employer.h"

using namespace std;

class Company;
class Employee : public CrewMember
{
	/**
	* @class Employee inheriting from CrewMember
	* Contains methods that employee to reserve days in which he want to work next mnth, see callendar and news etc.
	* Methods starting with the word "get" allow to retrive the attribute value
	* Methods starting with the word "set" allow to set the attribute value
	*/
	double salary = 0; 
	int hours_limit = 0; /// number of hours that employee can reserve in next month
public:
	bool shift_taken(string date);
	vector <string> reserved_hours;
	Company* company;
	double get_salary();
	void set_company(Company* employee_company);
	int get_hours_limit();
	vector <string> get_reserved_hours();
	void set_reserved_hours(string date); // employee eneters shifts in which he want to work next week, they are added to callendar and his vector of reserved hours
	void show_calendar();
	void show_news(); // prints news
	void present() override; // pronts informations about employee

	Employee(string ename, string esurname, string id, string ecompany, double esalary, int ehlimit, Company* compan);
	Employee();
	~Employee() override;
	Employee(const Employee& empl);
	void set_salary(int esalary);
	void set_hours_limit(int ehlimit);

	Employee& operator =(const Employee&);
	friend fstream& operator <<(fstream& file, Employee& employee); //! saves attributes (salary, hours limit, reserved hours) to fstream
	friend Employee& operator >>(istringstream& tokenStream, Employee& employee); //! sets attributes (salary, hours limit, reserved hours) from file
	
	friend void Employer::change_salary();
	friend void Employer::change_hours_limit();



};