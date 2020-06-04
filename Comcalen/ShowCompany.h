#pragma once
#include "Company.h"
#include <QDialog>
#include "ui_ShowCompany.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QPushButton>

class ShowCompany : public QDialog
{
	/**
	* @class ShowCompany inheriting from QDialog, which show Company database
	*/
	Q_OBJECT

public:
	ShowCompany(Company* company, QDialog *parent = Q_NULLPTR);
	~ShowCompany();

private:
	Ui::ShowCompany ui;
	Company* company;
	int company_members;

private slots:
	void save_button_pressed();
};
