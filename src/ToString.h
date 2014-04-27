//ToString.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

QString toString(double n);
QString toString(qint32 n);
QString toString(qint64 n);
QString toString(quint32 n);
QString toString(quint64 n);
QString toString(const QColor & c);
QString toString(const QSize & sz);
QString toString(const QRect & r);
QString toString(const QRectF & r);
QString toString(const QPoint & p);
QString toString(const QPointF & p);
QString toString(const QString & str);
QString reversed(const QString & str);
template<class T>
QList<T> reversed(const QList<T> & li) {
	QList<T> ret;
	foreach(auto t, li)
		ret.prepend(t);
	return ret;
}
QByteArray toByteArray(const QString & str);