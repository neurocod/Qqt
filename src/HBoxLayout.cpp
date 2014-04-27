//HBoxLayout.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "HBoxLayout.h"

HBoxLayout::HBoxLayout() {
	init();
}
HBoxLayout::HBoxLayout(QWidget*parent) {
	init();
	parent->setLayout(d);
}
HBoxLayout::HBoxLayout(QBoxLayout*parent) {
	init();
	parent->addLayout(d);
}
void HBoxLayout::init() {
	d = new QHBoxLayout();
	__super::init(d);
}