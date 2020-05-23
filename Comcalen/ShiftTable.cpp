#include "ShiftTable.h"

ShiftTable::ShiftTable(Employee* em, QDialog *parent)
	: QDialog(parent)
{
	employee = em;
	em->get_company();
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
	date = ui.calendar_employee->selectedDate();

	ui.label_day->setText(date.toString("dd.MM.yyyy"));
}

void ShiftTable::OK_clicked()
{
	QString dat = date.toString();
	employee->set_reserved_hours(dat.toStdString());
	ui.label_day->setText(ui.calendar_employee->selectedDate().toString("dd.MM.yyyy\nSaved!"));
}