//RestrictedValueTT.h by neurocod - 2013.06.16 00:26:26
#pragma once

template<class T, T _min, T _max>
class RestrictedValueTT {
	protected:
		T _v;
	public:
		RestrictedValueTT() {
			_v = (_min + _max)/2;
		}
		RestrictedValueTT(T t) {
			*this = t;
			ASSERT(t>=_min && t<=_max);
		}
		T min()const { return _min; }
		T max()const { return _max; }
		T value()const { return _v; }
		T operator=(T t) {
			_v = qBound(_min, t, _max);
			return _v;
		}
		T operator +=(T t) {
			_v = qBound(_min, _v + t, _max);
			return _v;
		}
		T operator -=(T t) {
			_v = qBound(_min, _v - t, _max);
			return _v;
		}
		T operator=(const QVariant & v) {
			T t = v.value<T>();
			*this = t;
			return _v;
		}
		operator T()const { return _v; }
		operator QVariant()const { return QVariant(_v); }
		template<class Gui>
		void setTo(Gui*gui)const {
			gui->setRange(_min, _max);
			gui->setValue(_v);
		}
		template<class Gui>
		void setTo(Gui & gui)const {
			gui->setRange(_min, _max);
			gui->setValue(_v);
		}
		template<class Gui>
		void update(bool toGui, Gui & gui) {
			if(toGui)
				setTo(gui);
			else
				*this = gui->value();
		}
		qreal to01()const {
			ASSERT(0==_min && _max>0);
			qreal ret = (qreal)_v / (qreal)_max;
			return ret;
		}
};
template<class T, T _min, T _max>
QDataStream & operator<<(QDataStream & stream, const RestrictedValueTT<T, _min, _max> & value) {
	stream << (T)value;
	return stream;
}
template<class T, T _min, T _max>
QDataStream & operator>>(QDataStream & stream, RestrictedValueTT<T, _min, _max> & value) {
	T t;
	stream >> t;
	value = t;
	return stream;
}