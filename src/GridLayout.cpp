//GridLayout.cpp by Kostya Kozachuck as neurocod - 11.03.2012 21:00:45
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "GridLayout.h"

GridLayout::GridLayout() {
}
void GridLayout::init() {
	d = new QGridLayout();
	__super::init(d);
}