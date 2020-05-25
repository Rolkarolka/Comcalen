#pragma once
#include <QDialog>
#include "ui_EmployeeCalendar.h"
#include "Employee.h"
#include <QTextCharFormat>
#include <QtWidgets/QMainWindow>


class EmployeeCalendar : public QDialo
{
	Q_OBJECT


public:
	EmployeeCalendar(Employee* employee, QDialog *parent = Q_NULLPTR);
	~EmployeeCalendar();

private:
	Employee* employee;
	Ui::EmployeeCalendar ui;
	void taken_days();
};
