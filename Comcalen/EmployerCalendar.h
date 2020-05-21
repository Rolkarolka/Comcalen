#pragma once

#include <QWidget>
#include "ui_EmployerCalendar.h"

class EmployerCalendar : public QWidget
{
	Q_OBJECT

public:
	EmployerCalendar(QWidget *parent = Q_NULLPTR);
	~EmployerCalendar();

private:
	Ui::EmployerCalendar ui;

private slots:
	void show_label();
	void day_start();
};
