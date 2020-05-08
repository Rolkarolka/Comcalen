#include "CrewMemenber.h"

void CrewMember::set_name(string n)
{
	name = n;
}

void CrewMember::set_surname(string s)
{
	surname = s;
}

void CrewMember::set_ID(string i)
{
	ID = i;
}

string CrewMember::get_name()
{
	return name;
}

string CrewMember::get_surname()
{
	return surname;
}

string CrewMember::get_ID()
{
	return ID;
}

string CrewMember::get_company()
{
	return company;
}

CrewMember::CrewMember(string n, string s, string i, string c)
{
	set_name(n);
	set_surname(s);
	set_ID(i);
	set_company(c);
}

CrewMember::CrewMember()
{

}

CrewMember::~CrewMember()
{
	
}

CrewMember::CrewMember(const CrewMember& crewM)
{
	cout << "Copying crew members is not allowed.";
}

CrewMember& CrewMember::operator =(const CrewMember&)
{
	cout << "Copying crew members is not allowed.";
}

fstream& operator <<(fstream& file, CrewMember& crewM)
{
	file << crewM.name << '\t' << crewM.surname << '\t' << crewM.ID << '\t' << crewM.company;
	return file;
}

CrewMember& operator >>(istringstream& tokenStream, CrewMember& crewM)
{
	string token;
	char delimiter = '\t';
	int num_word = 1;
	while (getline(tokenStream, token, delimiter))
	{

		switch (num_word)
		{
		case 1: crewM.name = token; break;
		case 2: crewM.surname = token; break;
		case 3: crewM.ID = token; break;
		case 4: crewM.company = token; break;
		}
		num_word++;

	}
	return crewM;
}