#pragma once

#include <QDialog>
#include "ui_EmployerCalendar.h"

class EmployerCalendar : public QDialog
{
	Q_OBJECT

public:
	EmployerCalendar(QDialog *parent = Q_NULLPTR);
	~EmployerCalendar();

private:
	Ui::EmployerCalendar ui;
};
