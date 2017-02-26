#include "pch.h"
#include "TestMainWindow.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	TestMainWindow w;
	w.show();
	return a.exec();
}