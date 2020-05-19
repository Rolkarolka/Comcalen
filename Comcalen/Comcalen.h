#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Comcalen.h"
#include "EmployerWelcome.h"


class Comcalen : public QMainWindow
{
	Q_OBJECT

public:
	Comcalen(QWidget *parent = Q_NULLPTR);

private:
	Ui::ComcalenClass ui;
	EmployerWelcome *employerwelcome;

private slots:
	void login_pressed();

};
