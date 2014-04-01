//Widget.h by Kostya Kozachuck as neurocod - 16.09.2011 18:53:44
//BSD license https://github.com/neurocod/Qqt
#pragma once

template<class T>
T* parentT(const QObject*_p) {
	if(!_p)
		return 0;
	QObject*p = _p->parent();
	while (p) {
		if (T*t = qobject_cast<T*>(p))
			return t;
		p = p->parent();
	}
	return 0;
}
class Widget: public WidgetPropertyRedirects {
	public:
		Widget(QWidget*parent=0);
		virtual ~Widget() {}

		template<class T>
		static T* findParentWidgetByClass(QWidget*w) {
			for(; w; w = w->parentWidget()) {
				T*t = qobject_cast<T*>(w);
				if(t)
					return t;
			}
			return 0;
		}

		EMBED_QPOINTER_AND_CAST(QWidget)
};