//MenuButton.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "MenuButton.h"

MenuButton& MenuButton::operator<<(QAction*act) {
	_menu << act;
	if(_first) {
		_first = false;
		_btn.icon = act->icon();
		_btn.toolTip = act->toolTip();
		QObject::connect(_btn, SIGNAL(clicked(bool)), act, SLOT(trigger()));
	}
	return *this;
}
MenuButton& MenuButton::operator<<(const QList<QAction *> & li) {
	for(auto a: li)
		*this << a;
	return *this;
}