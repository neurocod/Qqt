//GridLayout.cpp by Kostya Kozachuck as neurocod - 11.03.2012 21:00:45
#include "pch.h"
#include "GridLayout.h"

GridLayout::GridLayout() {
}
void GridLayout::init() {
	d = new QGridLayout();
	__super::init(d);
}