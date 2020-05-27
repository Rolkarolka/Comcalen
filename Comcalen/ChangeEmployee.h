#pragma once
#include <QDebug>
#include <QDialog>
#include "ui_ChangeEmployee.h"
#include "Employee.h"
class ChangeEmployee : public QDialog
{
	Q_OBJECT

public:
	ChangeEmployee(Employee* employee, QDialog *parent = Q_NULLPTR);
	~ChangeEmployee();
	Employee* get_employee();

private:
	Ui::ChangeEmployee ui;
	Employee* employee;
private slots:
	void save_button_pressed();
};
