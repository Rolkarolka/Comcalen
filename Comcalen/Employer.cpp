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
	string id = company->add_employee(name, surname, salary, hours_limit, company);
	cout << "New employee's ID is " << id << endl;
}

void Employer::remove_employee()
{
	string id;
	cout << "Enter employee's ID: ";
	do {
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> id;
		if (company->get_employee(id) == nullptr) cout << "Invalid ID. Try again.";
	} while (company->get_employee(id) == nullptr);
	company->delete_employee(id);
}
bool Employer::delete_news(int index)
{
	if (index < company->news.size())
	{
		company->delete_news(index);
		return true;
	}
	else
		return false;
}

string Employer::show_news(int index)
{
	if (index < company->news.size())
		return company->news[index];
	else
		return "";
}


void Employer::change_salary()
{
	string id;
	double salary;
	cout << "Enter employee's ID: ";
	do {
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> id;
		if (company->get_employee(id) == nullptr) cout << "Invalid ID. Try again.";
	} while (company->get_employee(id) == nullptr);

	cout << "Enter new salary:";
	do {
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> salary;
		if (cin.fail()) cout << "Wrong value.Try again.";
	} while (cin.fail());
	company->get_employee(id)->set_salary(salary);
}

void Employer::change_hours_limit()
{
	string id;
	int hours;
	cout << "Enter employee's ID: ";
	do {
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> id;
		if (company->get_employee(id) == nullptr) cout << "Invalid ID. Try again." <<  endl;
	} while (company->get_employee(id) == nullptr);
	cout << "Enter new hours limit:";
	do {
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> hours;
		if (cin.fail()) cout << "Wrong value.Try again.";
	} while (cin.fail());
	company->get_employee(id)->set_hours_limit(hours);
}

void Employer::present()
{
	cout << name << " " << surname << "\nID:" << ID << endl;
}

Employer::Employer(string ename, string esurname, string id, string ecompany, Company* compan)
	: CrewMember(ename, esurname, id, ecompany)
{
	company = compan;
#ifdef _DEBUG
	qDebug() << "Employer class created..\n";
#endif
}

Employer::Employer()
{
#ifdef _DEBUG
	qDebug() << "Employer class created.\n";
#endif
}

bool Employer::change_employee_name_surname_ID(string name, string surname, string new_name, string new_surname, string ID)
{
	bool changed = company->change_data_in_database_of_ID(ID, new_name, new_surname, name, surname);
	if (changed == true)
		return true;
	return false;
}

Employer::Employer(const Employer& empl)
{
#ifdef _DEBUG
	qDebug() << "Copying employers is not allowed.";
#endif
}

Employer::~Employer()
{
#ifdef _DEBUG
	 qDebug() << "Employer class removed.\n";
#endif
}


fstream& operator <<(fstream& file, Employer& employer)
{
	file << reinterpret_cast<CrewMember&>(employer);
	return file;
}

void Employer::set_company(Company* employer_company)
{
	company = employer_company;
}

Employer& operator >>(istringstream& tokenStream, Employer& employer)
{
	tokenStream >> reinterpret_cast<CrewMember&>(employer);		// jesli bedziesz to cos zmieniac to daj mi znac
	return employer;
}