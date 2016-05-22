//PreparedSqlQuery.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include <QSqlQuery>
class DbWorker;

class PreparedSqlQuery: public QSqlQuery {
	public:
		PreparedSqlQuery(DbWorker*parent, const QString & strQueryToPrepare);
		virtual ~PreparedSqlQuery();

		QString queryToPrepare()const { return _strQueryToPrepare; }
		void setDB(QSqlDatabase db);
	protected:
		QString _strQueryToPrepare;
		DbWorker* _parent;
};