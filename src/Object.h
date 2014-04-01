//Object.h by Kostya Kozachuck as neurocod - 11.03.2012 21:18:52
//BSD license https://github.com/neurocod/Qqt
#pragma once

class ObjectPropertyRedirects {
	public:
		ObjectPropertyRedirects() {}
		virtual ~ObjectPropertyRedirects() {}

		PROPERTY_REDIRECT(QObject, QString, objectName, objectName, setObjectName);
	protected:
		void init(QObject*d);
};

class Object: public ObjectPropertyRedirects {
	public:
		Object(QObject*parent = 0);
		virtual ~Object() {}
		EMBED_QPOINTER_AND_CAST(QObject)
};