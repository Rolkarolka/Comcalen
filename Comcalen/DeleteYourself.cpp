#include "DeleteYourself.h"

DeleteYourself::DeleteYourself(int mnum, QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	managment_num = mnum;
	if (mnum == 1)
		ui.totally_yes->setVisible(false);
	connect(ui.yes, SIGNAL(clicked()), this, SLOT(clicked_yes()));
	connect(ui.totally_yes, SIGNAL(clicked()), this, SLOT(clicked_totally_yes()));
	connect(ui.no, SIGNAL(clicked()), this, SLOT(reject()));
	#ifdef _DEBUG
		qDebug() << "DeleteYourself class created.\n";
	#endif
}

void DeleteYourself::clicked_totally_yes()
{
	delete_company = true;
	delete_employer = true;
	reject();
}
void DeleteYourself::clicked_yes()
{
	if (managment_num == 1)
		delete_company = true;
	delete_employer = true;
	reject();
}

DeleteYourself::~DeleteYourself()
{
	#ifdef _DEBUG
		qDebug() << "DeleteYourself class removed.\n";
	#endif
}

bool DeleteYourself::get_delete_company()
{
	return delete_company;
}
bool DeleteYourself::get_delete_employer()
{
	return delete_employer;
}