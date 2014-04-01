//PropertyRedirect.h by Kostya Kozachuck as neurocod - 28.08.2011 0:04:12
//BSD license https://github.com/neurocod/Qqt
#pragma once

template<
	typename TDestination,
	typename TValue,
	TValue (TDestination::*GetMethod)()const,
	void (TDestination::*SetMethod)(const TValue &)>
class PropertyRedirect: public SerizlizableToQDataStream<TValue> {
	public:
		virtual inline operator TValue()const {
			const TDestination* d2 = d;
			return (d2->*GetMethod)();
		}
		inline TValue operator=(const TValue & val) {
			TDestination* d2 = d;
			(d2->*SetMethod)(val);
			return (TValue)*this;
		}
		void init(TDestination *_d) {
			ASSERT(_d && !d);
			d = _d;
		}
		TDestination* destination()const { return d; }
	protected:
		QPointer<TDestination> d;
};

//'V' because set method uses value instead of const reference
template<
	typename TDestination,
	typename TValue,
	TValue (TDestination::*GetMethod)()const,
	void (TDestination::*SetMethod)(TValue val)>
class PropertyRedirectV: public SerizlizableToQDataStream<TValue> {
	public:
		inline operator TValue()const {
			const TDestination* d2 = d;
			return (d2->*GetMethod)();
		}
		inline TValue operator=(const TValue & val) {
			TDestination* d2 = d;
			(d2->*SetMethod)(val);
			return (TValue)*this;
		}
		void init(TDestination *_d) {
			ASSERT(_d && !d);
			d = _d;
		}
		TDestination* destination()const { return d; }
	protected:
		QPointer<TDestination> d;
};
//creates PropertyRedirectV<QAction, bool, &QAction::isVisible, &QAction::setVisible> visible;
#define PROPERTY_REDIRECTV(Class, Type, name, get, set) \
	PropertyRedirectV<Class, Type, &Class::get, &Class::set> name;
#define PROPERTY_REDIRECT(Class, Type, name, get, set) \
	PropertyRedirect<Class, Type, &Class::get, &Class::set> name;

template<typename T>
void* toVoidP(T t) {
	union {
		T t;
		void* v;
	} u;
	u.t = 0;
	u.v = (void*)1;
	ASSERT(u.t!=0);
	u.t = t;
	ASSERT(u.v!=0 && t!=0);
	return u.v;
}