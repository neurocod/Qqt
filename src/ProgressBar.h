//ProgressBar.h by Kostya Kozachuck as neurocod - 08.05.2012 14:21:12
//BSD license https://github.com/neurocod/Qqt
#pragma once

class ProgressBar: public WidgetPropertyRedirects {
	public:
		ProgressBar(QWidget * parent = 0);
		virtual ~ProgressBar() {}

		PROPERTY_REDIRECTV(QProgressBar, Qt::Alignment, alignment, alignment, setAlignment);
		PROPERTY_REDIRECT (QProgressBar, QString, format, format, setFormat);
		PROPERTY_REDIRECTV(QProgressBar, bool, invertedAppearance, invertedAppearance, setInvertedAppearance);
		PROPERTY_REDIRECTV(QProgressBar, int, maximum, maximum, setMaximum);
		PROPERTY_REDIRECTV(QProgressBar, int, minimum, minimum, setMinimum);
		PROPERTY_REDIRECTV(QProgressBar, Qt::Orientation, orientation, orientation, setOrientation);
		//PROPERTY_REDIRECTV(QProgressBar, const QString, text);
		PROPERTY_REDIRECTV(QProgressBar, QProgressBar::Direction, textDirection, textDirection, setTextDirection);
		PROPERTY_REDIRECTV(QProgressBar, bool, textVisible, isTextVisible, setTextVisible);
		PROPERTY_REDIRECTV(QProgressBar, int, value, value, setValue);

		EMBED_QPOINTER_AND_CAST(QProgressBar)
	protected:
		void init();//C++11 ctor
};