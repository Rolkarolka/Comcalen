#include "Company.h"
using namespace std;

void Company::set_payday(int day)
{
	payday = day;
}

string Company::get_company_ID()
{
	return company_ID;
}

map <QDate, vector<Shift*>> Company::get_calendar()
{
	return calendar;
}

vector <string> Company::get_shifts_employees(QDate d, QString h)
{
	map <QDate, vector<Shift*>>::iterator itr;
	vector<string> emplo;
	for (itr = calendar.begin(); itr != calendar.end(); ++itr)
	{
		if (d == itr->first)
		{
			for (int i = 0; i < itr->second.size(); i++)
			{
				if (h == itr->second[i]->hours)
				{
					for (int j = 0; j < itr->second[i]->employees.size(); j++)
					{
						if (itr->second[i]->employees[j] != "Avaible")
						{
							emplo.push_back(get_name_surname_id(itr->second[i]->employees[j]));
						}
					}
				}
			}
		}
	}
	return emplo;
}

bool Company::delete_data_in_database_of_ID(string ID)
{
	int index = 0;
	for (const auto& i : database_of_ID)
	{
		if (get<1>(i) == ID)
		{
			database_of_ID.erase(database_of_ID.begin() + index);
			return true;
		}
		index++;
	}
	return false;
}

bool Company::add_data_in_database_of_ID(string ID, string name, string surname)
{
	string check_ID = get_ID_having_name_and_surname(name, surname);
	if (check_ID == "")
	{
		string names = surname + " " + name;
		database_of_ID.push_back({ names, ID });
		return true;
	}
	return false;
}


bool Company::change_data_in_database_of_ID(string ID, string new_name, string new_surname, string name, string surname)
{
	string check_ID = get_ID_having_name_and_surname(name, surname);
	if (check_ID != "")
	{
		delete_data_in_database_of_ID(ID);
		add_data_in_database_of_ID(ID, new_name, new_surname);
		return true;
	}
	return false;
}

Company::Company(string cID) 
{ 
	company_ID = cID;
#ifdef _DEBUG
	qDebug() << "Company class created.\n";
#endif
};

void Company::set_ID(string ID)
{
	company_ID = ID;
}

string Company::get_company_name()
{
	return company_name;
}

void Company::set_company_name(string cname)
{
	company_name = cname;
}

string Company::get_ID_having_name_and_surname(string name, string surname)
{
	string names = surname + " " + name;
	for (const auto& i : database_of_ID)
	{
		if (get<0>(i) == names)
			return get<1>(i);
	}
	return "";
}

string Company::get_name_surname_id(string id)
{
	for (const auto& i : database_of_ID)
	{
		if (get<1>(i) == id)
			return get<0>(i);
	}
	return "";
}


void Company::set_name(string name)
{
	company_name = name;
}

string Company::add_employee(string name, string surname, double salary, int hours_limit, Company* company)
{
	string ID = set_employee_ID();
	string names = surname + " " + name;
	database_of_ID.push_back({ names, ID });
	Employee* employee = new Employee(name, surname, ID, company_name, salary, hours_limit, company);
	employees.insert(pair<string, Employee*>(ID, employee));
	return ID;
}

string Company::set_employee_ID()
{
	string temp_ID;
	do
	{
		int ID_i = rand() % 10000;
		temp_ID = company_ID + "//" + to_string(ID_i);
	} while (employers.count(temp_ID) != 0);

	return temp_ID;
}

int Company::get_number_of_news()
{
	return news.size();
}
int Company::get_number_of_managment()
{
	return employers.size();
}

bool Company::delete_employee(string ID)
{
	int index = 0;
	for (const auto& i : database_of_ID)
	{
		if (get<1>(i) == ID)
		{
			database_of_ID.erase(database_of_ID.begin() + index);
			employees.find(string(ID))->second->~Employee();
			employees.erase(string(ID));
			return true;
		}
		index++;
	}
	return false;
}

Company::Company(string cname, string cID)
{
	company_name = cname;
	company_ID = cID;
#ifdef _DEBUG
	qDebug() << "Company class created.\n";
#endif
}

Company::Company()
{
#ifdef _DEBUG
	qDebug() << "Company class created.\n";
#endif
}

Company::~Company()
{
	map <QDate, vector<Shift*>>::iterator itr3;

	for (itr3 = calendar.begin(); itr3 != calendar.end(); ++itr3)
	{
		for (int i = itr3->second.size() - 1; i >= 0; i--)
		{
			itr3->second[i]->~Shift();
		}
	}

	for (int i = shift_table.size() - 1; i >= 0; i--)
	{
		shift_table[i]->~Shift();
	}
	
	map <string, Employer*>::iterator itr;

	for (itr = employers.begin(); itr != employers.end(); ++itr)
	{
		itr->second->~Employer();
	}

	map <string, Employee*>::iterator itr2;

	for (itr2 = employees.begin(); itr2 != employees.end(); ++itr2)
	{
		itr2->second->~Employee();
	}
	employees.clear();
	employers.clear();
	calendar.clear();
#ifdef _DEBUG
	qDebug() << "Company class removed.\n";
#endif
}

int Company::get_payday()
{
	return payday;
}

string Company::add_employer(string name, string surname)
{
	string ID = set_employer_ID();
	string names = surname + " " + name;
	database_of_ID.push_back({ names, ID });
	Employer* employer = new Employer(name, surname, ID, company_name, this);
	employers.insert(pair<string, Employer*>(ID, employer));
	return ID;
}

bool Company::CrewMember_exist(string ID)
{
	for (const auto& i : database_of_ID)
	{
		if (get<1>(i) == ID)
			return true;
	}
	return false;
}


string Company::add_employer(Employer& employer)
{
	string ID = set_employer_ID();
	string names = employer.get_surname() + " " + employer.get_name();
	employer.set_ID(ID);
	employer.CrewMember::set_company(company_name);
	employer.set_company(this);
	database_of_ID.push_back({ names, ID });
	employers.insert(pair<string, Employer*>(ID, &employer));
	return ID;
}

Employer* Company::get_employer(string ID)
{ 
	if (CrewMember_exist(ID) == true)
	{
		map<string, Employer*>::iterator itr;
		itr = employers.find(ID);
		return itr->second;
	}
	else
		return nullptr;
}

Employee* Company::get_employee(string ID)
{
	if (CrewMember_exist(ID) == true)
		return employees[ID];
	else
		return nullptr;
}


bool Company::delete_employer(string ID)
{
	int index = 0;
	for (const auto& i : database_of_ID)
	{
		if (get<1>(i) == ID)
		{
			database_of_ID.erase(database_of_ID.begin() + index);
			employers.find(string(ID))->second->~Employer();
			employers.erase(string(ID));
			return true;
		}
		index++;
	}
	return false;

}

string Company::get_new_employer_ID()
{
	return set_employer_ID();
}
string Company::get_new_employee_ID()
{
	return set_employee_ID();
}


Company::Company(string cname, string employer_name, string employer_surname)
{
	company_name = cname;
	add_employer(employer_name, employer_surname);
#ifdef _DEBUG
	qDebug() << "Company class created.\n";
#endif
}

bool Company::delete_employer(string name, string surname)
{
	string ID = get_ID_having_name_and_surname(name, surname);
	bool done = delete_employer(ID);
	return done;
}


bool Company::delete_employee(string name, string surname)
{
	string ID = get_ID_having_name_and_surname(name, surname);
	bool done = delete_employee(ID);
	return done;
}


void Company::present_company()
{
	map <string, Employee*>::iterator itr1;
	for (itr1 = employees.begin(); itr1 != employees.end(); ++itr1)
	{
		itr1->second->present();
	}

	map <string, Employer*>::iterator itr2;

	for (itr2 = employers.begin(); itr2 != employers.end(); ++itr2)
	{
		itr2->second->present();
	}
}

vector<tuple<string, string>> Company::get_log_info()
{
	return database_of_ID;
}


string Company::set_employer_ID()
{
	string temp_ID;
	do
	{
		int ID_i = rand() % 10000;
		temp_ID = company_ID + "\\\\" + to_string(ID_i);
	} while (employers.count(temp_ID) != 0);

	return temp_ID;
}

void Company::add_news(string new_news)
{
	news.push_back(new_news);
}

bool Company::delete_news(int index)
{
	if (index < news.size())
	{
		news.erase(news.begin() + index);
		return true;
	}
	return false;
}

void Company::delete_shift(int index)
{
	if (index < shift_table.size())
	{
		delete shift_table[index];
		shift_table.erase(shift_table.begin() + index);

	}
}

vector<QString> Company::avaible_shifts(QDate date)
{
	map <QDate, vector<Shift*>>::iterator itr;
	vector<QString> a_shifts;
	bool check = true;
	for (itr = calendar.begin(); itr != calendar.end(); ++itr)
	{
		if (itr->first == date)
		{
			for (int i = 0; i < itr->second.size(); i++)
			{
				for (int j = 0; j < itr->second[i]->employees.size(); j++)
				{
					if (itr->second[i]->employees[j] == "Avaible")
					{
						a_shifts.push_back(itr->second[i]->hours);
						break;
					}
				}
			}
			check = false;
		}
	}
	if (check)
	{
		for (int i = 0; i < shift_table.size(); i++)
		{
			a_shifts.push_back(shift_table[i]->hours);
		}
	}
	return a_shifts;
}


void Company::update_calendar()
{
	map <QDate, vector<Shift*>>::iterator itr;
	vector <QDate> to_del;
	for (itr = calendar.begin(); itr != calendar.end(); ++itr)
	{
		if (itr->first < QDate::currentDate())
		{
			for (int i = 0; i < itr->second.size(); i++)
			{
				itr->second[i]->~Shift();
				to_del.push_back(itr->first);
			}
		}
	}
	for (int i = 0; i < to_del.size(); i++)
	{
		calendar.erase(to_del[i]);
	}
}

vector<QString> Company::get_hours_employer(QDate date)
{

	vector <QString> shifts;
	bool check = true;
	map <QDate, vector<Shift*>>::iterator itr;
	for (itr = calendar.begin(); itr != calendar.end(); ++itr)
	{
		if (itr->first == date)
		{
			check = false;
			for (int i = 0; i < itr->second.size(); i++)
			{
				shifts.push_back(itr->second[i]->hours);
			}
		}
	}
	if (check)
	{
		for (int i = 0; i < shift_table.size(); i++)
		{
			shifts.push_back(shift_table[i]->hours);
		}
	}
	return shifts;
}

void Company::add_shift(int no_emplo, QString hours)
{
	Shift* day = new Shift(no_emplo, hours);
	shift_table.push_back(day);
	map <QDate, vector<Shift*>>::iterator a;
	for (a = calendar.begin(); a != calendar.end(); ++a)
	{
		a->second.push_back(day);
	}

}



fstream& operator <<(fstream& file, Company& company)
{
	file << "\t" << company.company_name << "\t" << company.payday << "\t";
	map <string, Employee*>::iterator itr1;
	file << company.employees.size() << "\t";
	file << company.employers.size() << "\t";
	file << company.calendar.size() << "\t";
	file << company.shift_table.size() << "\t";
	file << company.news.size() << "\t";

	for (itr1 = company.employees.begin(); itr1 != company.employees.end(); ++itr1)
	{
		file << itr1->first << "\t";
		file << *itr1->second << "\t";
	}

	map <string, Employer*>::iterator itr2;

	for (itr2 = company.employers.begin(); itr2 != company.employers.end(); ++itr2)
	{
		file << itr2->first << "\t";
		file << *itr2->second << "\t";
	}

	map <QDate, vector<Shift*>>::iterator itr3;

	for (itr3 = company.calendar.begin(); itr3 != company.calendar.end(); ++itr3)
	{
		file << itr3->second.size() << "\t" << itr3->first.toString().toStdString() << "\t";
		for (int i = 0; i < itr3->second.size(); i++)
			file << *itr3->second[i] << "\t";
	}

	for (int i = 0; i < company.shift_table.size(); i++)
		file << *company.shift_table[i] << "\t";

	for (int i = 0; i < company.news.size(); i++)
		file << company.news[i] << "\t";
	

	return file;
}

Company& operator >>(istringstream& tokenStream, Company& company)
{
	string token, ID, date;
	bool date_taken = false;
	bool size_shifts = false;
	int size_sh = 0;
	int news_size, employees_size, employers_size, calendar_size, shifts_size;
	int start_news = 8, start_employers = 8, start_shift_table = 8, start_calendar = 8;
	char delimiter = '\t';
	int num_word = 1, counter_shift = 0;
	while (getline(tokenStream, token, delimiter))
	{
		switch (num_word)
		{
		case 1: company.company_name = (token.c_str()); break;
		case 2: company.payday = stoi(token.c_str()); break;
		case 3: employees_size = stoi(token.c_str()); start_employers += employees_size; start_news += employees_size; start_shift_table += employees_size; start_calendar += employees_size;  break;
		case 4: employers_size = stoi(token.c_str()); start_news += employers_size; start_shift_table += employers_size; start_calendar += employers_size; break;
		case 5: calendar_size = stoi(token.c_str()); start_shift_table += calendar_size*3; start_news += calendar_size*3; break;
		case 6: company.size_shift_table = stoi(token.c_str());  start_news += company.size_shift_table; break;
		case 7: news_size = stoi(token.c_str()); break;
		}
		if (num_word > 7 && num_word < start_employers)
		{
			ID = token.c_str();
			Employee* employee = new Employee();
			tokenStream >> *employee;
			employee->set_company(&company);
			string names = employee->get_surname() + " " + employee->get_name();
			company.database_of_ID.push_back({ names, ID });
			company.employees.insert(pair<string, Employee*>(ID, employee));
		}
		if (num_word >= start_employers && num_word < start_calendar)
		{
			ID = token.c_str();
			Employer* employer = new Employer();
			tokenStream >> *employer;
			employer->set_company(&company);
			string names = employer->get_surname() + " " + employer->get_name();
			company.database_of_ID.push_back({ names, ID });
			company.employers.insert(pair<string, Employer*>(ID, employer));
		}

		if (num_word >= start_calendar && num_word < start_shift_table)
		{
			if (!size_shifts)
			{
				size_sh = stoi(token);
				size_shifts = true;
			}
			else if (!date_taken)
			{
				date = token.c_str();
				date_taken = true;
			}
			else
			{
				vector<Shift*> shifts;
				for (int i = 0; i < size_sh; i++)
				{
					Shift* shift = new Shift();
					tokenStream >> *shift;
					shifts.push_back(shift);
				}
				date_taken = false;
				size_shifts = false;
				company.calendar.insert(pair<QDate, vector<Shift*>>(QDate::fromString(QString::fromStdString(date)), shifts));
			}
		}

		if (num_word >= start_shift_table  && num_word < start_news && company.size_shift_table != 0)
		{
			Shift* shift = new Shift();
			tokenStream >> *shift;
			company.shift_table.push_back(shift);
		}
		if (num_word >= start_news && token != ""  && news_size != 0)
		{
			string news = token.c_str();
			if (news != "")
				company.news.push_back(news);
		}
		num_word++;
	}
	return company;

}

int Company::get_number_of_staff()
{
	return employees.size();
}
