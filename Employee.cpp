#include "Employee.h"

void Employee::set_salary(int esalary)
{
	salary = esalary;
}

void Employee::set_hours_limit(int ehlimit)
{
	hours_limit = ehlimit;
}

void Employee::set_reserved_hours()
{

}

double Employee::get_salary()
{
	return salary;
}

int Employee::get_hours_limit()
{
	return hours_limit;
}
vector <string> Employee::get_reserved_hours()
{
	return reserved_hours;
}



void Employee::show_calendar()
{

}

void Employee::show_news()
{

}

void Employee::present()
{
	cout << name << " " << surname << "\nID: " << ID << "\nSalary:" << salary << "\nHours limit: " << hours_limit;
}

Employee::Employee(string ename, string esurname, string id, string ecompany, double esalary, int hlimit)
	: CrewMember(ename, esurname, id, ecompany)
{
	set_salary(esalary);
	set_hours_limit(hlimit);
}

Employee::Employee()
{

}

Employee::~Employee()
{

}

Employee::Employee(const Employee& empl)
{
	cout << "Copying employees is not allowed.";
}

fstream& operator <<(fstream& file, Employee& employee)
{
	file << reinterpret_cast<CrewMember&>(employee);
	file << employee.salary << '\t' << employee.hours_limit << '\t';
	for (int i = 0; i < size(employee.reserved_hours); i++)
	{
		file << employee.reserved_hours[i] << '\t';
	}
	return file;
}

Employee& operator >>(istringstream& tokenStream, Employee& employee)
{
	tokenStream >> reinterpret_cast<CrewMember&>(employee);
	string token;
	char delimiter = '\t';
	int num_word = 1;
	while (getline(tokenStream, token, delimiter))
	{

		switch (num_word)
		{
		case 1: employee.salary = stod(token); break;
		case 2: employee.hours_limit = stoi(token); break;

		}
		if (num_word >= 3)
		{
			employee.reserved_hours.push_back(token);
		}
		num_word++;

	}
	return employee;
}
