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

	void set_salary(int s);
	void set_hours_limit(int h);
public:
	vector <string> reserved_hours;

	double get_salary();
	int get_hours_limit();
	vector <string> get_reserved_hours();
	void set_reserved_hours();
	void show_calendar();
	void show_news();
	void present() override;

	Employee(string n, string s, string i, string c, double sal, int hl);
	Employee();
	~Employee();
	Employee(const Employee& empl);


	Employee& operator =(const Employee&);
	friend fstream& operator <<(fstream& file, Employee& employee); //! saves attributes (salary, hours limit, reserved hours) to fstream
	friend Employee& operator >>(istringstream& tokenStream, Employee& employee); //! sets attributes (salary, hours limit, reserved hours) from file



};