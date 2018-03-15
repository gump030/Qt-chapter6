#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFont font("Ώ¬Με", 15);
	a.setFont(font);
	MainWindow w;
	w.show();
	return a.exec();
}
