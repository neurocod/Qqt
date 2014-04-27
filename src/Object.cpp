//Object.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "Object.h"

Object::Object(QObject*parent) {
	d = new QObject(parent);
	__super::init(d);
}

void ObjectPropertyRedirects::init(QObject*d) {
	objectName.init(d);
}