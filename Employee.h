#pragma once
#include "CrewMember.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Employee : public CrewMember
{

	double salary = 0;
	int hours_limit = 0;

	void set_salary(int esalary);
	void set_hours_limit(int ehlimit);
public:
	vector <string> reserved_hours;

	double get_salary();
	int get_hours_limit();
	vector <string> get_reserved_hours();
	void set_reserved_hours();
	void show_calendar();
	void show_news();
	void present() override;

	Employee(string ename, string esurname, string id, string ecompany, double esalary, int ehlimit);
	Employee();
	~Employee() override;
	Employee(const Employee& empl);


	Employee& operator =(const Employee&);
	friend fstream& operator <<(fstream& file, Employee& employee); //! saves attributes (salary, hours limit, reserved hours) to fstream
	friend Employee& operator >>(istringstream& tokenStream, Employee& employee); //! sets attributes (salary, hours limit, reserved hours) from file



};