//JsonValueReader.cpp by neurocod - 2015.11.11 13:16:50
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "JsonValueReader.h"

const char* JsonValueReader::s_strDateTimeFormat = "yyyy.MM.dd hh:mm:ss.zzz";
QJsonValue toJson(QJsonValue::Type type) {
	return type;
}
QJsonValue toJson(bool b) { return b; }
QJsonValue toJson(double n) { return n; }
QJsonValue toJson(int n) { return n; }
QJsonValue toJson(qint64 n) { return n; }
QJsonValue toJson(const QString &s) { return s; }
QJsonValue toJson(QLatin1String s) { return s; }
QJsonValue toJson(const char *s) { return s; }
QJsonValue toJson(const QJsonArray &a) { return a; }
QJsonValue toJson(const QJsonObject &o) { return o; }
QJsonValue toJson(quint64 v) {
	return (qint64)v;
}
QJsonValue toJson(const QUuid & id) {
	return id.toString();
}
QJsonValue toJson(const QUrl & v) {
	return v.toString();
}
QJsonValue toJson(const QColor & v) {
	return Qqt::toString(v);
}
QJsonValue toJson(const QJsonValue & v) {
	return v;
}
QJsonValue toJson(const QByteArray & v) {
	return QString(v.toHex());
}
QJsonValue toJson(const QVariantList & v) {
	return QJsonArray::fromVariantList(v);
}
QJsonValue toJson(const QDateTime & v) {
	return v.toString(JsonValueReader::s_strDateTimeFormat);
}
bool JsonValueReader::toBool(const QJsonValue & js) {
	return js.toBool();
}
qint8 JsonValueReader::toInt8(const QJsonValue & js) {
	return js.toInt();
}
qint16 JsonValueReader::toInt16(const QJsonValue & js) {
	return js.toInt();
}
qint32 JsonValueReader::toInt32(const QJsonValue & js) {
	return js.toInt();
}
qint64 JsonValueReader::toInt64(const QJsonValue & js) {
	return js.toInt();
}
quint8 JsonValueReader::toUInt8(const QJsonValue & js) {
	return js.toInt();
}
quint16 JsonValueReader::toUInt16(const QJsonValue & js) {
	return js.toInt();
}
quint32 JsonValueReader::toUInt32(const QJsonValue & js) {
	return js.toInt();
}
quint64 JsonValueReader::toUInt64(const QJsonValue & js) {
	return js.toInt();
}
qreal JsonValueReader::toReal(const QJsonValue & js) {
	return js.toDouble();
}
QString JsonValueReader::toString(const QJsonValue & js) {
	return js.toString();
}
QUuid JsonValueReader::toUuid(const QJsonValue & js) {
	return QUuid(js.toString());
}
QColor JsonValueReader::toColor(const QJsonValue & js) {
	QString str = js.toString();
	if(str.isEmpty())
		return QColor();
	//if(str.startsWith('#')) {
	return QColor(str);
}
QByteArray JsonValueReader::toByteArray(const QJsonValue & js) {//static
	QString str = js.toString();
	//TODO: check hex range
	//for(QChar ch : str) {
	//}
	QByteArray arr;
	arr.append(str);
	return QByteArray::fromHex(arr);
}
template<>
bool JsonValueReader::require(const QString & name, QUuid & t) {
	QString s;
	if(!require(name, s))
		return false;
	t = QUuid(s);
	return true;
}
QJsonArray JsonValueReader::toJsonArray(const QJsonValue & js) {
	return js.toArray();
}
QJsonObject JsonValueReader::toJsonObject(const QJsonValue & js) {
	return js.toObject();
}
QVariant JsonValueReader::toVariant(const QJsonValue & js) {
	return js.toVariant();
}
template<>
bool JsonValueReader::require(const QString & name, UidList & li) {
	auto arr = requireArray(name);
	if(!ok())
		return false;
	for(auto&& v : arr) {
		if(!v.isString()) {
			setError("Uuid list: array value is not a string");
			return false;
		}
		QString s = v.toString();
		if(!s.startsWith('{')
		|| !s.endsWith('}')
		|| !s.contains('-')) {
			setError("Wrong uuid format in array");
			return false;
		}
		//TODO: more format checks
		QUuid id(s);
		li << id;
	}
	return true;
}
bool JsonValueReader::require(const QString & name, UidList & ids, bool acceptNulls) {
	if(!require(name, ids))
		return false;
	if(!acceptNulls) {
		for(auto & id : ids) {
			if(id.isNull()) {
				setError("Null uuid in uuid array");
				return false;
			}
		}
	}
	return true;
}
QVariantList JsonValueReader::toVariantList(const QJsonValue & js) {
	return js.toArray().toVariantList();
}
QDateTime JsonValueReader::toDateTime(const QJsonValue & js) {
	QString str = js.toString();
	return QDateTime::fromString(str, s_strDateTimeFormat);
}
StringStatus JsonValueReader::load(const QJsonValue & js, bool & v) {
	v = js.toBool();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, qint8 & v) {
	v = js.toInt();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, qint16 & v) {
	v = js.toInt();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, qint32 & v) {
	v = js.toInt();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, qint64 & v) {
	v = js.toInt();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, quint8 & v) {
	v = js.toInt();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, quint16 & v) {
	v = js.toInt();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, quint32 & v) {
	v = js.toInt();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, quint64 & v) {
	v = js.toInt();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, qreal & v) {
	v = js.toDouble();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, QString & v) {
	v = js.toString();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, Uid & v) {
	v = QUuid(js.toString());
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, QUrl & v) {
	v = QUrl(js.toString());
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, QColor & v) {
	QString str = js.toString();
	if(str.isEmpty()) {
		v = QColor();
		//} else if(str.startsWith('#')) {
	} else {
		v = QColor(str);
	}
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, QByteArray & v) {
	QString str = js.toString();
	for(QChar ch : str) {
		bool ok = ch.isDigit() || ('a'<=ch && ch<='f') || ('A'<=ch && ch<='F');
		if(!ok) {
			return QStringLiteral("Non-hex characters for json byte array");
		}
	}
	QByteArray arr;
	arr.append(str);
	v = QByteArray::fromHex(arr);
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, QJsonArray & v) {
	v = js.toArray();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, QJsonObject & v) {
	v = js.toObject();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, QVariant & v) {
	v = js.toVariant();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, QVariantList & v) {
	v = js.toArray().toVariantList();
	return true;
}
StringStatus JsonValueReader::load(const QJsonValue & js, QDateTime & v) {
	QString str = js.toString();
	v = QDateTime::fromString(str, s_strDateTimeFormat);
	return true;
}
QJsonArray JsonValueReader::requireArray(const QString & name, bool acceptEmpty) {
	auto it = _js.find(name);
	if(_js.end()==it) {
		setError(name + " required field not found");
		return QJsonArray();
	}
	auto js = it.value();
	if(!js.isArray()) {
		setError(name + " is not an array");
		return QJsonArray();
	}
	auto arr = it.value().toArray();
	if(!acceptEmpty && arr.isEmpty()) {
		setError(name + " is empty array");
	}
	return arr;
}
QJsonArray JsonValueReader::optionalArray(const QString & name) {
	bool keyFound;
	return optionalArray(name, keyFound);
}
QJsonArray JsonValueReader::optionalArray(const QString & name, OUT bool & keyFound) {
	auto it = _js.find(name);
	if(_js.end()==it) {
		keyFound = false;
		return QJsonArray();
	}
	keyFound = true;
	auto js = it.value();
	if(!js.isArray()) {
		return QJsonArray();
	}
	return it.value().toArray();
}
StringStatusT<QJsonObject> JsonValueReader::fromDocument(const QByteArray & arr) {//static
	QJsonParseError err;
	QJsonDocument doc = QJsonDocument::fromJson(arr, &err);
	if(err.error != QJsonParseError::NoError)
		return err.errorString();
	if(!doc.isObject())
		return QObject::tr("json doc is not an object");
	return doc.object();
}