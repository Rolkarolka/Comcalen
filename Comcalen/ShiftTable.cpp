#include "ShiftTable.h"
#include <QMessageBox>

ShiftTable::ShiftTable(Employee* em,  QDialog *parent)
	: QDialog(parent)
{
	employee = em;
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
	if (employee->shift_taken(ui.calendar_employee->selectedDate()))
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
	QString date = ui.calendar_employee->selectedDate().toString("dd.MM.yyyy");
	if (employee->shift_taken(ui.calendar_employee->selectedDate()))
	{
		QMessageBox::warning(this, "Shift", "This shift is taken!");
	}
	else
	{
		employee->set_reserved_hours(ui.calendar_employee->selectedDate());
		ui.label_taken->setText("Saved!");
	}

}