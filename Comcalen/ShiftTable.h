#pragma once

#include <QDialog>
#include "ui_ShiftTable.h"

class ShiftTable : public QDialog
{
	Q_OBJECT

public:
	ShiftTable(QDialog *parent = Q_NULLPTR);
	~ShiftTable();

private:
	Ui::ShiftTable ui;
};
