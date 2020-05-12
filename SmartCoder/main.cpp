#include "smartcoder.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SmartCoder w;
	w.show();
	return a.exec();
}
