#include "EmployeeCalendar.h"

EmployeeCalendar::EmployeeCalendar(Employee* em, QDialog *parent)
	: QDialog(parent)
{
	employee = em;
	ui.setupUi(this);
	connect(ui.return_from_ec, SIGNAL(released()), this, SLOT(reject()));
	taken_days();
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
	for (int i = 0; i < employee->get_reserved_hours().size(); i++)
	{
		date = employee->get_reserved_hours()[i];
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
}
