//RadioButton.cpp by Kostya Kozachuck as neurocod - 11.03.2012 6:50:31
#include "pch.h"
#include "RadioButton.h"

RadioButton::RadioButton() {
	init();
}
void RadioButton::init() {
	d = new QRadioButton();
	__super::init(d);
}