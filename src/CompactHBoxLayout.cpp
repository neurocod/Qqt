//CompactHBoxLayout.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "CompactHBoxLayout.h"

QHBoxLayout* compactHBoxLayout(QWidget*parent) {
	QHBoxLayout* layout = new QHBoxLayout(parent);
	layout->setMargin(0);
	layout->setSpacing(0);
	return layout;
}
//________________________________________________________________
CompactHBoxLayout::CompactHBoxLayout() {
	setCompact();
}
CompactHBoxLayout::CompactHBoxLayout(QWidget*parent): HBoxLayout(parent) {
	setCompact();
}
CompactHBoxLayout::CompactHBoxLayout(QBoxLayout*parent): HBoxLayout(parent) {
	setCompact();
}