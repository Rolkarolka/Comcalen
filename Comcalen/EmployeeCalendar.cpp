#include "EmployeeCalendar.h"

EmployeeCalendar::EmployeeCalendar(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.return_from_ec, SIGNAL(released()), this, SLOT(reject()));
}

EmployeeCalendar::~EmployeeCalendar()
{
}
