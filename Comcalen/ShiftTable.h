#pragma once

#include <QDialog>
#include <QtWidgets/QMainWindow>
#include "ui_ShiftTable.h"
#include <string>
#include "Employee.h"

class ShiftTable : public QDialog
{
	Q_OBJECT

public:
	ShiftTable(Employee* employee, QDialog *parent = Q_NULLPTR);
	~ShiftTable();

private:
	Employee* employee;
	Ui::ShiftTable ui;

private slots:
	void calendar_clicked();
	void OK_clicked();
};
