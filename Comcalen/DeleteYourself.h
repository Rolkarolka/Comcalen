#pragma once

#include <QDialog>
#include "ui_DeleteYourself.h"
#include "CompanyDatabase.h"

class DeleteYourself : public QDialog
{
	/**
	* @class DeleteYourself inheriting from QDialog, evocated while acctual user want to delete company or himself
	*/
	Q_OBJECT

public:
	DeleteYourself(int managment_num, QDialog *parent = Q_NULLPTR);
	~DeleteYourself();
	bool get_delete_company();
	bool get_delete_employer();
private:
	Ui::DeleteYourself ui;
	bool delete_employer = false;
	bool delete_company = false;
	int managment_num;

private slots:
	void clicked_totally_yes();
	void clicked_yes();
};