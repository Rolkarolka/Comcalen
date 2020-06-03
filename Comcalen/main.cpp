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
	return a.exec();
	_CrtDumpMemoryLeaks();
	return 0;
}
