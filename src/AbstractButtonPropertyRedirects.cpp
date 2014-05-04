//AbstractButtonPropertyRedirects.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "AbstractButtonPropertyRedirects.h"

void AbstractButtonPropertyRedirects::init(QAbstractButton*d) {
	WidgetPropertyRedirects::init(d);

	autoExclusive.init(d);
	autoRepeat.init(d);
	autoRepeatDelay.init(d);
	autoRepeatInterval.init(d);
	checkable.init(d);
	checked.init(d);
	down.init(d);
	icon.init(d);
	iconSize.init(d);
	shortcut.init(d);
	text.init(d);
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
void AbstractButtonPropertyRedirects::addShortcutToTooltip() {
	QKeySequence keySeq = shortcut;
	QString key = keySeq.toString();
	if(key.isEmpty())
		return;
	QString str = toolTip;
	if(!str.isEmpty())
		str += '\n';
	str += key;
	toolTip = str;
}