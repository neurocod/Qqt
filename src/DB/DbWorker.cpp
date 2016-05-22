//DbWorker.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "DbWorker.h"
#include <QSqlError>

DbWorker::DbWorker(QObject*parent):
	QObject(parent),
	_bShowErrors(true),
	_bShowErrorsInTracer(true),
	_bQueriesPrepared(false)
{
}
void DbWorker::setDB(const QSqlDatabase & db) {
	ASSERT(!_db.isOpen() && db.isOpen());
	_bQueriesPrepared = false;
	_db = db;
}
bool DbWorker::execOrTrace(QSqlQuery & q, const QString & statement) {
	bool ret = q.exec(statement);
	if(!ret) {
		traceLastError(q);
	}
	return ret;
}
bool DbWorker::execOrTrace(QSqlQuery & q) {
	bool ret = q.exec();
	if(!ret) {
		traceLastError(q);
	}
	return ret;
}
void DbWorker::maybeShowLastError(const QString & title, const QString & text) {
	if(!_bShowErrors)
		return;
	qDebug() << (title + " " + text);
	//msgBox(title, text);
	/*if(_bShowErrorsInTracer) {
		QString str = QString("%1\n%2")
			.arg(title)
			.arg(text);
		reportError(str);
	} else {
		QMessageBox::warning(0, title, text, QMessageBox::Ok, QMessageBox::Ok);
	}*/
}
void DbWorker::maybeShowLastError(const QString & text) {
	maybeShowLastError(QObject::tr("Database error"), text);
}
void DbWorker::traceLastError(const QSqlDatabase & q) {
	maybeShowLastError(q.lastError().text());
}
void DbWorker::traceLastError(const QSqlQuery & q) {
	QString text = QObject::tr("%1\nError query: %2")
		.arg(q.lastError().text())
		.arg(q.lastQuery());
	maybeShowLastError(QObject::tr("Database query error"), text);
}
WriteStatus DbWorker::prepareQueriesOnce() {
	if(!_db.isOpen() || !_db.isValid()) {
		maybeShowLastError(
			QObject::tr("Trying to prepare queries while database is not open\n"));
		return false;
	}
	if(!_bQueriesPrepared) {
		for(PreparedSqlQuery* q: _listToPrepare) {
			q->setDB(_db);
			if(!prepareOrTrace(*q, q->queryToPrepare())) {
				return false;
			}
		}
		_bQueriesPrepared = true;
	}
	return _bQueriesPrepared;
}
bool DbWorker::prepareOrTrace(QSqlQuery & q, const QString & statement) {
	bool ret = q.prepare(statement);
	if(!ret) {
		traceLastError(q);
	}
	return ret;
}
bool DbWorker::deleteAllRecords(const QString & strTableName) {
	//seems like DELETE FROM name can't be prepared
	QSqlQuery query(_db);
	if(!prepareOrTrace(query,
			QString("DELETE FROM %1;").arg(strTableName)
			)) {
		return false;
	}
	//query.bindValue(":t", strTableName);
	if(!query.exec()) {
		traceLastError(query);
		return false;
	}
	return true;
}
StringStatus DbWorker::lastError()const {
	auto err = _db.lastError();
	if(err.type()==QSqlError::NoError)
		return true;
	return StringStatus(false, err.text());
}
void DbWorker::maybeTransaction() {
	if(1==_transaction.count) {
		ASSERT(!_transaction.isOpen);
		_transaction.isOpen = true;
		_transaction.isResolved = false;
		_transaction.status = StringStatus(true);
		if(!_db.transaction()) {
			_transaction.status = lastError();
		}
	} else {
		ASSERT(_transaction.isOpen);
	}
}
void DbWorker::maybeCommit() {
	if(!_transaction.isOpen || 1!=_transaction.count)
		return;
	_transaction.isOpen = false;
	_transaction.isResolved = true;
	if(!_db.commit()) {
		_transaction.status = lastError();
	}
}
void DbWorker::rollback() {
	if(!_transaction.isOpen)
		return;
	_transaction.status = StringStatus(false, tr("rolled back"));
	_transaction.isOpen = false;
	_transaction.isResolved = true;
	if(!_db.rollback()) {
		_transaction.status = lastError();
	}
}
WriteStatus DbWorker::initSqlOnce() {
	auto status = connectToDbOnce();
	if(!status.ok()) {
		return status;
	}
	return prepareQueriesOnce();
}
void DbWorker::prepareLater(PreparedSqlQuery*q) {
	if(_listToPrepare.contains(q)) {
		ASSERT(0);
		return;
	}
	_listToPrepare << q;
}
void DbWorker::remove(PreparedSqlQuery*q) {
	if(1!=_listToPrepare.removeAll(q)) {
		ASSERT(0);
	}
}