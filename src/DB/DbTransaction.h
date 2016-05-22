//DbTransaction.h by Kostya Kozachuck as neurocod - 2013.09.16 19:40:25
#pragma once
class DbWorker;

//возможны вложенные транзакции - выполняется только транзакция верхнего уровня, вложенные могут лишь прервать всех,
//но не закоммитить
class DbTransaction {
	public:
		DbTransaction(DbWorker & db);//starts transaction on db
		virtual ~DbTransaction();
		const StringStatus & status()const;
		bool maybeCommit();
		bool rollback();
		bool startedAndOk()const;
	protected:
		DbWorker*_db;
};