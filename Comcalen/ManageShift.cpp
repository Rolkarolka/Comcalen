#include "ManageShift.h"

ManageShift::ManageShift(Company* com, QDialog *parent)
	: QDialog(parent)
{
	company = com;
	ui.setupUi(this);
	connect(ui.return_mw, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.add_button, SIGNAL(released()), this, SLOT(add_clicked()));
	connect(ui.existing_shifts, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(delete_shift(int, int)));
	show_list();
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
	if (add_set_lines())
	{
		QString hours = beginning + " - " + end;
		Shift* day = new Shift(no_employees, hours);
		company->shift_table.push_back(day);
		show_list();
	}
}

bool ManageShift::add_set_lines()
{
	QString line_1 = ui.begin_add->text();
	QString line_2 = ui.end_add->text();
	QString edit_line_3 = ui.no_employees->text();
	int line_3;
	bool check = true;
	try
	{
		line_3 = stoi(edit_line_3.toStdString());
	}
	catch (invalid_argument& e)
	{
		QMessageBox::warning(this, "Value", "Wrong value!");
		return false;
	}

	if (line_1 != "")
		beginning = line_1;
	if (line_2 != "")
		end = line_2;
	no_employees = line_3;
	if (no_employees < 1)
	{
		QMessageBox::warning(this, "Value", "Wrong value!");
		return false;
	}
	return true;
}

void ManageShift::delete_shift(int row, int column)
{
	ui.existing_shifts->removeRow(row);

	company->delete_shift(row);
}

void ManageShift::show_list()
{
	ui.existing_shifts->setRowCount(company->shift_table.size());
	ui.existing_shifts->setColumnCount(1);
	ui.existing_shifts->setHorizontalHeaderLabels(QStringList() << "Existing shifts:");
	ui.existing_shifts->horizontalHeader()->setStretchLastSection(true);
	for (int row = 0; row < company->shift_table.size(); row++)
	{
		string news = company->shift_table[row]->hours.toStdString() + " - " + std::to_string(company->shift_table[row]->no_employees);
		if (news != "")
		{
			QTableWidgetItem* newItem = new QTableWidgetItem(QString::fromStdString(news).arg(row).arg(0));
			ui.existing_shifts->setItem(row, 0, newItem);
		}

	}
}