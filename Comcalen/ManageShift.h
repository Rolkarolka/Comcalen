#pragma once

#include <QDialog>
#include "ui_ManageShift.h"

class ManageShift : public QDialog
{
	Q_OBJECT

public:
	ManageShift(QDialog *parent = Q_NULLPTR);
	~ManageShift();

private:
	Ui::ManageShift ui;
};
