//StringStatus.h by Kostya Kozachuck as neurocod - 2013.09.13 05:27:49
//BSD license
#pragma once
template<class T> class StringStatusT;
template<class T> class StringStatusV;

//аналог bool + строковая информация об ошибке.
//хранит только указатель на строку, который == 0 если все ок.
//при возврате из функции затраты на возврат одного указателя.
class StringStatus {
	protected:
		QString* _error = 0;
		void maybeStop();
		template<class T> friend class StringStatusT;
		template<class T> friend class StringStatusV;
	public:
		StringStatus() {}//ok
		StringStatus(bool ok);
		StringStatus(const StringStatus & other);
		StringStatus(StringStatus && other);
		StringStatus(const QDataStream & stream);
		StringStatus(const QTextStream & stream);
		StringStatus(const QString & msg);//error
		StringStatus(const char* msg);//error
		StringStatus(const QString& str, const QString& function, const QString& file, int line);
		~StringStatus();
		void setError(const QString & msg);
		void setOk();
		void set(const StringStatus & msg);
		void setStatus(const StringStatus & msg) { set(msg); }
		bool ok()const { return !_error; }
		bool isError()const { return _error; }
		QString msg()const;
		QString toString()const;
		void msgBox(const QString & additionalInfo = QString())const;
		void print(const QString & additionalInfo = QString())const;
		StringStatus& operator=(const StringStatus & other);
		StringStatus& operator=(StringStatus && other);
		static bool ok(const QDataStream & stream);
};

template<class T>
class StringStatusT: public StringStatus {
	//StringStatusT<QString> produces error, in such case use one of:
	//StringStatusV<QString> or StringStatusT<QVariant> or QPair<StringStatus, QString>
	public:
		T _v;//attached value
		T operator->()const { return _v; }
		T operator*()const { return _v; }
		
		StringStatusT(): _v() {}
		StringStatusT(bool ok): StringStatus(ok), _v() {}
		StringStatusT(const QString & error): StringStatus(error),  _v() {}
		StringStatusT(const T & t): _v(t) {}
		StringStatusT(T && t): _v(std::move(t)) {}
		StringStatusT(const StringStatusT<T> & other): StringStatus(other), _v(other._v) {}
		StringStatusT(const StringStatus & other): StringStatus(other),  _v() {}
		StringStatusT(StringStatus && other):  _v() {
			_error = other._error;
			other._error = 0;
		}
		StringStatusT(StringStatusT<T> && other): StringStatus(std::move(other)), _v(std::move(other._v)) {
			_error = other._error;
			other._error = 0;
		}
};
template<class T>
class StringStatusV: public StringStatus {
	//the only difference from StringStatusT is absense of (const T & t) ctor,
	//so there is no disambiguation in some cases like StringStatusV<QString>
	public:
		T _v;//attached value
		T operator->()const { return _v; }
		
		StringStatusV():  _v() {}
		StringStatusV(bool ok): StringStatus(ok),  _v() {}
		StringStatusV(bool ok, const T & t): StringStatus(ok), _v(t) {}
		StringStatusV(bool ok, T && t): StringStatus(ok), _v(t) {}
		StringStatusV(const QString & error): StringStatus(error),  _v() {}
		StringStatusV(const StringStatusV<T> & other): StringStatus(other), _v(other._v) {}
		StringStatusV(const StringStatus & other): StringStatus(other),  _v() {}
		StringStatusV(StringStatusV<T> && other): _v(std::move(other._v)) {
			_error = other._error;
			other._error = 0;
		}
		StringStatusV(StringStatus && other):  _v() {
			_error = other._error;
			other._error = 0;
		}
};
//template<class T>
//StringStatusV<T> StringStatusV_make(bool b, const T & t) {
//	return StringStatusV<T>(b, t);
//}
using ReadStatus = StringStatus;
using WriteStatus = StringStatus;
template<class T> using ReadStatusT = StringStatusT<T>;
template<class T> using WriteStatusT = StringStatusT<T>;
template<class T> using ReadStatusV = StringStatusV<T>;
template<class T> using WriteStatusV = StringStatusV<T>;

//in gcc maybe make another define witout QStringLiteral
#ifdef Q_OS_WIN
#define STRING_STATUS(STR) StringStatus(STR, __FUNCTION__, QStringLiteral(__FILE__), __LINE__)
#else
#define STRING_STATUS(STR) StringStatus(STR, __FUNCTION__, __FILE__, __LINE__)
#endif