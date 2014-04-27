//ToolButton.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "ToolButton.h"

void ToolButton::init() {
	d = new QToolButton();
	AbstractButtonPropertyRedirects::init(d);
	defaultAction.init(d);
	toolButtonStyle.init(d);
	arrowType.init(d);
	autoRaise.init(d);
	popupMode.init(d);
}