#pragma once

#include <QWidget>
#include "ui_EmployeeWelcome.h"

class EmployeeWelcome : public QWidget
{
	Q_OBJECT

public:
	EmployeeWelcome(QWidget *parent = Q_NULLPTR);
	~EmployeeWelcome();

private:
	Ui::EmployeeWelcome ui;
};
