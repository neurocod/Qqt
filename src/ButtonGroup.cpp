//ButtonGroup.cpp by Kostya Kozachuck as neurocod - 11.03.2012 6:41:26
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "ButtonGroup.h"

ButtonGroup::ButtonGroup(QObject * parent) {
	d = new QButtonGroup(parent);
	exclusive.init(d);
}
ButtonGroup& ButtonGroup::operator<<(QAbstractButton * button) {
	d->addButton(button);
	return *this;
}