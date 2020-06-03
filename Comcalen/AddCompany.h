#pragma once
#include <QDebug>
//#include <QWidget>
#include <QDialog>
#include "ui_AddCompany.h"
#include "CompanyDatabase.h"

class AddCompany : public QDialog
{
	/**
	* @class AddCompany inheriting from QDialog
	*/
	Q_OBJECT

public:
	AddCompany(CompanyDatabase* company_database, QDialog* parent = Q_NULLPTR);
	~AddCompany();
	Employer* get_employer();
	Company* get_company();

private:
	CompanyDatabase* cdatabase;
	Company* new_company;
	string company_ID;
	Employer* employer = nullptr;
	Ui::AddCompany ui;
	string company_name;
	string employer_name;
	string employer_surname;
	void set_lines();

	friend fstream& operator <<(fstream& file, Shift& employee);

private slots:
	void add_employee_pressed();
	void add_employee_to_company();
	void create_company_pressed();
	void return_to_creating();
	void is_reject();
};
