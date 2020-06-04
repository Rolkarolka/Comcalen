#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <QDebug>

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
	string ID = ""; /// unique ID given by company 
	string company = "";

public:

	void set_ID(string id);
	void set_company(string ecompany);
	void set_name(string ename);
	void set_surname(string esurname);
	string get_name();
	string get_surname();
	string get_ID();
	string get_company();
	virtual void present() = 0; //! shows string representation of obcject

	CrewMember(string ename, string esurname, string id, string ecompany);
	CrewMember();
	virtual ~CrewMember();
	CrewMember(const CrewMember& crewM);

	CrewMember& operator =(const CrewMember&);
	friend fstream& operator <<(fstream& file, CrewMember& crewM); //! saves attributes (name, surname, ID, company) to fstream
	friend CrewMember& operator >>(istringstream& tokenStream, CrewMember& crewM); //! sets attributes (name, surname, ID, company) from file

};