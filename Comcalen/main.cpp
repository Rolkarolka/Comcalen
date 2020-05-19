#include "Comcalen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Comcalen w;
	w.show();
	return a.exec();
}
