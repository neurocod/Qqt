//Action.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "Action.h"

void Action::operator=(QAction*a) {
	ASSERT(!d);
	init(a);
}
Action::Action(QAction* act) {
	init(act);
}
Action::Action(QObject* parent) {
	init();
	d->setParent(parent);
}
void Action::init(QAction*_d) {
	if(_d)
		d = _d;
	else
		d = new QAction(0);
	toolTip.init(d);
	autoRepeat.init(d);
	checkable.init(d);
	checked.init(d);
	enabled.init(d);
	iconVisibleInMenu.init(d);
	visible.init(d);
	menuRole.init(d);
	priority.init(d);
	shortcutContext.init(d);
	shortcut.init(d);
	font.init(d);
	icon.init(d);
	iconText.init(d);
	statusTip.init(d);
	text.init(d);
	whatsThis.init(d);
	separator.init(d);
}
void Action::connectClicks(QObject*obj, const char* slot, Qt::ConnectionType conn) {
	QObject::connect(d, SIGNAL(triggered(bool)), obj, slot, conn);
}
//static
void Action::insertToBegin(QWidget*w, QAction*act) {
	ASSERT(w && act);
	QList<QAction*> li = w->actions();
	if(li.isEmpty()) {
		w->addAction(act);
	} else {
		w->insertAction(li[0], act);
	}
}
//static
void Action::insertToBegin(QWidget*w, const QList<QAction*> & lact) {
	ASSERT(w);
	QList<QAction*> li = w->actions();
	if(li.isEmpty()) {
		w->insertActions(0, lact);
	} else {
		w->insertActions(li[0], lact);
	}
}