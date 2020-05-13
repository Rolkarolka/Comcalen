#include "Employer.h"
#include "Company.h"

void Employer::add_employee()
{
	string name = "";
	string surname = "";
	double salary = 0;
	int hours_limit = 0;
	cout << "Name: ";
	cin >> name;
	cout << "\nSurname: ";
	cin >> surname;
	cout << "Salary: ";
	do {
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> salary;
		if (cin.fail()) cout << "Wrong value.Try again.";
	} while (cin.fail());
	cout << "Hours limit: ";
	do {
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> hours_limit;
		if (cin.fail()) cout << "Wrong value.Try again.";
	} while (cin.fail());
	string id = company->add_employee(name, surname, salary, hours_limit);
	cout << "New employee's ID is " << id << endl;
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
	cout << name << " " << surname << "\nID:" << ID << endl;
}

Employer::Employer(string ename, string esurname, string id, string ecompany, Company* compan)
	: CrewMember(ename, esurname, id, ecompany)
{
	company = compan;
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
	tokenStream >> reinterpret_cast<CrewMember&>(employer);		// jesli bedziesz to cos zmieniac to daj mi znac
	return employer;
}