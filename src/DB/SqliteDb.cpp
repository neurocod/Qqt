//SqliteDb.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "SqliteDb.h"

SqliteDb::SqliteDb(QObject*parent): DbWorker(parent), _queryLastInsertedId(this, "SELECT last_insert_rowid()") {
}
QVariant SqliteDb::toVariantByteArray(const QDateTime & dt) { //static
	QByteArray arr;
	{
		QDataStream stream(&arr, QIODevice::WriteOnly);
		stream << dt;
	}
	return QVariant(arr);
}
QDateTime SqliteDb::dateTimeFromVariant(const QVariant & v) { //static
	QDateTime dt;
	if(v.canConvert(QVariant::ByteArray)) {
		const QByteArray arr = v.toByteArray();
		QDataStream stream(arr);
		stream >> dt;
	}
	return dt;
}
QVariant SqliteDb::lastInsertedId() {
	if(!execOrTrace(_queryLastInsertedId)) {
		return QVariant();
	}
	if(!_queryLastInsertedId.next()) {
		traceLastError(_queryLastInsertedId);
		return QVariant();
	}
	QVariant id = _queryLastInsertedId.value(0);
	return id;
}
bool SqliteDb::openDB(const QString & strFile, const QString & strConnection, const QString & host) {
	_db = QSqlDatabase::addDatabase("QSQLITE", strConnection);
	_db.setHostName(host);
	_db.setDatabaseName(strFile);
	if (!_db.open()) {
		traceLastError(_db);
		return false;
	}
	return true;
}