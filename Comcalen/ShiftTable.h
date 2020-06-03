#pragma once
#include <QDebug>
#include <QDialog>
#include <QtWidgets/QMainWindow>
#include "ui_ShiftTable.h"
#include <string>
#include "Employee.h"
#include <QDate>
#include <QTextCharFormat>
#include "Company.h"



class ShiftTable : public QDialog
{
    /**
    * @class ShiftTable inheriting from QDialog
    */
    Q_OBJECT



public:
    ShiftTable(Employee* employee, Company* company, QDialog* parent = Q_NULLPTR);
    ~ShiftTable();



private:
    Company* company;
    Employee* employee;
    Ui::ShiftTable ui;
    void paint_calendar(); //! paints callendar green if shift is avaible for employee on given day, red if not



private slots:
    void calendar_clicked(); //! show which shifts are avaible for employee in given day
    void add_shift(int, int); //! calls for function set_reserved_hours from class Employee, and prints information about whether adding shift was succesfull or not
};





	