//New.h by Kostya Kozachuck as neurocod - 27.09.2011 16:01:22
//BSD license https://github.com/neurocod/Qqt
#pragma once

template<class Class>
class New {
	private:
		Class*d;
	public:
		New() {
			d = new Class();
		}
		template<typename T0>
		New(T0 t0) {
			d = new Class(t0);
		}
		template<typename T0, typename T1>
		New(T0 t0, T1 t1) {
			d = new Class(t0, t1);
		}
		template<typename T0, typename T1, typename T2>
		New(T0 t0, T1 t1, T2 t2) {
			d = new Class(t0, t1, t2);
		}
		template<typename T0, typename T1, typename T2, typename T3>
		New(T0 t0, T1 t1, T2 t2, T3 t3) {
			d = new Class(t0, t1, t2, t3);
		}
		virtual ~New() {}
		Class* operator->() { return d; }
		const Class* operator->()const { return d; }
		operator Class* () { return d; }
		operator const Class* ()const { return d; }
};
template<class T>
T* autoNew(T*&var) {
	T*tmp = new T();
	var = tmp;
	return tmp;
}
template<class T>class QPointer;
template<class T>
T* autoNew(QPointer<T> &var) {
	T*tmp = new T();
	var = tmp;
	return tmp;
}