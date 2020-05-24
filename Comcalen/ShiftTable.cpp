#include "ShiftTable.h"
#include <QMessageBox>

ShiftTable::ShiftTable(Employee* em, Company* co, QDialog *parent)
	: QDialog(parent)
{
	employee = em;
	company = co;
	ui.setupUi(this);
	connect(ui.return_menu, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.calendar_employee, SIGNAL(released()), this, SLOT(calendar_clicked()));
	connect(ui.ok_button, SIGNAL(released()), this, SLOT(OK_clicked()));

}

ShiftTable::~ShiftTable()
{
}

void ShiftTable::calendar_clicked()
{
	QString date = ui.calendar_employee->selectedDate().toString("dd.MM.yyyy");
	ui.label_day->setText(date);
	string stdate = date.toStdString();
	if (employee->shift_taken(stdate))
	{
		ui.label_taken->setText("Shift is taken!");
	}
	else
	{
		ui.label_taken->setText("Shift is avaible!");

	}

}

void ShiftTable::OK_clicked()
{
	QString dat = ui.calendar_employee->selectedDate().toString("dd.MM.yyyy");
	string sdate = dat.toStdString();
	if (employee->shift_taken(sdate))
	{
		QMessageBox::warning(this, "Shift", "This shift is taken!");
	}
	else
	{
		employee->set_reserved_hours(sdate);
		ui.label_taken->setText("Saved!");
	}

}