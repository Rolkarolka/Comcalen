#include "Employer.h"

void Employer::add_employee()
{
	string id = "";
	cout << "Enter employee's ID: ";
	cin >> id;
}

void Employer::remove_employee()
{
	string id;
	cout << "Enter employee's ID: ";
	cin >> id;
}

void Employer::show_calendar()
{

}

void Employer::show_news()
{

}

void Employer::set_shift_hours()
{

}
void Employer::change_salary()
{
	string id;
	cout << "Enter employee's ID: ";
	cin >> id;

}

void Employer::set_hours_limit()
{
	string id;
	cout << "Enter employee's ID: ";
	cin >> id;
}

void Employer::present()
{
	cout << name << " " << surname << "\nID:" << ID;
}

Employer::Employer(string ename, string esurname, string id, string ecompany)
	: CrewMember(ename, esurname, id, ecompany)
{

}

Employer::Employer()
{

}

Employer::Employer(const Employer& empl)
{
	cout << "Copying employers is not allowed.";
}

Employer::~Employer()
{

}


fstream& operator <<(fstream& file, Employer& employer)
{
	file << reinterpret_cast<CrewMember&>(employer);
	return file;
}

Employer& operator >>(istringstream& tokenStream, Employer& employer)
{
	tokenStream >> reinterpret_cast<CrewMember&>(employer);
	return employer;
}