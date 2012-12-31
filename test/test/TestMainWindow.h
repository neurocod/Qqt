#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_testmainwindow.h"

class TestMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	TestMainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TestMainWindow();

private:
	Ui::TestMainWindowClass ui;
};

#endif // TESTMAINWINDOW_H
