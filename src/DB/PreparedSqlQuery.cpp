//PreparedSqlQuery.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "PreparedSqlQuery.h"
#include "DbWorker.h"

PreparedSqlQuery::PreparedSqlQuery(DbWorker*parent, const QString & strQueryToPrepare):
		_strQueryToPrepare(strQueryToPrepare),
		_parent(parent) {
	ASSERT(_parent);
	_parent->prepareLater(this);
}
void PreparedSqlQuery::setDB(QSqlDatabase db) {
	QSqlQuery & q = *this;
	q = QSqlQuery(db);
}
PreparedSqlQuery::~PreparedSqlQuery() {
	_parent->remove(this);
}