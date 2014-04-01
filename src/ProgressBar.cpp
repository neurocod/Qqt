//ProgressBar.cpp by Kostya Kozachuck as neurocod - 08.05.2012 14:21:12
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "ProgressBar.h"

ProgressBar::ProgressBar(QWidget * parent) {
	init();
	d->setParent(parent);
}
void ProgressBar::init() {
	d = new QProgressBar();
	__super::init(d);

	alignment.init(d);
	format.init(d);
	invertedAppearance.init(d);
	maximum.init(d);
	minimum.init(d);
	orientation.init(d);
	//text.init(d);
	textDirection.init(d);
	textVisible.init(d);
	value.init(d);
}