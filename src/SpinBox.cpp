//SpinBox.cpp by Kostya Kozachuck as neurocod - 11.03.2012 20:16:59
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "SpinBox.h"

SpinBox::SpinBox(QWidget * parent) {
	init();
	d->setParent(parent);
}
void SpinBox::init() {
	d = new QSpinBox();
	__super::init(d);
	maximum.init(d);
	minimum.init(d);
	prefix.init(d);
	singleStep.init(d);
	suffix.init(d);
	value.init(d);
}