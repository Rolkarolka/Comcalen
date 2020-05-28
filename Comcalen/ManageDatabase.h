#pragma once

#include <QDialog>
#include "ui_ManageDatabase.h"
#include "Company.h"
#include "ChangeEmployee.h"
#include <QDebug>

class ManageDatabase : public QDialog
{
	Q_OBJECT

public:
	ManageDatabase(Employer* crew_member, Company* company, QDialog *parent = Q_NULLPTR);
	~ManageDatabase();

private:
	Ui::ManageDatabase ui;
	Employer* employer;
	Company* company;

private slots:
	void add_employee_pressed();
	void del_employee_r_pressed();
	void add_employer_pressed();
	void change_employee_pressed();
};
