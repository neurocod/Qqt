//DbTransaction.cpp by Kostya Kozachuck as neurocod - 2013.09.16 19:40:25
#include "pch.h"
#include "DbTransaction.h"
#include "DbWorker.h"

//способ инициализации типа DbTransaction transaction = db.createTransaction() не очень подходит из-за двойного вызова конструктора
//и конструктора копирования - проще один конструктор на самом верху
DbTransaction::DbTransaction(DbWorker & db) {
	_db = &db;
	_db->_transaction.count++;
	_db->maybeTransaction();
}
DbTransaction::~DbTransaction() {
	_db->_transaction.count--;
	if(0==_db->_transaction.count) {
		ASSERT(_db->_transaction.isResolved);
		ASSERT(!_db->_transaction.isOpen);
	}
}
const StringStatus & DbTransaction::status()const {
	return _db->_transaction.status;
}
bool DbTransaction::maybeCommit() {
	_db->maybeCommit();
	return status().ok();
}
bool DbTransaction::rollback() {
	_db->rollback();
	return status().ok();
}
bool DbTransaction::startedAndOk()const {
	return _db->_transaction.startedAndOk();
}