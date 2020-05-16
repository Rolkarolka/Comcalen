#pragma once
#include "CrewMember.h"
//#include "Company.h"
#include <string>
#include <iostream>


class Company;

class Employer : public CrewMember
{
	/**
	* @class Employer inheriting from CrewMember
	* Contains methods that allow employer to add and remove employee, see news and callendars etc.
	* Methods starting with the word "get" allow to retrive the attribute value
	* Methods starting with the word "set" allow to set the attribute value
	*/

	
	Company* company = nullptr;
public:
	void add_employee(); // user enters employee atributes and then calls function add_employee in class Company
	void remove_employee(); // user enters employee's ID and then calls  function  delete_employee in class Company
	void show_calendar(); 
	void show_news(); // prints content from vector news company
	void set_shift_hours();
	void change_salary(); // employer enters employee's ID and new salary then calls for function set_salary in class Employee
	void change_hours_limit();
	void present() override; // prints information about employer

	Employer(string ename, string esurname, string id, string ecompany, Company* compan);
	Employer();
	Employer(const Employer& empl);
	~Employer() override;

	Employer& operator =(const Employer&);
	friend fstream& operator <<(fstream& file, Employer& employer); //! saves attributes (name, surname, ID, company) to fstream
	friend Employer& operator >>(istringstream& tokenStream, Employer& employer); //! sets attributes (name, surname, ID, company) from file

};
