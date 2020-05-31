#include "Shift.h"


Shift::Shift(int no_emp, QString h)
{
	no_employees = no_emp;
	hours = h;
	for (int i = 0; i < no_emp; i++)
	{
		employees.push_back("Avaible");
	}

}

Shift::Shift() 
{
}

Shift::~Shift()
{

}

void Shift::add_shift(string employee_id)
{

}

fstream& operator <<(fstream& file, Shift& shift)
{																		
	file << "\t" << shift.hours.toStdString() << "\t" << shift.no_employees <<"\t";
	file << "[" << "\t";
	for (int i = 0; i < shift.employees.size(); i++)
	{
		file << shift.employees[i] << "\t";
	}
	file << "]";
	return file;
}

Shift& operator >>(istringstream& tokenStream, Shift& shift)
{
	string token;
	char delimiter = '\t';
	int num_word = 1;
	vector <string> temp;
	while (getline(tokenStream, token, delimiter))
	{
		if (token == "")
		{
			continue;
		}
		if (num_word == 1)
		{
			shift.hours = QString::fromStdString(token);
		}
		else if (num_word == 2)
		{
			shift.no_employees = stoi(token);
		}
		else if (num_word > 2)
		{
			if (token == "[")
			{
				num_word++;
				continue;
			}
			else if (token == "]")
			{
				shift.employees = temp;
				return shift;
			}
			else
			{
				temp.push_back(token);
			}
		}
	
		num_word++;
	}
}