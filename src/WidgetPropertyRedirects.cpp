//WidgetPropertyRedirects.cpp by Kostya Kozachuck as neurocod - 16.09.2011 2:05:58
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "WidgetPropertyRedirects.h"

WidgetPropertyRedirects::WidgetPropertyRedirects() {
}
void WidgetPropertyRedirects::init(QWidget*d) {
	__super::init(d);
	maximumWidth.init(d);
	acceptDrops.init(d);
	accessibleDescription.init(d);
	accessibleName.init(d);
	autoFillBackground.init(d);
	baseSize.init(d);
	contextMenuPolicy.init(d);
	cursor.init(d);
	enabled.init(d);
	focusPolicy.init(d);
	font.init(d);
	geometry.init(d);
	inputMethodHints.init(d);
	layoutDirection.init(d);
	locale.init(d);
	maximumHeight.init(d);
	maximumSize.init(d);
	minimumHeight.init(d);
	minimumSize.init(d);
	minimumWidth.init(d);
	mouseTracking.init(d);
	palette.init(d);
	pos.init(d);
	size.init(d);
	sizeIncrement.init(d);
	sizePolicy.init(d);
	statusTip.init(d);
	styleSheet.init(d);
	toolTip.init(d);
	updatesEnabled.init(d);
	visible.init(d);
	whatsThis.init(d);
	windowFilePath.init(d);
	windowFlags.init(d);
	windowIcon.init(d);
	windowIconText.init(d);
	windowModality.init(d);
	windowModified.init(d);
	windowOpacity.init(d);
	windowTitle.init(d);
}