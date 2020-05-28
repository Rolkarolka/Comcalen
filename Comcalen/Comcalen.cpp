#include "Comcalen.h"
#include <QMessageBox>
#include "Employee.h"


Comcalen::Comcalen(CompanyDatabase* cdatabase, QWidget* parent)
	: QMainWindow(parent)
{
	database = cdatabase;
	ui.setupUi(this);
	connect(ui.login_button, SIGNAL(released()), this, SLOT(login_pressed()));
	connect(ui.signin_button, SIGNAL(released()), this, SLOT(signup_pressed()));
	connect(ui.employee_calendar_button, SIGNAL(released()), this, SLOT(employee_calendar_pressed()));
	connect(ui.employer_calendar_button, SIGNAL(released()), this, SLOT(employer_calendar_pressed()));
	connect(ui.employee_new_shift_button, SIGNAL(released()), this, SLOT(employee_add_shift_pressed()));

	connect(ui.show_company, SIGNAL(released()), this, SLOT(show_company_pressed()));

	connect(ui.manage_database, SIGNAL(released()), this, SLOT(manage_database_pressed()));
	connect(ui.manage_shifts, SIGNAL(released()), this, SLOT(manage_shift_pressed()));
	connect(ui.employer_news_button, SIGNAL(released()), this, SLOT(show_news_pressed()));

	ui.employee_menu->setVisible(false);
	ui.employer_menu->setVisible(false);
#ifdef _DEBUG
	qDebug() << "Comcalen class created.\n";
#endif
}

void Comcalen::show_company_pressed()
{
	ShowCompany sc_window(user_company);
	sc_window.setWindowTitle(QString::fromStdString("Comcalen"));
	hide();
	connect(&sc_window, SIGNAL(rejected()), this, SLOT(show()));
	sc_window.exec();
}

void Comcalen::employee_add_shift_pressed()
{
	QString all_ID = ui.ID_line->text();
	string ID = all_ID.toStdString();
	Employee* employee = user_company->get_employee(ID);
	ShiftTable st_window(employee);
	st_window.setWindowTitle(QString::fromStdString("Comcalen"));
	hide();
	connect(&st_window, SIGNAL(rejected()), this, SLOT(show()));
	st_window.exec();
}
void Comcalen::employee_calendar_pressed()
{
	QString all_ID = ui.ID_line->text();
	string ID = all_ID.toStdString();
	Employee* employee = user_company->get_employee(ID);
	EmployeeCalendar ec_window(employee);
	ec_window.setWindowTitle(QString::fromStdString("Comcalen"));
	hide();
	connect(&ec_window, SIGNAL(rejected()), this, SLOT(show()));
	ec_window.exec();
}

void Comcalen::signup_pressed()
{
	AddCompany add_company_window(database);
	add_company_window.setWindowTitle(QString::fromStdString("Comcalen"));
	connect(&add_company_window, SIGNAL(accepted()), this, SLOT(on_add_company_accepted()));
	connect(&add_company_window, SIGNAL(rejected()), this, SLOT(show()));
	hide();
	int accepted = add_company_window.exec();
	if (accepted == 1)
	{
		user_company = add_company_window.get_company();
		crew_member = add_company_window.get_employer();
		database->get_filename();
	}
}

void Comcalen::employer_calendar_pressed()
{
	EmployerCalendar ec_window(user_company);
	ec_window.setWindowTitle(QString::fromStdString("Comcalen"));
	hide();
	connect(&ec_window, SIGNAL(rejected()), this, SLOT(show()));
	ec_window.exec();
}


void Comcalen::show_news_pressed()
{
	ShowNews sn_window(dynamic_cast<Employer*>(crew_member), user_company->get_number_of_news());
	sn_window.setWindowTitle(QString::fromStdString("Comcalen"));
	hide();
	connect(&sn_window, SIGNAL(rejected()), this, SLOT(show()));
	sn_window.exec();
}

void Comcalen::manage_shift_pressed()
{
	QString all_ID = ui.ID_line->text();
	string ID = all_ID.toStdString();
	ManageShift ms_window(user_company);
	ms_window.setWindowTitle(QString::fromStdString("Comcalen"));
	hide();
	connect(&ms_window, SIGNAL(rejected()), this, SLOT(show()));
	ms_window.exec();
}

void Comcalen::manage_database_pressed()
{
	ManageDatabase md_window(user_company);
	md_window.setWindowTitle(QString::fromStdString("Comcalen"));
	hide();
	connect(&md_window, SIGNAL(rejected()), this, SLOT(show()));
	md_window.exec();
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

Employee* Comcalen::find_employee(Company* company, string ID)
{
	return company->get_employee(ID);
}

Employer* Comcalen::find_employer(Company* company, string ID)
{
	return company->get_employer(ID);
}

void Comcalen::login_pressed()
{
	QString all_ID = ui.ID_line->text();
	string ID = all_ID.toStdString();
	user_company = find_company_by_ID(ID);
	if (user_company)
	{
		int part = part_ID(ID);
		string disparity = ID.substr(part, 1);
		if (disparity == "/")
		{
			crew_member = find_employee(user_company, ID);
			if (!crew_member)
				QMessageBox::warning(this, "Login", "Incorrect ID");
			else
			{
				ui.sibox->setVisible(false);
				ui.employee_menu->setVisible(true);
				string hi_text = "Welcome " + crew_member->get_name() + " " + crew_member->get_surname() + "!";
				ui.hi_label->setText(QString::fromStdString(hi_text));
			}
		}
		else if (disparity == "\\")
		{
			crew_member = find_employer(user_company, ID);
			if (!crew_member)
				QMessageBox::warning(this, "Login", "Incorrect ID");
			else
			{
				ui.sibox->setVisible(false);
				ui.employer_menu->setVisible(true);
				string hi_text = "Welcome " + crew_member->get_name() + " " + crew_member->get_surname() + "!";
				ui.hello_label->setText(QString::fromStdString(hi_text));
			}
		}
	}
	else
		QMessageBox::warning(this, "Login", "Incorrect ID");
	
}

void Comcalen::on_add_company_accepted()
{
	show();
	ui.employee_menu->setVisible(false);
	string hi_text = "Welcome " + crew_member->get_name() + " " + crew_member->get_surname() + "!";
	ui.hello_label->setText(QString::fromStdString(hi_text));
	ui.sibox->setVisible(false);
	ui.employer_menu->setVisible(true);
}
Comcalen::~Comcalen()
{
#ifdef _DEBUG
	qDebug() << "Comcalen class removed.\n";
#endif
}


Comcalen::Comcalen(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.login_button, SIGNAL(released()), this, SLOT(login_pressed()));
	connect(ui.signin_button, SIGNAL(released()), this, SLOT(signup_pressed()));
	connect(ui.employee_calendar_button, SIGNAL(released()), this, SLOT(employee_calendar_pressed()));
	connect(ui.employer_calendar_button, SIGNAL(released()), this, SLOT(employer_calendar_pressed()));
	ui.employee_menu->setVisible(false);
	ui.employer_menu->setVisible(false);
#ifdef _DEBUG
	qDebug() << "Comcalen class created.\n";
#endif
}