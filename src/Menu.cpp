//Menu.cpp by Kostya Kozachuck as neurocod - 16.09.2011 2:01:02
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "Menu.h"

Menu::Menu() {
	init(0, 0);
}
Menu::Menu(QMenu*other) {
	init(0, other);
}
Menu::Menu(QWidget*parent) {
	init(parent, 0);
}
Menu::Menu(QString _title, QWidget*parent) {
	init(parent, 0);
	title = _title;
}
void Menu::showUnder(QWidget*w) {
	QPoint pt = w->mapToGlobal(w->rect().bottomLeft());
	icon.destination()->popup(pt);
}
void Menu::init(QWidget*parent, QMenu*m) {
	if(m)
		d = m;
	else
		d = new QMenu(parent);
	WidgetPropertyRedirects::init(d);
	icon.init(d);
	title.init(d);
	tearOffEnabled.init(d);
	separatorsCollapsible.init(d);
}
Menu& Menu::operator<<(QAction*act) {
	d->addAction(act);
	return *this;
}