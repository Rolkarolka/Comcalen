#include "EmployerCalendar.h"

EmployerCalendar::EmployerCalendar(Company* com, QDialog *parent)
	: QDialog(parent)
{
	company = com;
	ui.setupUi(this);
	connect(ui.return_employer_c, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.calendar_employer, SIGNAL((selectionChanged())), this, SLOT(calendar_clicked()));
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
	vector <QString> shifts;
	for (int i = 0; i < company->shift_table.size(); i++)
	{
		shifts.push_back(company->shift_table[i]->hours);
	}
	ui.hours->setRowCount(shifts.size());
	ui.hours->setColumnCount(1);


	for (int row = 0; row < shifts.size(); row++)
	{
		QTableWidgetItem* newItem = new QTableWidgetItem(shifts[row].arg(row).arg(0));
		ui.hours->setItem(row, 0, newItem);
	}
}

void EmployerCalendar::show_emplo(int, int)
{
	vector <string> emplo = company->get_shifts_employees(ui.calendar_employer->selectedDate(), ui.hours->currentItem()->text());
	ui.employees->setRowCount(emplo.size());
	ui.employees->setColumnCount(1);
	if (emplo.size() > 0)
		for (int row = 0; row < emplo.size(); row++)
		{
			QTableWidgetItem* newItem = new QTableWidgetItem(QString::fromStdString(emplo[row]).arg(row).arg(0));
			ui.employees->setItem(row, 0, newItem);
		}
	else
	{

	}
}
