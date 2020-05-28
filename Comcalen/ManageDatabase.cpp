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
	connect(ui.del_employee_button, SIGNAL(released()), this, SLOT(del_employee_r_pressed()));
	connect(ui.change_employee_button, SIGNAL(released()), this, SLOT(change_employee_pressed()));
#ifdef _DEBUG
	qDebug() << "ManageDatabase class created.\n";
#endif
}

ManageDatabase::~ManageDatabase()
{
#ifdef _DEBUG
	qDebug() << "ManageDatabase class removed.\n";
#endif
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
		string ID = company->add_employee(line_3, line_2, line_4, line_1, company);
		ui.add_hl_e->clear();
		ui.add_name_e->clear();
		ui.add_surname_e->clear();
		ui.add_salary_e->clear();
		ui.label_7->setText(QString::fromStdString(ID));
	}
	else
		QMessageBox::warning(this, "Warning!", "You need to enter all good information. to add employee");

}


void ManageDatabase::del_employee_r_pressed()
{
	QString edit_line_1 = ui.del_surname_e->text();
	string  line_1 = edit_line_1.toStdString();
	QString edit_line_2 = ui.del_name_e->text();
	string  line_2 = edit_line_2.toStdString();

	company->delete_employee(line_2, line_1);
	company->delete_employer(line_2, line_1);
	ui.del_name_e->clear();
	ui.del_surname_e->clear();
	ui.label_2->setText("Done!");
}

void ManageDatabase::add_employer_pressed()
{
	QString edit_line_1 = ui.add_surname_r->text();
	string  line_1 = edit_line_1.toStdString();
	QString edit_line_2 = ui.add_name_r->text();
	string  line_2 = edit_line_2.toStdString();

	string ID = company->add_employer(line_2, line_1);
	ui.add_name_r->clear();
	ui.add_surname_r->clear();
	ui.label_8->setText(QString::fromStdString(ID));
}

void ManageDatabase::change_employee_pressed()
{

	QString edit_line_1 = ui.change_name_e->text();
	string  name = edit_line_1.toStdString();
	QString edit_line_2 = ui.change_surname_e->text();
	string  surname = edit_line_2.toStdString();
	if (name != "" && surname != "")
	{
		string ID = company->get_ID_having_name_and_surname(name, surname);
		Employee* employee = company->get_employee(ID);
		if (employee)
		{
			ChangeEmployee che_window(company->get_employee(ID));
			connect(&che_window, SIGNAL(rejected()), this, SLOT(show()));
			che_window.exec();
			ui.change_name_e->clear();
			ui.change_surname_e->clear();
			ui.label->setText("Done!");
		}
		else
			QMessageBox::warning(this, "Warning!", "Employee does not exist");
	}
	else
		QMessageBox::warning(this, "Warning!", "You need to enter all good information. to add employee");
}
