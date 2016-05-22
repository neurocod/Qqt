//RestrictedValueT.h by Kostya Kozachuck as neurocod - 23.02.2013 12:37:00
#pragma once

template<class T>
class RestrictedValueT {
	protected:
		T _min;
		T _v;
		T _max;
	public:
		RestrictedValueT(T tMin, T tMax) {
			_min = tMin;
			_max = tMax;
			_v = (tMin + tMax)/2;
		}
		RestrictedValueT(T tMin, T t, T tMax) {
			_min = tMin;
			_max = tMax;
			*this = t;
			ASSERT(t>=tMin && t<=tMax);
		}
		T min()const { return _min; }
		T max()const { return _max; }
		T operator=(T t) {
			_v = qBound(_min, t, _max);
			return _v;
		}
		T operator=(const QVariant & v) {
			T t = v.value<T>();
			*this = t;
			return _v;
		}
		operator T()const {
			return _v;
		}
		operator QVariant()const {
			return QVariant(_v);
		}
		template<class Gui>
		void setTo(Gui*gui)const {
			gui->setRange(_min, _max);
			gui->setValue(_v);
		}
		template<class Gui>
		void setTo(Gui&gui)const {
			gui->setRange(_min, _max);
			gui->setValue(_v);
		}
		template<class Gui>
		void update(bool toGui, Gui & gui) {
			if(toGui) {
				setTo(gui);
			} else {
				*this = gui->value();
			}
		}
};
template<class T>
QDataStream & operator<<(QDataStream & stream, const RestrictedValueT<T> & value) {
	stream << (T)value;
	return stream;
}
template<class T>
QDataStream & operator>>(QDataStream & stream, RestrictedValueT<T> & value) {
	T t;
	stream >> t;
	value = t;
	return stream;
}