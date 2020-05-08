#pragma once
#include "CrewMember.h"
#include <string>
#include <iostream>

class Employer : public CrewMember
{

public:
	void add_employee();
	void romove_employee();
	void show_calendar();
	void show_news();
	void set_shift_hours();
	void change_salary();
	void set_hours_limit();
	void present() override;

	Employer(string ename, string esurname, string id, string ecompany);
	Employer();
	Employer(const Employer& empl);
	~Employer() override;

	Employer& operator =(const Employer&);
	friend fstream& operator <<(fstream& file, Employer& employer); //! saves attributes (name, surname, ID, company) to fstream
	friend Employer& operator >>(istringstream& tokenStream, Employer& employer); //! sets attributes (name, surname, ID, company) from file

};
