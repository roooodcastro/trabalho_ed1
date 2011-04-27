#include "interface.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Interface window;
	window.show();
	return app.exec();
}
