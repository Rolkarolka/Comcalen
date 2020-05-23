#include "EmployerCalendar.h"

EmployerCalendar::EmployerCalendar(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.return_employer_c, SIGNAL(released()), this, SLOT(reject()));
}

EmployerCalendar::~EmployerCalendar()
{
}
