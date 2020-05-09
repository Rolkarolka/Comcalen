#include "CrewMember.h"

void CrewMember::set_name(string ename)
{
	name = ename;
}

void CrewMember::set_surname(string esurname)
{
	surname = esurname;
}

void CrewMember::set_ID(string id)
{
	ID = id;
}

void CrewMember::set_company(string ecompany)
{
	company = ecompany;
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

CrewMember::CrewMember(string ename, string esurname, string id, string ecompany)
{
	set_name(ename);
	set_surname(esurname);
	set_ID(id);
	set_company(ecompany);
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