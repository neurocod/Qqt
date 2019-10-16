//StringStatus.cpp by Kostya Kozachuck as neurocod - 2013.09.13 05:27:49
//BSD license
#include "pch.h"
#include "StringStatus.h"

StringStatus::~StringStatus() {
	if(_error) {
		//хотя этот if и не нужен, так как delete сработает и с нулевым указателем,
		//в оптимизации под move semantics, когда программа видит что там заранее ноль,
		//эта проверка может помочь избежать вызова в неизвестный код delete
		delete _error;
	}
}
StringStatus::StringStatus(bool ok): _error(ok ? 0 : new QString()) {
	maybeStop();
}
StringStatus::StringStatus(const QString& str, const QString& function, const QString& file, int line) {
	_error = new QString(QStringLiteral("%1 in %2 %3:%4"));
	(*_error ) = _error->arg(str, function, file).arg(line);
	maybeStop();
}
StringStatus::StringStatus(const QDataStream & stream) {
	auto status = stream.status();
	switch(status) {
		case QDataStream::Ok: break;
		case QDataStream::ReadPastEnd: setError(QObject::tr("read past end")); break;
		case QDataStream::ReadCorruptData: setError(QObject::tr("read currupt data")); break;
		case QDataStream::WriteFailed: setError(QObject::tr("write failed")); break;
		default: setError(QObject::tr("Unknown status code"));
	}
}
StringStatus::StringStatus(const QTextStream & stream) {
	auto status = stream.status();
	switch(status) {
		case QDataStream::Ok: break;
		case QDataStream::ReadPastEnd: setError(QObject::tr("read past end")); break;
		case QDataStream::ReadCorruptData: setError(QObject::tr("read currupt data")); break;
		case QDataStream::WriteFailed: setError(QObject::tr("write failed")); break;
		default: setError(QObject::tr("Unknown status code"));
	}
}
StringStatus::StringStatus(const char* msg): _error(new QString(msg)) {
	maybeStop();
}
StringStatus::StringStatus(const QString & msg): _error(new QString(msg)) {
	maybeStop();
}
StringStatus::StringStatus(const StringStatus & other): _error(other._error ? new QString(*other._error) : 0) {
	//no maybeStop() because error already caught in debugger (if any) at production point.
}
StringStatus::StringStatus(StringStatus && other) : _error(other._error) {
	other._error = 0;
	//no maybeStop() because error already caught in debugger (if any) at production point.
}
StringStatus& StringStatus::operator=(const StringStatus & other) {
	delete _error;
	if(other._error)
		_error = new QString(*other._error);
	else
		_error = 0;
	return *this;
}
StringStatus& StringStatus::operator=(StringStatus && other) {
	std::swap(_error, other._error);
	return *this;
}
void StringStatus::setOk() {
	if(!_error)
		return;
	delete _error;
	_error = 0;
}
void StringStatus::set(const StringStatus & other) {
	if(other._error) {
		setError(*other._error);
		return;
	}
	delete _error;
	_error = 0;
}
void StringStatus::setError(const QString & msg) {
	if(Q_UNLIKELY(_error)) {
		*_error = msg;
	} else {
		_error = new QString(msg);
	}
	maybeStop();
}
QString StringStatus::msg()const {
	return _error ? *_error : QString();
}
void StringStatus::maybeStop() {
	if(!_error)
		return;
	const QString& s = *_error;
	if(s==QStringLiteral("Connection refused")
	|| s==QStringLiteral("Unknown error"))
		return;
	int t = 3;//for debug breakpoint
}
QString StringStatus::toString()const {
	if(!_error)
		return QStringLiteral("Status: OK");
	return QStringLiteral("Status: error %1").arg(*_error);
}
bool StringStatus::ok(const QDataStream & stream) {//static
	return stream.status()==QDataStream::Ok;
}
void StringStatus::msgBox(const QString & additionalInfo)const {
#ifdef QT_WIDGETS_LIB
	if(_error) {
		QString title = qApp->applicationName();
		if(!additionalInfo.isEmpty())
			title += ' ' + additionalInfo;
		MsgBox::critical(0, title, *_error);
		return;
	}
	MsgBox::information(0, qApp->applicationName(), additionalInfo);
#else
	print(additionalInfo);
#endif
}
void StringStatus::print(const QString & additionalInfo)const {
	if(_error) {
		QString s = *_error;
		if(!additionalInfo.isEmpty())
			s += ' ' + additionalInfo;
		qCritical() << s;
	} else {
		qInfo() << additionalInfo;
	}
}