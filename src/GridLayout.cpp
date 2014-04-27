//GridLayout.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "GridLayout.h"

GridLayout::GridLayout() {
}
void GridLayout::init() {
	d = new QGridLayout();
	__super::init(d);
}