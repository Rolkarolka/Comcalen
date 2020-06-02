#pragma once

#include <QDialog>
#include "ui_ManageShift.h"
#include "Company.h"
#include "Shift.h"
#include <QTableWidgetItem>
#include <iterator>
#include <QTableWidget>
#include <QDebug>

class ManageShift : public QDialog
{
	Q_OBJECT

public:
	ManageShift(Company* company, QDialog *parent = Q_NULLPTR);
	~ManageShift();

private:
	Ui::ManageShift ui;
	Company* company;
	int no_employees;
	QString beginning;
	QString end;

	void add_set_lines();
	void show_list();

private slots:
	void add_clicked();
	void delete_shift(int, int);

};
