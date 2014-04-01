//Splitter.cpp by Kostya Kozachuck as neurocod - 16.09.2011 18:59:11
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "Splitter.h"

Splitter::Splitter(QWidget * parent) {
	init(parent);
}
Splitter::Splitter(Qt::Orientation _orientation, QWidget * parent) {
	init(parent);
	orientation = _orientation;
}
void Splitter::init(QWidget * parent) {
	d = new QSplitter(parent);
	WidgetPropertyRedirects::init(d);

	orientation.init(d);
	childrenCollapsible.init(d);
	handleWidth.init(d);
	opaqueResize.init(d);
	sizes.init(d);
}
Splitter & Splitter::operator<<(QWidget*w) {
	d->addWidget(w);
	return *this;
}
Splitter & Splitter::operator<<(QLayout*lay) {
	Widget w;
	w->setLayout(lay);
	d->addWidget(w);
	return *this;
}