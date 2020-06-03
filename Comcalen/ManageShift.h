#pragma once

#include <QDialog>
#include "ui_ManageShift.h"
#include "Company.h"
#include "Shift.h"
#include <QTableWidgetItem>
#include <iterator>
#include <QTableWidget>
#include <QDebug>
#include <QMessageBox>

class ManageShift : public QDialog
{
	/**
	* @class ManageShift inheriting from QDialog, for Employer to manage company shifts
	*/
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

	bool add_set_lines(); //! prepares values entered by the user so that a new shift can be created
	void show_list(); //! shows list of existing shifts

private slots:
	void add_clicked(); //! creates new shift
	void delete_shift(int, int); //! deletes existing shift

};
