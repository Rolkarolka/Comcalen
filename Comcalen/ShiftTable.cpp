#include "ShiftTable.h"
#include <QMessageBox>

ShiftTable::ShiftTable(Employee* em,  QDialog *parent)
	: QDialog(parent)
{
	employee = em;
	ui.setupUi(this);

	paint_calendar();
	connect(ui.return_menu, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.calendar_shift, SIGNAL(released()), this, SLOT(calendar_clicked()));
	connect(ui.ok_button, SIGNAL(released()), this, SLOT(OK_clicked()));
#ifdef _DEBUG
	qDebug() << "ShiftTable class created.\n";
#endif

}

ShiftTable::~ShiftTable()
{
#ifdef _DEBUG
	qDebug() << "ShiftTable class removed.\n";
#endif
}

void ShiftTable::paint_calendar()
{
	QDate days = QDate::currentDate();
	QTextCharFormat days_qtfc;
	QColor days_c;
	days_c.setRgb(172, 62, 83);
	days_qtfc.setBackground(QBrush(days_c));

	int max_year = days.year() + 100;
	while (days.year() <= max_year)
	{
		if (employee->shift_taken(days))
		{
			ui.calendar_shift->setDateTextFormat(days, days_qtfc);
		}
		else
		{
			days_c.setRgb(155, 231, 198);
			days_qtfc.setBackground(QBrush(days_c));
			ui.calendar_shift->setDateTextFormat(days, days_qtfc);
			days_c.setRgb(172, 62, 83);
			days_qtfc.setBackground(QBrush(days_c));
		}
		days = days.addDays(1);
	}

}



void ShiftTable::calendar_clicked()
{
	if (employee->shift_taken(ui.calendar_shift->selectedDate()))
	{
		ui.label_taken->setText("Shift is taken!");
	}
	else
	{
		ui.label_taken->setText("Shift is avaible!");
	}
}

void ShiftTable::OK_clicked()
{
	QString date = ui.calendar_shift->selectedDate().toString("dd.MM.yyyy");
	if (employee->shift_taken(ui.calendar_shift->selectedDate()) || ui.calendar_shift->selectedDate() < QDate::currentDate())
	{
		QMessageBox::warning(this, "Shift", "This shift is not avaible!");
	}

	else
	{
		employee->set_reserved_hours(ui.calendar_shift->selectedDate());
		ui.label_taken->setText("Saved!");
	}

}