//ToString.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "ToString.h"

template<typename T>
QString toStringT(T t) {
	return QString("%1").arg(t);
}
QString toString(double n) { return toStringT(n); }
QString toString(qint32 n) { return toStringT(n); }
QString toString(qint64 n) { return toStringT(n); }
QString toString(quint32 n) { return toStringT(n); }
QString toString(quint64 n) { return toStringT(n); }
QString reversed(const QString & str) {
    QString ret;
    for (int i = str.length() - 1; i>=0; i--)
        ret += str.at(i);
    return ret;
}
QString toString(const QSize & sz) {
	QString ret = QString("QSize(%1, %2)").arg(sz.width()).arg(sz.height());
	return ret;
}
QString toString(const QRect & r) {
	QString str = QString("QRect(%1, %2, %3, %4)")
		.arg(r.left())
		.arg(r.top())
		.arg(r.width())
		.arg(r.height());
	return str;
}
QString toString(const QRectF & r) {
	QString str = QString("QRectF(%1, %2, %3, %4)")
		.arg(r.left())
		.arg(r.top())
		.arg(r.width())
		.arg(r.height());
	return str;
}
QString toString(const QPoint & p) {
	return QString("QPoint(%1, %2)").arg(p.x()).arg(p.y());
}
QString toString(const QPointF & p) {
	return QString("QPointF(%1, %2)").arg(p.x()).arg(p.y());
}
QString toString(const QString & str) {
	return str;
}
QByteArray toByteArray(const QString & str) {
	QByteArray ret;
	ret.append(str);
	return ret;
}
QString toString(const QColor & clr) {
	QString ret = QString("#%1%2%3")
		.arg(clr.red(), 2, 16, QChar('0'))
		.arg(clr.green(), 2, 16, QChar('0'))
		.arg(clr.blue(), 2, 16, QChar('0'));
	return ret;
}

void assertWithFunc(const char *assertion, const char *file, const char *func, int line) {
	QByteArray arr = assertion;
	arr += " in funcion ";
	arr += func;
	qt_assert(arr, file, line);
}