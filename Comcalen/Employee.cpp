#include "Employee.h"
#include "Company.h"

bool Employee::shift_avaible(QDate date, QString h)
{
	vector <QString> shifts = company->avaible_shifts(date);
	for (int i = 0; i < shifts.size(); i++)
	{
		if (shifts[i] == h) return true;
	}
	return false;
}

void Employee::set_salary(int esalary)
{
	salary = esalary;
}

void Employee::set_hours_limit(int ehlimit)
{
	hours_limit = ehlimit;
}

void Employee::set_reserved_hours(QDate date, QString h)
{
	if (shift_avaible(date, h))
	{
		bool check = true;
		map <QDate, vector<Shift*>>::iterator itr;
		for (itr = company->calendar.begin(); itr != company->calendar.end(); ++itr)
		{
			if (itr->first == date)
			{
				for (int i = 0; i < itr->second.size(); i++)
				{
					if (itr->second[i]->hours == h)
					{
						for (int k = 0; k < itr->second[i]->employees.size(); i++)
						{
							if (itr->second[i]->employees[k] == "Avaible")
							{
								itr->second[i]->employees[k] == ID;
								reserved_hours.insert(pair<QDate, QString>(date, h));
							}
						}
					}
				}
				check = false;
			}
		}
		if (check)
		{
			vector<Shift*> shifts;
			int no_emp;
			QString ho;
			for (int i = 0; i < company->shift_table.size(); i++)
			{
				no_emp = company->shift_table[i]->no_employees;
				ho = company->shift_table[i]->hours;
				Shift* p = new Shift(no_emp, ho);
				if (ho == h)
				{
					p->employees[0] = ID;
					reserved_hours.insert(pair<QDate, QString>(date, h));
				}
				shifts.push_back(p);
			}
			company->calendar.insert(pair<QDate, vector<Shift*>>(date, shifts));

		}
	}
}

double Employee::get_salary()
{
	return salary;
}

int Employee::get_hours_limit()
{
	return hours_limit;
}
map <QDate, QString> Employee::get_reserved_hours()
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
	cout << name << " " << surname << "\nID: " << ID << "\nSalary:" << salary << "\nHours limit: " << hours_limit << endl;
}

Employee::Employee(string ename, string esurname, string id, string ecompany, double esalary, int hlimit, Company* compan)
	: CrewMember(ename, esurname, id, ecompany)
{
	set_salary(esalary);
	set_hours_limit(hlimit);
	company = compan;
#ifdef _DEBUG
	qDebug() << "Employee class created.\n";
#endif
}

Employee::Employee()
{
#ifdef _DEBUG
	qDebug() << "Employee class created.\n";
#endif
}

Employee::~Employee()
{
#ifdef _DEBUG
	qDebug() << "Employee class removed.\n";
#endif

}

Employee::Employee(const Employee& empl)
{
	qDebug() << "Copying employees is not allowed.";
}

fstream& operator <<(fstream& file, Employee& employee)
{																		// jak tu cos zmienisz to daj mi znac
	file << reinterpret_cast<CrewMember&>(employee);
	file << '\t' << employee.salary << '\t' << employee.hours_limit << "\t[\t";
	map <QDate, QString>::iterator itr;

	for (itr = employee.reserved_hours.begin(); itr != employee.reserved_hours.end(); ++itr)
	{
		file << itr->first.toString().toStdString() << "\t";
		file << itr->second.toStdString() << "\t";
	}
	file << "]";
	return file;
}

Employee& operator >>(istringstream& tokenStream, Employee& employee)
{
	tokenStream >> reinterpret_cast<CrewMember&>(employee);
	string token;
	char delimiter = '\t';
	int num_word = 1;
	QDate date;
	bool check = false;
	while (getline(tokenStream, token, delimiter))
	{
		switch (num_word)
		{
		case 1: employee.salary = stod(token); break;
		case 2: employee.hours_limit = stoi(token); break;
		}
		if (num_word >= 4 && token != "]" && !check)
		{
			date = QDate::fromString(QString::fromStdString(token));
			check = true;
			
		}
		else if (num_word >= 4 && token != "]" && check)
		{
			employee.reserved_hours.insert(pair<QDate, QString>(date, QString::fromStdString(token)));
			check = false;
		}

		else if (num_word >= 4 && token == "]")
			return employee;
		num_word++;

	}
}

void Employee::set_company(Company* employee_company)
{
	company = employee_company;
}
