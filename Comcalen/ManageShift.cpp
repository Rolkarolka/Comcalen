#include "ManageShift.h"

ManageShift::ManageShift(Company* com, QDialog *parent)
	: QDialog(parent)
{
	company = com;
	ui.setupUi(this);
	connect(ui.return_mw, SIGNAL(released()), this, SLOT(reject()));
	connect(ui.add_button, SIGNAL(released()), this, SLOT(add_clicked()));
	connect(ui.delete_button, SIGNAL(released()), this, SLOT(delete_clicked()));
}

ManageShift::~ManageShift()
{
}

void ManageShift::add_clicked()
{

}
void ManageShift::delete_clicked()
{

}