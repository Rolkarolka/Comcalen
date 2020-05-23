#include "ManageShift.h"

ManageShift::ManageShift(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.return_mw, SIGNAL(released()), this, SLOT(reject()));
}

ManageShift::~ManageShift()
{
}
