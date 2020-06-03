#pragma once
#include "Employee.h"
#include <map>
#include <tuple>
#include <iostream>
class Shift
{
	void add_shift(string employee_id);

public:

	QString hours; /// string in the form "hh:mm - hh:mm"

	int no_employees; /// max.number of employees that work on this shift
	vector<string> employees; /// list of employees working on that shift (their ids)

	Shift(int no_employees, QString hours);
	Shift();
	~Shift();

	friend Shift& operator >>(istringstream& tokenStream, Shift& shift);
	friend fstream& operator <<(fstream& file, Shift& shft);

};
