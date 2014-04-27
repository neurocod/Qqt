//ToolBar.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "ToolBar.h"

ToolBar::ToolBar(QWidget*parent) {
	init(parent);
}
ToolBar::ToolBar(QString title, QWidget*parent) {
	init(parent);
	d->setWindowTitle(title);
}
void ToolBar::init(QWidget*parent) {
	d = new RotatableToolBar(parent);
	WidgetPropertyRedirects::init(d);
	allowedAreas.init(d);
	floatable.init(d);
	//floating.init(d);
	iconSize.init(d);
	movable.init(d);
	orientation.init(d);
	toolButtonStyle.init(d);
}
ToolBar & ToolBar::operator<<(QWidget*w) {
	d->addWidget(w);
	return *this;
}
ToolBar & ToolBar::operator<<(QAction*a) {
	d->addAction(a);
	return *this;
}
ToolBar & ToolBar::operator<<(const QList<QAction*>& li) {
	foreach(auto a, li)
		*this << a;
	return *this;
}