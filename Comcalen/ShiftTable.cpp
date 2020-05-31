#include "ShiftTable.h"
#include <QMessageBox>



ShiftTable::ShiftTable(Employee* em, Company* com, QDialog* parent)
    : QDialog(parent)
{
    company = com;
    employee = em;
    ui.setupUi(this);



    paint_calendar();
    connect(ui.return_menu, SIGNAL(released()), this, SLOT(reject()));
    connect(ui.calendar, SIGNAL(selectionChanged()), this, SLOT(calendar_clicked()));
    connect(ui.ok_button, SIGNAL(released()), this, SLOT(OK_clicked()));
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
    QDate days = QDate::currentDate();
    QTextCharFormat days_qtfc;
    QColor days_c;
    days_c.setRgb(155, 231, 198);
    days_qtfc.setBackground(QBrush(days_c));

    int max_m = days.month() + 2;
    while (days.month() <= max_m)
    {
        if (company->avaible_shifts(days).size() > 0)
        {
            ui.calendar->setDateTextFormat(days, days_qtfc);
        }
        else
        {
            days_c.setRgb(172, 62, 83);
            days_qtfc.setBackground(QBrush(days_c));
            ui.calendar->setDateTextFormat(days, days_qtfc);
            days_c.setRgb(155, 231, 198);
            days_qtfc.setBackground(QBrush(days_c));
        }
        days = days.addDays(1);
    }
}





void ShiftTable::calendar_clicked()
{
    vector <QString> shifts = company->avaible_shifts(ui.calendar->selectedDate());
    ui.avaible_list->setRowCount(shifts.size());
    ui.avaible_list->setColumnCount(1);


    for (int row = 0; row < shifts.size(); row++)
    {
        QTableWidgetItem* newItem = new QTableWidgetItem(shifts[row].arg(row).arg(0));
        ui.avaible_list->setItem(row, 0, newItem);
    }

}



void ShiftTable::OK_clicked()
{
    /*QString date = ui.calendar_shift->selectedDate().toString("dd.MM.yyyy");
    if (employee->shift_taken(ui.calendar_shift->selectedDate()) || ui.calendar_shift->selectedDate() < QDate::currentDate())
    {
        QMessageBox::warning(this, "Shift", "This shift is not avaible!");
    }



    else
    {
        employee->set_reserved_hours(ui.calendar_shift->selectedDate());
        ui.label_taken->setText("Saved!");
    }

    */
}

void ShiftTable::add_shift(int row, int column)
{
    employee->set_reserved_hours(ui.calendar->selectedDate(), ui.avaible_list->currentItem()->text());
}
