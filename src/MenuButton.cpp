//MenuButton.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "MenuButton.h"

MenuButton& MenuButton::operator<<(QAction*act) {
	m_menu << act;
	if(m_bFirst) {
		m_bFirst = false;
		m_btn.icon = act->icon();
		m_btn.toolTip = act->toolTip();
		QObject::connect(m_btn, SIGNAL(clicked(bool)), act, SLOT(trigger()));
	}
	return *this;
}
MenuButton& MenuButton::operator<<(const QList<QAction *> & li) {
	for(auto a: li)
		*this << a;
	return *this;
}