#include "EmployeeCalendar.h"

EmployeeCalendar::EmployeeCalendar(Employee* em, Company* com, QDialog *parent)
	: QDialog(parent)
{
	company = com;
	employee = em;
	ui.setupUi(this);
	connect(ui.return_from_ec, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.calendar_employee, SIGNAL(selectionChanged()), this, SLOT(show_hours()));
	taken_days();
#ifdef _DEBUG
	qDebug() << "EmployeeCalendar class created .\n";
#endif
}

void EmployeeCalendar::taken_days()
{
	QTextCharFormat taken_days;
	QColor taken_day_color;
	taken_day_color.setRgb(155, 231, 198);
	taken_days.setBackground(QBrush(taken_day_color));
	QTextCharFormat weekend = taken_days;
	weekend.setForeground((QBrush(Qt::red)));
	QTextCharFormat today = taken_days;
	today.setForeground((QBrush(Qt::green)));

	QDate date;
	map <QDate, QString>::iterator itr;
	for (itr = employee->reserved_hours.begin(); itr != employee->reserved_hours.end(); ++itr)
	{

		date = itr->first;
		int week_day = date.dayOfWeek();
		if (date == QDate::currentDate())
		{
			ui.calendar_employee->setDateTextFormat(date, today);
		}
		else if (week_day == 6 || week_day == 7)
		{
			ui.calendar_employee->setDateTextFormat(date, weekend);
		}
		else
		{
			ui.calendar_employee->setDateTextFormat(date, taken_days);
		}
		
	}
}

EmployeeCalendar::~EmployeeCalendar()
{
#ifdef _DEBUG
	qDebug() << "EmployeeCalendar class removed .\n";
#endif

}

void EmployeeCalendar::show_hours()
{
	map <QDate, QString>::iterator itr;
	bool check = true;
	for (itr = employee->reserved_hours.begin(); itr != employee->reserved_hours.end(); ++itr)
	{

		QDate date = itr->first;
		if (date == ui.calendar_employee->selectedDate())
		{
			ui.label->setText(itr->second);
			check = false;
		}
	}
	if (check)
	{
		ui.label->setText("");
	}
		
}