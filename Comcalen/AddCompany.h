#pragma once

//#include <QWidget>
#include <QDialog>
#include "ui_AddCompany.h"
#include "CompanyDatabase.h"

class AddCompany : public QDialog
{
	Q_OBJECT

public:
	AddCompany(CompanyDatabase* company_database, QDialog* parent = Q_NULLPTR);
	~AddCompany();

private:
	CompanyDatabase* cdatabase;
	Company* new_company;
	Ui::AddCompany ui;
	string company_name;
	string employer_name;
	string employer_surname;
	void set_lines();

private slots:
	void add_employee_pressed();
	void add_employee_to_company();
	void create_company_pressed();
	void return_to_creating();

};