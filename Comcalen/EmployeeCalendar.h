#pragma once

#include <QDialog>
#include "ui_EmployeeCalendar.h"

class EmployeeCalendar : public QDialog
{
	Q_OBJECT

public:
	EmployeeCalendar(QDialog *parent = Q_NULLPTR);
	~EmployeeCalendar();

private:
	Ui::EmployeeCalendar ui;
};
