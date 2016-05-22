//SqliteDb.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "DbWorker.h"

class SqliteDb: public DbWorker {
	public:
		SqliteDb(QObject*parent = 0);
		virtual ~SqliteDb() {}

		static QVariant toVariantByteArray(const QDateTime & dt);
		//static QDateTime fromVariant<QDateTime>(const QVariant & v);
		static QDateTime dateTimeFromVariant(const QVariant & v);
		QVariant lastInsertedId();
		bool openDB(const QString & strFile, const QString & strConnection = "", const QString & host = "localhost");
	protected:
		PreparedSqlQuery _queryLastInsertedId;
};