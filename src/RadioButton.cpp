//RadioButton.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "RadioButton.h"

RadioButton::RadioButton() {
	init();
}
void RadioButton::init() {
	d = new QRadioButton();
	__super::init(d);
}