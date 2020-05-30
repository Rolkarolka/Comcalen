#include "EmployerCalendar.h"

EmployerCalendar::EmployerCalendar(Company* com, QDialog *parent)
	: QDialog(parent)
{
	company = com;
	ui.setupUi(this);
	connect(ui.return_employer_c, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.calendar_employer, SIGNAL(released()), this, SLOT(calendar_clicked()));
#ifdef _DEBUG
	qDebug() << "EmployeeCalendar class created.\n";
#endif

}

EmployerCalendar::~EmployerCalendar()
{
#ifdef _DEBUG
	qDebug() << "EmployeeCalendar class removed.\n";
#endif
}

void EmployerCalendar::calendar_clicked()
{
	
	QString date = ui.calendar_employer->selectedDate().toString("dd.MM.yyyy");
	ui.day_label->setText(date);
	
	/*string stdate = date.toStdString();
	string employee = company->get_calendar()[ui.calendar_employer->selectedDate()];
	ui.employee_label->setText(QString::fromStdString(employee));*/
}