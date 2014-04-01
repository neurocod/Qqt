//AbstractSpinBoxPropertyRedirects.cpp by Kostya Kozachuck as neurocod - 11.03.2012 20:19:11
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "AbstractSpinBoxPropertyRedirects.h"

AbstractSpinBoxPropertyRedirects::AbstractSpinBoxPropertyRedirects() {
}
void AbstractSpinBoxPropertyRedirects::init(QAbstractSpinBox*d) {
	__super::init(d);
	accelerated.init(d);
	alignment.init(d);
	buttonSymbols.init(d);
	correctionMode.init(d);
	frame.init(d);
	keyboardTracking.init(d);
	readOnly.init(d);
	specialValueText.init(d);
	wrapping.init(d);
}