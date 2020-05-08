#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class CrewMember

{
	/**
	* @class CrewMemeber inherited by Employer and Employee with virtual methods.
	* Methods starting with the word "get" allow to retrive the attribute value
    * Methods starting with the word "set" allow to set the attribute value
	*/

protected:
	string name = "";
	string surname = "";
	string ID = "";
	string company = "";

	void set_name(string n);
	void set_surname(string s);
	void set_ID(string i);
	void set_company(string c);

public:
	string get_name();
	string get_surname();
	string get_ID();
	string get_company();
	virtual void present() = 0; //! shows string representation of obcject

	CrewMember(string n, string s, string i, string c);
	CrewMember();
	virtual ~CrewMember();
	CrewMember(const CrewMember& crewM);

	CrewMember& operator =(const CrewMember&);
	friend fstream& operator <<(fstream& file, CrewMember& crewM); //! saves attributes (name, author) to fstream
	friend CrewMember& operator >>(istringstream& tokenStream, CrewMember& crewM); //! sets attributes (name, author) from file



};