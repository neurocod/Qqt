//ToolButton.cpp by Kostya Kozachuck as neurocod - 28.08.2011 0:27:58
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "ToolButton.h"

void ToolButton::init() {
	d = new QToolButton();
	AbstractButtonPropertyRedirects::init(d);
	defaultAction.init(d);
	toolButtonStyle.init(d);
}