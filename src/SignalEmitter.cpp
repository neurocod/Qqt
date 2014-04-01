//SignalEmitter.cpp by Kostya Kozachuck as neurocod - 18.03.2009 1:15:20
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "SignalEmitter.h"

SignalEmitter::SignalEmitter(QObject *parent): QObject(parent) {
}
void SignalEmitter::emitv() {
	emit v();
}
void SignalEmitter::emitv(QString str) {
	emit v(str);
}
void SignalEmitter::emitv(QString str, QByteArray data) {
	emit v(str, data);
}
void SignalEmitter::emitv(QString str, QString data) {
	emit v(str, data);
}
void SignalEmitter::emitv(int n) {
	emit v(n);
}