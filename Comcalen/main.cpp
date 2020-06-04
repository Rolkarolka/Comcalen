#include <QtWidgets/QApplication>
#include <iostream>
#include "Comcalen.h"
#include "CompanyDatabase.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


using namespace std;

int main(int argc, char *argv[])
{
	CompanyDatabase database("database.txt");
	QApplication a(argc, argv);
	Comcalen w(&database);
	w.show();
	a.exec();
	bool company_exist = w.get_if_company_exist();
	if (company_exist == false)
	{
		string ID = w.get_company_ID();
		database.delete_company(ID);
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
