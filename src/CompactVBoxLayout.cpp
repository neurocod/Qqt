//CompactVBoxLayout.cpp by Kostya Kozachuck as neurocod - 19.07.2011 9:47:14
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "CompactVBoxLayout.h"

QVBoxLayout* compactVBoxLayout(QWidget*parent) {
	QVBoxLayout* layout = new QVBoxLayout(parent);
	layout->setMargin(0);
	layout->setSpacing(0);
	return layout;
}
//________________________________________________________________
CompactVBoxLayout::CompactVBoxLayout() {
	setCompact();
}
CompactVBoxLayout::CompactVBoxLayout(QWidget*parent): VBoxLayout(parent) {
	setCompact();
}
CompactVBoxLayout::CompactVBoxLayout(QBoxLayout*parent): VBoxLayout(parent) {
	setCompact();
}