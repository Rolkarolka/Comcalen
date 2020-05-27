#pragma once
#include "Employee.h"
#include <map>
#include <tuple>
#include <iostream>
class Shift
{
	void add_shift(string employee_id);

public:

	QString hours;
	int no_employees;
	vector<string> employees;

	Shift(int no_employees, QString hours);
	Shift();
	~Shift();

	friend Shift& operator >>(istringstream& tokenStream, Shift& shift);
	friend fstream& operator <<(fstream& file, Shift& shft);

};
