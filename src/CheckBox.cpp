//CheckBox.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "CheckBox.h"

void CheckBox::init() {
	d = new QCheckBox();
	AbstractButtonPropertyRedirects::init(d);
	checkState.init(d);
}