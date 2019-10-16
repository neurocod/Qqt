//JsonValueReader.h by neurocod - 2015.11.11 13:16:50
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "StringStatus.h"

QJsonValue toJson(qint64 n);
QJsonValue toJson(quint64 v);
QJsonValue toJson(QJsonValue::Type type);
QJsonValue toJson(bool b);
QJsonValue toJson(double n);
QJsonValue toJson(int n);
QJsonValue toJson(const QString &s);
QJsonValue toJson(QLatin1String s);
QJsonValue toJson(const char *s);
QJsonValue toJson(const QJsonArray &a);
QJsonValue toJson(const QJsonObject &o);
QJsonValue toJson(const QJsonValue &other);
QJsonValue toJson(const QUuid & v);
QJsonValue toJson(const QUrl & v);
QJsonValue toJson(const QByteArray & v);
QJsonValue toJson(const QVariantList & v);
QJsonValue toJson(const QDateTime & v);
QJsonValue toJson(const QJsonValue & v);
QJsonValue toJson(const QColor & v);
template<class T>
QJsonArray toJson(const QList<T> & list) {
	QJsonArray arr;
	for(auto&& t: list) {
		arr.append(toJson(t));
	}
	return arr;
}
template<class T>
QJsonArray toJson(const QSet<T> & list) {
	QJsonArray arr;
	for(auto&& t: list) {
		arr.append(toJson(t));
	}
	return arr;
}
template<class T>
QJsonArray toJson(const QVector<T> & list) {
	QJsonArray arr;
	for(auto&& t: list) {
		arr.append(toJson(t));
	}
	return arr;
}
template<class T>
void insert(QJsonObject & js, const QString & name, const T & v) {
	js.insert(name, toJson(v));
}
//Common error policy: set success once at start, and change to error only
class JsonValueReader: public ReadStatus {
	public:
		const QJsonObject & _js;
		static const char* s_strDateTimeFormat;
		static StringStatusT<QJsonObject> fromDocument(const QByteArray & arr);

		JsonValueReader(const QJsonObject & js): _js(js) {}
		void setStatus(const ReadStatus & r) { static_cast<ReadStatus&>(*this) = r; }
		void setStatus(ReadStatus && r) { static_cast<ReadStatus&>(*this) = r; }
		static StringStatus load(const QJsonValue & js, bool & v);
		static StringStatus load(const QJsonValue & js, qint8 & v);
		static StringStatus load(const QJsonValue & js, qint16 & v);
		static StringStatus load(const QJsonValue & js, qint32 & v);
		static StringStatus load(const QJsonValue & js, qint64 & v);
		static StringStatus load(const QJsonValue & js, quint8 & v);
		static StringStatus load(const QJsonValue & js, quint16 & v);
		static StringStatus load(const QJsonValue & js, quint32 & v);
		static StringStatus load(const QJsonValue & js, quint64 & v);
		static StringStatus load(const QJsonValue & js, qreal & v);
		static StringStatus load(const QJsonValue & js, QString & v);
		static StringStatus load(const QJsonValue & js, Uid & v);
		static StringStatus load(const QJsonValue & js, QUrl & v);
		static StringStatus load(const QJsonValue & js, QColor & v);
		static StringStatus load(const QJsonValue & js, QByteArray & v);
		static StringStatus load(const QJsonValue & js, QVariant & v);
		static StringStatus load(const QJsonValue & js, QVariantList & v);
		static StringStatus load(const QJsonValue & js, QDateTime & v);
		static StringStatus load(const QJsonValue & js, QJsonArray & v);
		static StringStatus load(const QJsonValue & js, QJsonObject & v);
		
		static bool toBool(const QJsonValue & j);
		static qint8 toInt8(const QJsonValue & j);
		static qint16 toInt16(const QJsonValue & j);
		static qint32 toInt32(const QJsonValue & j);
		static qint64 toInt64(const QJsonValue & j);
		static quint8 toUInt8(const QJsonValue & j);
		static quint16 toUInt16(const QJsonValue & j);
		static quint32 toUInt32(const QJsonValue & j);
		static quint64 toUInt64(const QJsonValue & j);
		static qreal toReal(const QJsonValue & j);
		static QString toString(const QJsonValue & j);
		static QUuid toUuid(const QJsonValue & j);
		static QColor toColor(const QJsonValue & j);
		static QByteArray toByteArray(const QJsonValue & j);
		static QVariant toVariant(const QJsonValue & j);
		static QVariantList toVariantList(const QJsonValue & j);
		static QDateTime toDateTime(const QJsonValue & j);
		static QJsonArray toJsonArray(const QJsonValue & j);
		static QJsonObject toJsonObject(const QJsonValue & j);
		bool require(const QString & name, UidList & ids, bool acceptNulls);
		QJsonArray requireArray(const QString & name, bool acceptEmpty = true);
		QJsonArray optionalArray(const QString & name);
		QJsonArray optionalArray(const QString & name, OUT bool & keyFound);//but key can be of type not an array
		template<class T>
		bool require(const QString & name, T & t) {
			auto it = _js.constFind(name);
			if(_js.constEnd()==it) {
				setError(QObject::tr("Required field '%1' not found").arg(name));
				return false;
			}
			auto ret = load(it.value(), t);
			if(!ret.ok())
				set(ret);
			return ret.ok();
		}
		template<class Enum>
		bool requireEnum(const QString & name, Enum & e) {
			auto it = _js.constFind(name);
			if(_js.constEnd()==it) {
				setError(QObject::tr("Required field '%1' not found").arg(name));
				return false;
			}
			if(!it.value().isDouble()) {
				setError(QObject::tr("Required enum '%1' is not number").arg(name));
				return false;
			}
			const int n = it.value().toDouble();
			if(n < 0) {
				setError("enum '" + name + "' is < 0");
				return false;
			}
			e = (Enum)n;
			return true;
		}
		template<class T>
		bool optional(const QString & name, T & t)const {
			auto it = _js.constFind(name);
			if(_js.constEnd()==it)
				return false;
			load(it.value(), t);
			return true;
		}
		template<class Enum>
		bool optionalEnum(const QString & name, Enum & e) {
			auto it = _js.constFind(name);
			if(_js.constEnd()==it)
				return false;
			const int n = it.value().toDouble();
			if(n < 0) {
				setError("enum '" + name + "' is < 0");
				return false;
			}
			e = (Enum)n;
			return true;
		}
};
template<>
bool JsonValueReader::require(const QString & name, QUuid & t);
template<>
bool JsonValueReader::require(const QString & name, UidList & t);
