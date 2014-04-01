//ComboBox.cpp by Kostya Kozachuck as neurocod - 11.03.2012 7:19:02
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "ComboBox.h"

ComboBox::ComboBox() {
	init();
}
void ComboBox::init() {
	d = new QComboBox();
	__super::init(d);
	duplicatesEnabled.init(d);
	editable.init(d);
	frame.init(d);
	currentIndex.init(d);
	iconSize.init(d);
	insertPolicy.init(d);
	maxCount.init(d);
	maxVisibleItems.init(d);
	minimumContentsLength.init(d);
	modelColumn.init(d);
	sizeAdjustPolicy.init(d);
}
ComboBox& ComboBox::operator<<(QStringList texts) {
	d->addItems(texts);
	return *this;
}
ComboBox& ComboBox::operator<<(QString text) {
	d->addItem(text);
	return *this;
}
void ComboBox::add(const QString & text, const QVariant & userData) {
	d->addItem(text, userData);
}
void ComboBox::add(const QIcon & icon, const QString & text, const QVariant & userData) {
	d->addItem(icon, text, userData);
}