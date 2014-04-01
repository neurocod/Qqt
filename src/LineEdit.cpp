//LineEdit.cpp by Kostya Kozachuck as neurocod - 11.03.2012 10:53:18
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "LineEdit.h"

LineEdit::LineEdit(QWidget * parent) {
	init();
	d->setParent(parent);
}
void LineEdit::init() {
	d = new QLineEdit();
	__super::init(d);
	alignment.init(d);
	cursorMoveStyle.init(d);
	cursorPosition.init(d);
	dragEnabled.init(d);
	echoMode.init(d);
	frame.init(d);
	inputMask.init(d);
	maxLength.init(d);
	modified.init(d);
	placeholderText.init(d);
	readOnly.init(d);
	text.init(d);
	completer.init(d);
}