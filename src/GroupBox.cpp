//GroupBox.cpp by Kostya Kozachuck as neurocod - 11.03.2012 10:29:36
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "GroupBox.h"

GroupBox::GroupBox() {
	init();
}
void GroupBox::init() {
	d = new QGroupBox();
	__super::init(d);
	checkable.init(d);
	checked.init(d);
	flat.init(d);
	title.init(d);
}
void GroupBox::connectClicks(QObject*obj, const char * slot) {
	QObject::connect(d, SIGNAL(clicked(bool)), obj, slot);
}