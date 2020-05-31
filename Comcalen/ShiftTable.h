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
    Q_OBJECT



public:
    ShiftTable(Employee* employee, Company* company, QDialog* parent = Q_NULLPTR);
    ~ShiftTable();



private:
    Company* company;
    Employee* employee;
    Ui::ShiftTable ui;
    void paint_calendar();



private slots:
    void calendar_clicked();
    void OK_clicked();
    void add_shift(int, int);
};





	