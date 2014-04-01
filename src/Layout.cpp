//Layout.cpp by Kostya Kozachuck as neurocod - 11.03.2012 21:04:56
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "Layout.h"

Layout::Layout() {
}
void Layout::init(QLayout*_d) {
	d = _d;
	__super::init(d);
	sizeConstraint.init(d);
	spacing.init(d);
}