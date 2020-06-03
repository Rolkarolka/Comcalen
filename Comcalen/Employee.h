#pragma once
#include "CrewMember.h"
#include <vector>
#include <string>
#include <iostream>
#include "Employer.h"
#include <QDate>
#include <QDebug>

using namespace std;

class Company;
class Employee : public CrewMember
{
	/**
	* @class Employee inheriting from CrewMember
	* Contains methods that employee to reserve days in which he want to work, methods checking is given shifts are avaible for this employee etc.
	* Methods starting with the word "set" allow to set the attribute value
	*/

	double salary = 0; 
	int hours_limit = 0; /// number of hours that employee can reserve in next month
	

public:
	map <QDate, QString> reserved_hours; /// contains information about date and hours in which employee has shift

	bool shift_avaible(QDate date, QString); //! checks if shift in given day and hours is avaible
	void set_company(Company* employee_company); 
	bool set_reserved_hours(QDate date, QString h); //! employee eneters shifts in which he want to work next week, they are added to callendar and his vector of reserved hours
	bool is_working_that_day(QDate date); //! checks if employee has already a shift in given day
	void update_reserved_h(); //! deletes shifts from reserved_hours if that already happend 
	Company* company;
	double get_salary();
	int get_hours_limit();
	map <QDate, QString> get_reserved_hours();
	void present() override; //! prints informations about employee
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