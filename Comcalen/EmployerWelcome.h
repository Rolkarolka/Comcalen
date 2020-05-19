#pragma once

#include <QWidget>
#include "ui_EmployerWelcome.h"

class EmployerWelcome : public QWidget
{
	Q_OBJECT

public:
	EmployerWelcome(QWidget *parent = Q_NULLPTR);
	~EmployerWelcome();

private:
	Ui::EmployerWelcome ui;
};
