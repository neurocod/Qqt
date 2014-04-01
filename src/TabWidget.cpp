//TabWidget.cpp by Kostya Kozachuck as neurocod - 08.12.2012 13:28:55
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "TabWidget.h"

TabWidget::TabWidget(QWidget*parent) {
	init(parent);
}
void TabWidget::init(QWidget*parent) {
	d = new QTabWidget(parent);
	WidgetPropertyRedirects::init(d);
	currentIndex.init(d);
	documentMode.init(d);
	elideMode.init(d);
	iconSize.init(d);
	movable.init(d);
	tabPosition.init(d);
	tabShape.init(d);
	tabsClosable.init(d);
	usesScrollButtons.init(d);
}