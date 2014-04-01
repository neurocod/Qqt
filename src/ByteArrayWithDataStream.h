//ByteArrayWithDataStream.h by Kostya Kozachuck as neurocod - 01.06.2012 21:12:00
//BSD license https://github.com/neurocod/Qqt
#pragma once

class ByteArrayWithDataStream {
	public:
		QByteArray m_arr;
		QDataStream m_stream;
		//write mode
		ByteArrayWithDataStream(): m_stream(&m_arr, QIODevice::WriteOnly) {}
		//read mode
		ByteArrayWithDataStream(const QByteArray & arr): m_arr(arr), m_stream(&m_arr, QIODevice::ReadOnly) {}
		template<class T>
		ByteArrayWithDataStream & operator<<(const T & t) {
			m_stream << t;
			return *this;
		}
		template<class T>
		ByteArrayWithDataStream & operator>>(T & t) {
			m_stream >> t;
			return *this;
		}
		operator QDataStream &(){ return m_stream; }
		operator QByteArray &(){ return m_arr; }
};
template<class TValue>
class SerizlizableToQDataStream {
	public:
		virtual operator TValue()const=0;
		virtual TValue operator=(const TValue & val)=0;
};
template<class T>
QDataStream & operator>>(QDataStream & stream, SerizlizableToQDataStream<T> & t) {
	T t2;
	stream >> t2;
	t = t2;
	return stream;
}
template<class T>
QDataStream & operator<<(QDataStream & stream, SerizlizableToQDataStream<T> & t) {
	T t2 = t;
	stream << t2;
	return stream;
}