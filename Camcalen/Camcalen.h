#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Camcalen.h"

class Camcalen : public QMainWindow
{
	Q_OBJECT

public:
	Camcalen(QWidget *parent = Q_NULLPTR);

private:
	Ui::CamcalenClass ui;
};
