#include "smartcoder.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>
#include <QPropertyAnimation>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);


	QSplashScreen* splash = new QSplashScreen;
	splash->setPixmap(QPixmap(":/icons/Resources/icons/icon11.png"));
	splash->show();
	SmartCoder w;
	QPropertyAnimation* animation = new QPropertyAnimation(&w, "windowOpacity");
	animation->setDuration(500);
	animation->setStartValue(0);
	animation->setEndValue(1);
	animation->start();
	w.show();
	splash->finish(&w);
	delete splash;

	return a.exec();
}
