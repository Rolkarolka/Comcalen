#include "ChangeEmployee.h"
#include <QMessageBox>


ChangeEmployee::ChangeEmployee(Employer* new_employer,  Employee* new_employee, QDialog* parent)
	: QDialog(parent)
{
	employee = new_employee;
	employer = new_employer;
	ui.setupUi(this);
	string name = employee->get_name();
	ui.label_name->setText(QString::fromStdString(name));
	string surname = employee->get_surname();
	ui.label_surname->setText(QString::fromStdString(surname));
	string hl =to_string(employee->get_hours_limit());
	ui.label_hl->setText(QString::fromStdString(hl));
	string salary = to_string(employee->get_salary());
	ui.label_salary->setText(QString::fromStdString(salary));
	connect(ui.return_button, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.save_button, SIGNAL(released()), this, SLOT(save_button_pressed()));
#ifdef _DEBUG
	qDebug() << "ChangeEmployee class created.\n";
#endif
}

ChangeEmployee::~ChangeEmployee()
{
#ifdef _DEBUG
	qDebug() << "Change Employee class removed.\n";
#endif

}

Employee* ChangeEmployee::get_employee()
{
	return employee;
}

void ChangeEmployee::save_button_pressed()
{
	bool ok_1, ok_2;
	QString edit_line_1 = ui.change_hl_e->text();
	auto  line_1 = edit_line_1.toInt(&ok_1);
	QString edit_line_4 = ui.change_salary_e->text();
	auto  line_4 = edit_line_4.toDouble(&ok_2);

	QString edit_line_2 = ui.change_surname_e->text();
	string  line_2 = edit_line_2.toStdString();
	QString edit_line_3 = ui.change_name_e->text();
	string  line_3 = edit_line_3.toStdString();

	if (line_3 != "")
	{
		string ID = employee->get_ID();
		employer->change_employee_name_surname_ID(employee->get_name(), employee->get_surname(), line_3, employee->get_surname(), employee->get_ID());
		employee->set_name(line_3);
	}
	if (line_2 != "")
	{
		employer->change_employee_name_surname_ID(employee->get_name(), employee->get_surname(), employee->get_name(), line_2, employee->get_ID());
		employee->set_surname(line_2);
	}
	if (ok_1)
	{
		if (line_1 > 0)
			employee->set_hours_limit(line_1);
		else
		{
			QMessageBox::warning(this, "Warning", "Incorrect value");
			ui.change_hl_e->clear();
			return;
		}
	}
	if (ok_2)
	{
		if (line_4 > 0)
			employee->set_salary(line_4);
		else
		{
			QMessageBox::warning(this, "Warning", "Incorrect value");
			ui.change_salary_e->clear();
			return;
		}
	}
	if (!ok_1 && !ok_2 && line_3 == "" && line_2 == "")
	{
		QMessageBox::warning(this, "Warning", "Cannot save changes");
		return;
	}
	ui.change_name_e->clear();
	ui.change_hl_e->clear();
	ui.change_salary_e->clear();
	ui.change_surname_e->clear();
	accept();
	}
