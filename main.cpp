#include <iostream>
#include "CompanyDatabase.h"


int main()
{
	CompanyDatabase tdatabase("database.txt");
	string ID = tdatabase.add_company("Cookie");
	//string ID_cookie = tdatabase.get_ID_having_name_company("Cookie");
	Company* company = tdatabase.get_company_with_ID(ID);
	string ID_1 = company->add_employee("Karolina", "Romanowska", 1, 1);
	company->add_employer("Marianna", "Gromadzka");
	company->add_news("Zrob ladne ciasteczko");
	cout << "Employers: " << company->get_number_of_managment() << endl;
	company->delete_employer(company->get_ID_having_name_and_surname("Marianna", "Gromadzka"));
	cout << "Employers: " << company->get_number_of_managment() << endl;
	//company->delete_employee(ID_1);
	//cout << "Employees: " << company->get_number_of_staff() << endl;
	tdatabase.save_file();
	CompanyDatabase tclass("database.txt");

	tclass.open_file();
	cout << tclass.get_size_of_database();
	tdatabase.save_file();
	return 0;
}