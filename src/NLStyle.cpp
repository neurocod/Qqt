//NLStyle.cpp by Kostya Kozachuck as neurocod - 01.10.2009 21:31:32
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "NLStyle.h"

LPCSTR NLStyle::s_strDateTimeFormatFull = "yyyy.MM.dd hh:mm:ss.zzz";

CompactTextEdit::CompactTextEdit(QWidget*parent):
		QTextEdit(parent) {
}
//virtual
QSize CompactTextEdit::sizeHint()const {
	QSize sz = __super::sizeHint();
	sz.setHeight(30);
	return sz;
}
//virtual
QSize CompactTextEdit::minimumSizeHint()const {
	QSize sz(30,30);
	return sz;
}
//________________________________________________________________
CompactLineEdit::CompactLineEdit(QWidget*parent):
		QLineEdit(parent) {
}
//virtual
QSize CompactLineEdit::sizeHint()const {
	QSize sz = __super::sizeHint();
	sz.setWidth(128);
	return sz;
}
//virtual
QSize CompactLineEdit::minimumSizeHint()const {
	QSize sz = __super::minimumSizeHint();
	return sz;
}
//________________________________________________________________
QPixmap pixmapFromText(QString text, int w, int h, QColor clrText, int nFontSize) {
	QPixmap pixmap(w, h);
	pixmap.fill(Qt::transparent);
	QPainter painter(&pixmap);
	QFont font("MS Sans Serif", nFontSize, QFont::Normal);
	painter.setFont(font);
	painter.setPen(clrText);
	painter.drawText(0, nFontSize, text);
	return pixmap;
}
QPixmap pixmapFromText(QString text, int w, int h, QColor clrText) {
	return pixmapFromText(text, w, h, clrText, h);
}