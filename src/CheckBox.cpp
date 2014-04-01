//CheckBox.cpp by Kostya Kozachuck as neurocod - 16.09.2011 1:08:43
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "CheckBox.h"

void CheckBox::init() {
	d = new QCheckBox();
	AbstractButtonPropertyRedirects::init(d);
	checkState.init(d);
}