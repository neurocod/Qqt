//Widget.cpp by Kostya Kozachuck as neurocod - 16.09.2011 18:53:45
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "Widget.h"

Widget::Widget(QWidget*parent) {
	d = new QWidget(parent);
	WidgetPropertyRedirects::init(d);
}