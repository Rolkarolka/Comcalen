#pragma once
#include "Company.h"
#include <QDialog>
#include "ui_ShowCompany.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QPushButton>

class ShowCompany : public QDialog
{
	Q_OBJECT

public:
	ShowCompany(Company* company, QDialog *parent = Q_NULLPTR);
	~ShowCompany();

private:
	Ui::ShowCompany ui;
};
