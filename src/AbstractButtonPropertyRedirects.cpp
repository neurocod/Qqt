//AbstractButtonPropertyRedirects.cpp by Kostya Kozachuck as neurocod - 16.09.2011 1:16:38
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "AbstractButtonPropertyRedirects.h"

void AbstractButtonPropertyRedirects::init(QAbstractButton*d) {
	WidgetPropertyRedirects::init(d);
	text.init(d);
	icon.init(d);
	checked.init(d);
}
void AbstractButtonPropertyRedirects::connectClicks(QObject*obj, const char* slot, Qt::ConnectionType type) {
	QObject::connect(icon.destination(), SIGNAL(clicked(bool)), obj, slot, type);
}
void AbstractButtonPropertyRedirects::set(const QIcon & i) {
	icon = i;
}
/*void AbstractButtonPropertyRedirects::setTooltipByShortcut() {
	tooltip = QObject::tr("Shortcut: %1").arg();
}*/