#pragma once
#include <QDebug>
#include <QDialog>
#include "ui_ChangeEmployee.h"
#include "Employee.h"
#include "Employer.h"
class ChangeEmployee : public QDialog
{
	/**
	* @class ChangeEmployee inheriting from QDialog, change employee atributes
	*/
	Q_OBJECT

public:
	ChangeEmployee(Employer* employer, Employee* employee, QDialog* parent = Q_NULLPTR);
	~ChangeEmployee();
	Employee* get_employee();

private:
	Ui::ChangeEmployee ui;
	Employee* employee;
	Employer* employer;
private slots:
	void save_button_pressed(); //! save changes
};
