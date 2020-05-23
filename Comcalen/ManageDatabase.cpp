#include "ManageDatabase.h"
#include <iostream>
#include <QMessageBox>
using namespace std;
ManageDatabase::ManageDatabase(Company* new_company, QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	company = new_company;
	connect(ui.return_mw, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.add_employee_button, SIGNAL(released()), this, SLOT(add_employee_pressed()));
	connect(ui.add_employer_button, SIGNAL(released()), this, SLOT(add_employer_pressed()));
	connect(ui.del_employee_button, SIGNAL(released()), this, SLOT(del_employee_pressed()));
	connect(ui.del_employer_button, SIGNAL(released()), this, SLOT(del_employer_pressed()));
}

ManageDatabase::~ManageDatabase()
{
}

void ManageDatabase::add_employee_pressed()
{
	bool ok_1, ok_2;
	QString edit_line_1 = ui.add_hl_e->text();
	auto  line_1 = edit_line_1.toInt(&ok_1);
	QString edit_line_4 = ui.add_salary_e->text();
	auto  line_4 = edit_line_4.toDouble(&ok_2);

	QString edit_line_2 = ui.add_surname_e->text();
	string  line_2 = edit_line_2.toStdString();
	QString edit_line_3 = ui.add_name_e->text();
	string  line_3 = edit_line_3.toStdString();

	if (ok_1 && ok_2)
	{
		company->add_employee(line_3, line_2, line_4, line_1, company);
		ui.add_hl_e->clear();
		ui.add_name_e->clear();
		ui.add_surname_e->clear();
		ui.add_salary_e->clear();
	}
	else
		QMessageBox::warning(this, "Warning!", "You need to enter all good information. to add employee");

}


void ManageDatabase::del_employee_pressed()
{
	QString edit_line_1 = ui.del_surname_e->text();
	string  line_1 = edit_line_1.toStdString();
	QString edit_line_2 = ui.del_name_e->text();
	string  line_2 = edit_line_2.toStdString();

	company->delete_employee(line_2, line_1);
	ui.del_name_e->clear();
	ui.del_surname_e->clear();
}

void ManageDatabase::add_employer_pressed()
{
	QString edit_line_1 = ui.add_surname_r->text();
	string  line_1 = edit_line_1.toStdString();
	QString edit_line_2 = ui.add_name_r->text();
	string  line_2 = edit_line_2.toStdString();

	company->add_employer(line_2, line_1);
	ui.add_name_r->clear();
	ui.add_surname_r->clear();
}

void ManageDatabase::del_employer_pressed()
{
	QString edit_line_1 = ui.del_surname_r->text();
	string  line_1 = edit_line_1.toStdString();
	QString edit_line_2 = ui.del_name_r->text();
	string  line_2 = edit_line_2.toStdString();

	company->delete_employer(line_2, line_1);
	ui.del_name_r->clear();
	ui.del_surname_r->clear();
}