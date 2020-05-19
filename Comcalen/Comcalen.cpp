#include "Comcalen.h"
#include <QMessageBox>
//#include <QDebug>

Comcalen::Comcalen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.login_button , SIGNAL(released()), this, SLOT(login_pressed()));
}

void Comcalen::login_pressed()
{
	//qDebug() << "test";
	QString ID = ui.ID_line->text();
	if (ID == "test")
	{
		hide();
		employerwelcome = new EmployerWelcome();
		employerwelcome->show();
	}
	else
		QMessageBox::warning(this, "Login", "Incorrect ID");
}