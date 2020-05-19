#include "Comcalen.h"
#include <QMessageBox>
//#include <QDebug>

Comcalen::Comcalen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.login_button , SIGNAL(released()), this, SLOT(login_pressed()));
}

Comcalen::Comcalen(CompanyDatabase* cdatabase, QWidget* parent)
	: QMainWindow(parent)
{
	database = cdatabase;
	ui.setupUi(this);
	connect(ui.login_button, SIGNAL(released()), this, SLOT(login_pressed()));
}

int Comcalen::part_ID(string ID)
{
	for (int i = 0; i < ID.length(); i++)
	{
		if (ID[i] == '\\' || ID[i] == '/')
			return i;
	}
	return -1;
}

Company* Comcalen::find_company_by_ID(string ID)
{
	string company_ID = "";
	int part = part_ID(ID);
	if (part != -1)
		company_ID = ID.substr(0, part);
	else
		company_ID = "";
	Company* company = database->get_company_with_ID(company_ID);
	return company;
}

Employee* Comcalen::find_employee(Company* company, string ID,int second_part)
{
	string CrewMember_ID = ID.substr(second_part, ID.length());
	Employee* employee = company->get_employee(CrewMember_ID);
	return employee;
}

Employer* Comcalen::find_employer(Company* company, string ID, int second_part)
{
	string CrewMember_ID = ID.substr(second_part, ID.length());
	Employer* employer = company->get_employer(CrewMember_ID);
	return employer;
}

void Comcalen::login_pressed()
{
	//qDebug() << "test";
	QString all_ID = ui.ID_line->text();
	string ID = all_ID.toStdString();
	Company* company = find_company_by_ID(ID);
	if (company)
	{
		int part = part_ID(ID);
		char disparity = ID.substr(part, part)[0];
		if (disparity == '\\')
		{
			Employee* employee = find_employee(company, ID, part+2);
			hide();
			employeewelcome = new EmployeeWelcome();
			employeewelcome->show();
		}
		else if (disparity == '//')
		{
			Employer* employer = find_employer(company, ID, part+2);
			hide();
			employerwelcome = new EmployerWelcome();
			employerwelcome->show();
		}
	}
	else
		QMessageBox::warning(this, "Login", "Incorrect ID");
}

void Comcalen::signup_pressed()
{

}