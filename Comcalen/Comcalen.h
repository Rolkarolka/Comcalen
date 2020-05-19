#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Comcalen.h"
#include "EmployerWelcome.h"
#include "EmployeeWelcome.h"
#include "CompanyDatabase.h"
#include "CrewMember.h"
#include <iostream>
#include <string>


class Comcalen : public QMainWindow
{
	Q_OBJECT

private:
	CompanyDatabase* database = nullptr;

public:
	Comcalen(QWidget *parent = Q_NULLPTR);
	Comcalen(CompanyDatabase* cdatabase, QWidget* parent = Q_NULLPTR);

private:
	Ui::ComcalenClass ui;
	EmployerWelcome *employerwelcome;
	EmployeeWelcome* employeewelcome;
	int part_ID(string ID);
	Employee* find_employee(Company* company, string ID, int second_part); //! return user object
	Employer* find_employer(Company* company, string ID, int second_part); //! return user object
	Company* find_company_by_ID(string ID);	//! return company from which user is
	

private slots:
	void login_pressed();
	void signup_pressed();

};
