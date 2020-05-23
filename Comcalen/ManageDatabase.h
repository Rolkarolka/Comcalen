#pragma once

#include <QDialog>
#include "ui_ManageDatabase.h"
#include "Company.h"

class ManageDatabase : public QDialog
{
	Q_OBJECT

public:
	ManageDatabase(Company* company, QDialog *parent = Q_NULLPTR);
	~ManageDatabase();

private:
	Ui::ManageDatabase ui;
	Company* company;

private slots:
	void add_employee_pressed();
	void del_employee_pressed();
	void add_employer_pressed();
	void del_employer_pressed();
};
