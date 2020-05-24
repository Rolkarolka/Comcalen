#include "EmployerCalendar.h"

EmployerCalendar::EmployerCalendar(Company* com, QDialog *parent)
	: QDialog(parent)
{
	company = com;
	ui.setupUi(this);
	connect(ui.return_employer_c, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.calendar_employer, SIGNAL(released()), this, SLOT(calendar_clicked()));

}

EmployerCalendar::~EmployerCalendar()
{
}

void EmployerCalendar::calendar_clicked()
{
	QString date = ui.calendar_employer->selectedDate().toString("dd.MM.yyyy");
	ui.day_label->setText(date);
	string stdate = date.toStdString();
	string employee = company->get_calendar()[stdate];
	ui.employee_label->setText(QString::fromStdString(employee));
}