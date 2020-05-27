#include "ManageShift.h"
#ifdef _WIN32
#include <windows.h>

void sleep(unsigned milliseconds)
{
	Sleep(milliseconds);
}
#else
#include <unistd.h>

void sleep(unsigned milliseconds)
{
	usleep(milliseconds * 1000); // takes microseconds
}
#endif

ManageShift::ManageShift(Company* com, QDialog *parent)
	: QDialog(parent)
{
	company = com;
	ui.setupUi(this);
	connect(ui.return_mw, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.add_button, SIGNAL(released()), this, SLOT(add_clicked()));
	connect(ui.delete_button, SIGNAL(released()), this, SLOT(delete_clicked()));
	ui.existing_shifts->setRowCount(company->shift_table.size());
	ui.existing_shifts->setColumnCount(1);
	for (int row = 0; row < company->shift_table.size(); row++)
	{
		string news = company->shift_table[row]->hours.toStdString() + " - " + std::to_string(company->shift_table[row]->no_employees);
		if (news != "")
		{
			QTableWidgetItem* newItem = new QTableWidgetItem(QString::fromStdString(news).arg(row).arg(0));
			ui.existing_shifts->setItem(row, 0, newItem);
		}
		
	}
	#ifdef _DEBUG
		qDebug() << "ManageShift class created.\n";
	#endif
}

ManageShift::~ManageShift()
{
#ifdef _DEBUG
	qDebug() << "ManageShift class removed.\n";
#endif
}

void ManageShift::add_clicked()
{
	add_set_lines();
	QString hours = beginning + " - " + end;
	Shift* day = new Shift(no_employees, hours);
	company->shift_table.push_back(day);
	ui.saved_label->setText("Saved!");
}
void ManageShift::delete_clicked()
{
	delete_set_lines();
}
void ManageShift::add_set_lines()
{
	QString line_1 = ui.begin_add->text();
	QString line_2 = ui.end_add->text();
	QString edit_line_3 = ui.no_employees->text();
	int line_3 = stoi(edit_line_3.toStdString());


	if (line_1 != "")
		beginning = line_1;
	if (line_2 != "")
		end = line_2;
	if (edit_line_3 != "")
		no_employees = line_3;
}

void ManageShift::delete_set_lines()
{
	QString line_1 = ui.begin_del->text();
	QString line_2 = ui.end_del->text();

	if (line_1 != "")
		beginning = line_1;
	if (line_2 != "")
		end = line_2;

}