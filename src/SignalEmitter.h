//SignalEmitter.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include <QObject>
#include "preprocessor.h"

class SignalEmitter: public QObject {
	Q_OBJECT
	MAYBE_SUPER(QObject)
	public:
		SignalEmitter(QObject *parent=0);
		virtual ~SignalEmitter() {}
	public slots:
		//v means variant - by parameters
		void emitv();
		void emitv(QString str);
		void emitv(QString str, QByteArray data);
		void emitv(QString str, QString data);
		void emitv(int n);
	signals:
		void v();
		void v(QString str);
		void v(QString str, QByteArray data);
		void v(QString str, QString data);
		void v(int n);
};