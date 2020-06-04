#include "EmployerCalendar.h"

EmployerCalendar::EmployerCalendar(Company* com, QDialog *parent)
	: QDialog(parent)
{
	company = com;
	ui.setupUi(this);
	connect(ui.return_employer_c, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.calendar_employer, SIGNAL(selectionChanged()), this, SLOT(calendar_clicked()));
	connect(ui.hours, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(show_emplo(int, int)));

#ifdef _DEBUG
	qDebug() << "EmployerCalendar class created.\n";
#endif

}

EmployerCalendar::~EmployerCalendar()
{
#ifdef _DEBUG
	qDebug() << "EmployerCalendar class removed.\n";
#endif
}

void EmployerCalendar::calendar_clicked()
{
	ui.employees->setRowCount(0);
	ui.employees->setColumnCount(1);
	
	vector<QString> shifts = company->get_hours_employer(ui.calendar_employer->selectedDate());
	ui.hours->setRowCount(shifts.size());
	ui.hours->setColumnCount(1);
	ui.hours->setHorizontalHeaderLabels(QStringList() << "Shifts:");
	ui.hours->horizontalHeader()->setStretchLastSection(true);

	for (int row = 0; row < shifts.size(); row++)
	{
		QTableWidgetItem* newItem = new QTableWidgetItem(shifts[row]);
		ui.hours->setItem(row, 0, newItem);
	}
}

void EmployerCalendar::show_emplo(int, int)
{
	vector <string> emplo = company->get_shifts_employees(ui.calendar_employer->selectedDate(), ui.hours->currentItem()->text());
	ui.employees->setRowCount(emplo.size());
	ui.employees->setColumnCount(1);
	ui.employees->setHorizontalHeaderLabels(QStringList() << "Employees:");
	ui.employees->horizontalHeader()->setStretchLastSection(true);
	if (emplo.size() > 0)
		for (int row = 0; row < emplo.size(); row++)
		{
			QTableWidgetItem* newItem = new QTableWidgetItem(QString::fromStdString(emplo[row]));
			ui.employees->setItem(row, 0, newItem);
		}	
}
