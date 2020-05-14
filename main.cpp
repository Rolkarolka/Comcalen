#include <iostream>
#include "CompanyDatabase.h"


int main()
{
	string employer_id;
	Employer* employer;
	Employee* employee;
	CompanyDatabase tdatabase("database.txt");
	string ID = tdatabase.add_company("Cookie");
	//string ID_cookie = tdatabase.get_ID_having_name_company("Cookie");
	Company* company = tdatabase.get_company_with_ID(ID);
	string ID_1 = company->add_employee("Karolina", "Romanowska", 1, 1, company);
	cout << ID_1;
	employee = company->get_employee(ID_1);
	employee->set_reserved_hours();
	employer_id = company->add_employer("Marianna", "Gromadzka");
	employer = company->get_employer(employer_id);
	employer->change_hours_limit();
	//employer->add_employee();
	cout << "Employees: " << company->get_number_of_staff() << endl;
	company->add_news("Zrob ladne ciasteczko");
	employer->show_news();
	cout << "Employers: " << company->get_number_of_managment() << endl;
	company->delete_employer(company->get_ID_having_name_and_surname("Marianna", "Gromadzka"));
	cout << "Employers: " << company->get_number_of_managment() << endl;
	company->present_company();
	//company->delete_employee(ID_1);
	//cout << "Employees: " << company->get_number_of_staff() << endl;
	tdatabase.save_file();
	CompanyDatabase tclass("database.txt");
	cout << endl << endl;
	tclass.open_file();
	cout << endl << endl;
	cout << tclass.get_size_of_database();

	cout << endl;

	Company* new_company = tclass.get_company_with_name("Cookie");
	new_company->present_company();
	tdatabase.save_file();
	return 0;
}