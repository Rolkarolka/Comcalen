#pragma once
#include "CrewMember.h"
#include <string>
#include <QDebug>
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

	
public:
	Company* company = nullptr;
	void add_employee(); //! user enters employee atributes and then calls function add_employee in class Company
	void remove_employee(); //! user enters employee's ID and then calls  function  delete_employee in class Company
	string show_news(int index); //! prints content from vector news company
	void change_salary(); //! employer enters employee's ID and new salary then calls for function set_salary in class Employee
	void change_hours_limit(); //! employer enters employee's ID and new hours and calls for function set_hours_limit in class Employee 
	void present() override; //! prints information about employer
	void set_company(Company* employer_company);
	bool delete_news(int index); //! deletes item with given index from vector news

	Employer(string ename, string esurname, string id, string ecompany, Company* compan);
	Employer();
	Employer(const Employer& empl);
	~Employer() override;

	Employer& operator =(const Employer&);
	friend fstream& operator <<(fstream& file, Employer& employer); //! saves attributes (name, surname, ID, company) to fstream
	friend Employer& operator >>(istringstream& tokenStream, Employer& employer); //! sets attributes (name, surname, ID, company) from file

};
