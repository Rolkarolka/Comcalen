#include "ShiftTable.h"

ShiftTable::ShiftTable(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.return_menu, SIGNAL(released()), this, SLOT(reject()));

}

ShiftTable::~ShiftTable()
{
}
