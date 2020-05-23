#include "AddCompany.h"
#include <QMessageBox>

AddCompany::AddCompany(CompanyDatabase* company_database, QDialog *parent)
	: QDialog(parent)
{
	cdatabase= company_database;
	ui.setupUi(this);
	connect(ui.add_employee_button, SIGNAL(released()), this, SLOT(add_employee_pressed()));
	connect(ui.add_employee, SIGNAL(released()), this, SLOT(add_employee_to_company()));
	connect(ui.create_company, SIGNAL(released()), this, SLOT(create_company_pressed()));
	connect(ui.return_2, SIGNAL(released()), this, SLOT(return_to_creating()));
	connect(ui.return_main_w, SIGNAL(released()), this, SLOT(reject()));
	ui.adding_employee->setVisible(false);
}

AddCompany::~AddCompany()
{
}



void AddCompany::create_company_pressed()
{
	set_lines();
	if (company_name != "" && employer_name != "" && employer_surname != "")
	{
		new_company = new Company();
		new_company->set_company_name(company_name);
		new_company->add_employer(employer_name, employer_surname);
		ui.add_company_box->setVisible(false);
		accept();
		cdatabase->add_company(*new_company);
	}
	else
		QMessageBox::warning(this, "Warning!", "You need to enter all information.");
}


void AddCompany::return_to_creating()
{
	ui.add_company_box->setVisible(true);
	ui.adding_employee->setVisible(false);
}

void AddCompany::add_employee_pressed()
{
	set_lines();
	if (company_name != "" && employer_name != "" && employer_surname != "")
	{
		if (new_company == nullptr)
		{
			employer = new Employer();
			employer->set_name(employer_name);
			employer->set_surname(employer_surname);
			new_company = new Company(company_name);
			new_company->add_employer(*employer);
		}
		else
		{
			if (new_company->get_company_name() != company_name)
				new_company->set_company_name(company_name);

		}
		ui.add_company_box->setVisible(false);
		ui.adding_employee->setVisible(true);
	}
	else
		QMessageBox::warning(this, "Warning!", "You need to enter all information.");
}

void AddCompany::add_employee_to_company()
{
	bool ok_1, ok_2;
	QString edit_line_1 = ui.employee_hl->text();
	auto  line_1 = edit_line_1.toInt(&ok_1);
	QString edit_line_4 = ui.employee_salary->text();
	auto  line_4 = edit_line_4.toDouble(&ok_2);

	QString edit_line_2 = ui.employee_surname->text();
	string  line_2 = edit_line_2.toStdString();
	QString edit_line_3 = ui.employee_name->text();
	string  line_3 = edit_line_3.toStdString();

	if (ok_1 && ok_2)
	{
		new_company->add_employee(line_3, line_2, line_4, line_1, new_company);
		ui.add_company_box->setVisible(true);
		ui.adding_employee->setVisible(false);
		ui.employee_hl->clear();
		ui.employee_salary->clear();
		ui.employee_name->clear();
		ui.employee_surname->clear();
	}
	else
		QMessageBox::warning(this, "Warning!", "You need to enter all information. to add employee");
}



void AddCompany::set_lines()
{
	QString edit_line_1 = ui.cname->text();
	string  line_1 = edit_line_1.toStdString();
	QString edit_line_2 = ui.employer_surname->text();
	string  line_2 = edit_line_2.toStdString();
	QString edit_line_3 = ui.employer_name->text();
	string  line_3 = edit_line_3.toStdString();

	if (line_1 != "")
		company_name = line_1;
	if (line_2 != "")
		employer_surname = line_2;
	if (line_3 != "")
		employer_name = line_3;
}
