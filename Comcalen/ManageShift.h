#pragma once

#include <QDialog>
#include "ui_ManageShift.h"
#include "Company.h"
#include <QDebug>

class ManageShift : public QDialog
{
	Q_OBJECT

public:
	ManageShift(Company* company, QDialog *parent = Q_NULLPTR);
	~ManageShift();

private:
	Ui::ManageShift ui;
	Company* company;
private slots:
	void add_clicked();
	void delete_clicked();

};
