//FormLayout.cpp by Kostya Kozachuck as neurocod - 28.06.2012 21:59:11
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "FormLayout.h"

FormLayout::FormLayout(QWidget * parent) {
	init();
	if(parent)
		parent->setLayout(d);
}
FormLayout::FormLayout(QBoxLayout*parent) {
	init();
	if(parent)
		parent->addLayout(d);
}
void FormLayout::init() {
	ASSERT(!d);
	d = new QFormLayout();
	fieldGrowthPolicy.init(d);
	formAlignment.init(d);
	horizontalSpacing.init(d);
	labelAlignment.init(d);
	rowWrapPolicy.init(d);
	verticalSpacing.init(d);
}
FormLayout& FormLayout::operator << (QWidget*w) {
	d->addRow(w);
	return *this;
}
FormLayout& FormLayout::operator << (const QString & str) {
	d->addRow(new QLabel(str));
	return *this;
}