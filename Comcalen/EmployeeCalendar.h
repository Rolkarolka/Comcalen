#pragma once
#include <QDialog>
#include "ui_EmployeeCalendar.h"
#include "Employee.h"
#include <QTextCharFormat>
#include <QDebug>
#include <QtWidgets/QMainWindow>
#include "Shift.h"
#include "Company.h"

class EmployeeCalendar : public QDialog
{
	Q_OBJECT


public:
	EmployeeCalendar(Employee* employee, Company* com, QDialog *parent = Q_NULLPTR);
	~EmployeeCalendar();

private:
	Company* company;
	Employee* employee;
	Ui::EmployeeCalendar ui;
	void taken_days(); //! paints calendar

private slots:
	void show_hours(); //! when calendar is clicked, show hours in which employee has shift
};
