#ifndef company_h
#define company_h
#include <iostream>
#include <set>
using namespace std;

class Company
{
	string name;
	string payday;
	set <string, Employee> employees;
	void set_name(string name);
public:
	void change_name();

};


#endif