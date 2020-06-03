#pragma once

#include <QDialog>
#include "ui_EmployerCalendar.h"
#include <string>
#include "Company.h"
#include <QDebug>


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
	void calendar_clicked(); //! when calecndar is clicked shows shifts that employer can click to see who is working then 
	void show_emplo(int, int); //! show list of employees working on given day and shift
};
