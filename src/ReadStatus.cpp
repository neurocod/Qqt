//ReadStatus.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "ReadStatus.h"

StringStatus::StringStatus(bool ok) {
	m_ok = ok;
	maybeStop();
}
StringStatus::StringStatus(const QDataStream & stream) {
	auto status = stream.status();
	m_ok = status==QDataStream::Ok;
	switch(status) {
		case QDataStream::Ok: m_msg.clear(); break;//m_msg = QObject::tr("OK"); break;
		case QDataStream::ReadPastEnd: m_msg = QObject::tr("read past end"); break;
		case QDataStream::ReadCorruptData: m_msg = QObject::tr("read currupt data"); break;
		case QDataStream::WriteFailed: m_msg = QObject::tr("write failed"); break;
	}
	maybeStop();
}
StringStatus::StringStatus(bool ok, const QString & msg): m_msg(msg) {
	m_ok = ok;
	maybeStop();
}
StringStatus::StringStatus(const StringStatus & other): m_msg(other.m_msg) {
	m_ok = other.m_ok;
	maybeStop();
}
void StringStatus::maybeStop() {
	if(!m_ok)
		int t=3;//for debug breakpoint
}
//bool statusOk(const QDataStream & stream);
bool statusOk(const QDataStream & stream) {
	return stream.status()==QDataStream::Ok;
}