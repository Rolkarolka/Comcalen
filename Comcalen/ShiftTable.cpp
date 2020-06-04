#include "ShiftTable.h"
#include <QMessageBox>



ShiftTable::ShiftTable(Employee* em, Company* com, QDialog* parent)
    : QDialog(parent)
{
    company = com;
    employee = em;
    company->update_calendar();
    ui.setupUi(this);
    paint_calendar();
    connect(ui.return_menu, SIGNAL(released()), this, SLOT(reject()));
    connect(ui.calendar, SIGNAL(selectionChanged()), this, SLOT(calendar_clicked()));
    connect(ui.avaible_list, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(add_shift(int, int)));

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
    QDate days = QDate::currentDate().addDays(1);
    QTextCharFormat days_qtfc;
    QColor days_c;
    days_c.setRgb(155, 231, 198);
    days_qtfc.setBackground(QBrush(days_c));

    int max_m = days.month() + 2;
    while (days.month() <= max_m)
    {
        if (company->avaible_shifts(days).size() == 0 || employee->is_working_that_day(days))
        {
            days_c.setRgb(172, 62, 83);
            days_qtfc.setBackground(QBrush(days_c));
            ui.calendar->setDateTextFormat(days, days_qtfc);
            days_c.setRgb(155, 231, 198);
            days_qtfc.setBackground(QBrush(days_c));
        }
        else
        {
            ui.calendar->setDateTextFormat(days, days_qtfc);
        }
        days = days.addDays(1);
    }
}





void ShiftTable::calendar_clicked()
{
    if (ui.calendar->selectedDate() > QDate::currentDate() && QDate::currentDate().addDays(1).month() + 2 >= ui.calendar->selectedDate().addDays(1).month()  && !employee->is_working_that_day(ui.calendar->selectedDate()))
    {
        ui.label_saved->setText("");
        vector <QString> shifts = company->avaible_shifts(ui.calendar->selectedDate());
        ui.avaible_list->setRowCount(shifts.size());
        ui.avaible_list->setColumnCount(1);
        for (int row = 0; row < shifts.size(); row++)
        {
            QTableWidgetItem* newItem = new QTableWidgetItem(shifts[row]);
            ui.avaible_list->setItem(row, 0, newItem);
        }
    }
    else
    {
        ui.avaible_list->setRowCount(0);
        ui.avaible_list->setColumnCount(1);
    }
}





void ShiftTable::add_shift(int row, int column)
{
    if (employee->set_reserved_hours(ui.calendar->selectedDate(), ui.avaible_list->currentItem()->text()))
    {
        ui.label_saved->setText("Saved!");
        QDate days = ui.calendar->selectedDate();
        QTextCharFormat days_qtfc;
        QColor days_c;
        days_c.setRgb(172, 62, 83);
        days_qtfc.setBackground(QBrush(days_c));
        ui.calendar->setDateTextFormat(days, days_qtfc);

    }
    else ui.label_saved->setText("This shift is not avaible.");
}
