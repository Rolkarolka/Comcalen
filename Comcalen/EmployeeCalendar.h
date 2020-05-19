#pragma once

#include <QWidget>
#include "ui_EmployeeCalendar.h"

class EmployeeCalendar : public QWidget
{
	Q_OBJECT

public:
	EmployeeCalendar(QWidget *parent = Q_NULLPTR);
	~EmployeeCalendar();

private:
	Ui::EmployeeCalendar ui;
};
