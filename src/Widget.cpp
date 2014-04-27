//Widget.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "Widget.h"

Widget::Widget(QWidget*parent) {
	d = new QWidget(parent);
	WidgetPropertyRedirects::init(d);
}