//BoxLayout.cpp by Kostya Kozachuck as neurocod - 19.07.2011 9:47:17
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "BoxLayout.h"

BoxLayout::BoxLayout() {
}
BoxLayout& BoxLayout::operator<<(QWidget*w) {
	d->addWidget(w);
	return *this;
}
BoxLayout& BoxLayout::operator<<(QLayout*l) {
	d->addLayout(l);
	return *this;
}
BoxLayout& BoxLayout::operator<<(QLayoutItem * item) {
	d->addItem(item);
	return *this;
}
BoxLayout& BoxLayout::operator<<(const QString & str) {
	*this << new QLabel(str);
	return *this;
}
void BoxLayout::setCompact() {
	d->setMargin(0);
	d->setSpacing(0);
}
void BoxLayout::insertStretch(int index, int stretch) {
	d->insertStretch(index, stretch);
}
void BoxLayout::addStretch(int stretch) {
	d->addStretch(stretch);
}
void BoxLayout::init(QBoxLayout*_d) {
	d = _d;
	__super::init(d);
}