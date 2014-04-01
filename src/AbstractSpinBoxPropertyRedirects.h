//AbstractSpinBoxPropertyRedirects.h by Kostya Kozachuck as neurocod - 11.03.2012 20:19:10
//BSD license https://github.com/neurocod/Qqt
#pragma once

class AbstractSpinBoxPropertyRedirects: public WidgetPropertyRedirects {
	public:
		AbstractSpinBoxPropertyRedirects();
		virtual ~AbstractSpinBoxPropertyRedirects() {}

		PROPERTY_REDIRECTV(QAbstractSpinBox, bool, accelerated, isAccelerated, setAccelerated);
		//PROPERTY_REDIRECTV(QAbstractSpinBox, const bool, acceptableInput, acceptableInput);
		PROPERTY_REDIRECTV(QAbstractSpinBox, Qt::Alignment, alignment, alignment, setAlignment);
		PROPERTY_REDIRECTV(QAbstractSpinBox, QAbstractSpinBox::ButtonSymbols, buttonSymbols, buttonSymbols, setButtonSymbols);
		PROPERTY_REDIRECTV(QAbstractSpinBox, QAbstractSpinBox::CorrectionMode, correctionMode, correctionMode, setCorrectionMode);
		PROPERTY_REDIRECTV(QAbstractSpinBox, bool, frame, hasFrame, setFrame);
		PROPERTY_REDIRECTV(QAbstractSpinBox, bool, keyboardTracking, keyboardTracking, setKeyboardTracking);
		PROPERTY_REDIRECTV(QAbstractSpinBox, bool, readOnly, isReadOnly, setReadOnly);
		PROPERTY_REDIRECT (QAbstractSpinBox, QString, specialValueText, specialValueText, setSpecialValueText);
		//PROPERTY_REDIRECTV(QAbstractSpinBox, const QString, text);
		PROPERTY_REDIRECTV(QAbstractSpinBox, bool, wrapping, wrapping, setWrapping);
	protected:
		void init(QAbstractSpinBox*d);//C++11 ctor
};