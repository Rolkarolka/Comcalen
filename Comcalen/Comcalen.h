#pragma once

#include <QtWidgets/QMainWindow>
#include <QDialog>
#include <QDebug>
#include "ui_Comcalen.h"
#include "EmployeeCalendar.h"
#include "EmployerCalendar.h"
#include "CompanyDatabase.h"
#include "AddCompany.h"
#include "ManageShift.h"
#include "ShowCompany.h"
#include "CrewMember.h"
#include "ManageDatabase.h"
#include "ShiftTable.h"
#include "ShowNews.h"
#include <iostream>
#include <string>


class Comcalen : public QMainWindow
{
	/**
	* @class Comcalen inheriting from QDialog, main of QT program
	*/
	Q_OBJECT

private:
	CompanyDatabase* database = nullptr;

public:
	Comcalen(QWidget *parent = Q_NULLPTR);
	Comcalen(CompanyDatabase* cdatabase, QWidget* parent = Q_NULLPTR);
	~Comcalen();
	bool get_if_company_exist();
	string get_company_ID();

private:
	Ui::ComcalenClass ui;
	CrewMember* crew_member;
	Company* user_company;
	bool company_exist = true;

	int part_ID(string ID);
	Employee* find_employee(Company* company, string ID); //! return user object
	Employer* find_employer(Company* company, string ID); //! return user object
	Company* find_company_by_ID(string ID);	//! return company from which user is
	

private slots:
	void login_pressed();
	void signup_pressed();
	void on_add_company_accepted(); //! change view
	void employee_calendar_pressed();
	void employer_calendar_pressed();
	void employee_add_shift_pressed();
	void show_company_pressed();
	void show_news_pressed();
	void manage_shift_pressed();
	void manage_database_pressed();

};
