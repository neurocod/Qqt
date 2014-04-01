//SpinBox.h by Kostya Kozachuck as neurocod - 11.03.2012 20:16:58
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "AbstractSpinBoxPropertyRedirects.h"

class SpinBox: public AbstractSpinBoxPropertyRedirects {
	public:
		SpinBox(QWidget * parent = 0);
		virtual ~SpinBox() {}

		//PROPERTY_REDIRECTV(QSpinBox, const QString, cleanText
		PROPERTY_REDIRECTV(QSpinBox, int, maximum, maximum, setMaximum);
		PROPERTY_REDIRECTV(QSpinBox, int, minimum, minimum, setMinimum);
		PROPERTY_REDIRECT (QSpinBox, QString, prefix, prefix, setPrefix);
		PROPERTY_REDIRECTV(QSpinBox, int, singleStep, singleStep, setSingleStep);
		PROPERTY_REDIRECT (QSpinBox, QString, suffix, suffix, setSuffix);
		PROPERTY_REDIRECTV(QSpinBox, int, value, value, setValue);
		EMBED_QPOINTER_AND_CAST(QSpinBox)
	protected:
		void init();//C++11 ctor
};