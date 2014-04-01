//VBoxLayout.cpp by Kostya Kozachuck as neurocod - 19.07.2011 9:47:07
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "VBoxLayout.h"

VBoxLayout::VBoxLayout() {
	init();
}
VBoxLayout::VBoxLayout(QWidget*parent) {
	init();
	parent->setLayout(d);
}
VBoxLayout::VBoxLayout(QBoxLayout*parent) {
	init();
	parent->addLayout(d);
}
void VBoxLayout::init() {
	d = new QVBoxLayout();
	__super::init(d);
}