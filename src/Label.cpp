//Label.cpp by Kostya Kozachuck as neurocod - 29.02.2012 1:30:10
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "Label.h"

Label::Label() {
	init();
}
void Label::init() {
	d = new QLabel();
	WidgetPropertyRedirects::init(d);
	alignment.init(d);
	indent.init(d);
	margin.init(d);
	openExternalLinks.init(d);
	scaledContents.init(d);
	text.init(d);
	textFormat.init(d);
	textInteractionFlags.init(d);
	wordWrap.init(d);
}
void Label::set(const QImage & img) {
	set(QPixmap::fromImage(img));
}
void Label::set(const QPixmap& img) {
	d->setPixmap(img);
}
void Label::set(const QString& str) {
	d->setText(str);
}
void Label::operator=(const QImage & img) {
	set(img);
}
void Label::operator=(const QPixmap& img) {
	set(img);
}
void Label::operator=(const QString& str) {
	set(str);
}