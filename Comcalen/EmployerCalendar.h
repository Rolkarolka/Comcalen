#pragma once

#include <QDialog>
#include "ui_EmployerCalendar.h"
#include <string>
#include "Company.h"


class EmployerCalendar : public QDialog
{
	Q_OBJECT

public:
	EmployerCalendar(Company* company, QDialog *parent = Q_NULLPTR);
	~EmployerCalendar();

private:
	Ui::EmployerCalendar ui;
	Company* company;
private slots:
	void calendar_clicked();
};
