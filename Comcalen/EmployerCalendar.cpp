#include "EmployerCalendar.h"
#include <string>

EmployerCalendar::EmployerCalendar(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.calendar_employer, SIGNAL(released()), this, SLOT(show_label()));
}

void EmployerCalendar::show_label()
{
	ui.day_label->setText(ui.calendar_employer->selectedDate().toString("dd.MM.yyyy"));

}

void EmployerCalendar::day_start()
{

}

EmployerCalendar::~EmployerCalendar()
{

}