//AbstractButtonPropertyRedirects.h by Kostya Kozachuck as neurocod - 16.09.2011 1:16:37
//BSD license https://github.com/neurocod/Qqt
#pragma once

class AbstractButtonPropertyRedirects: public WidgetPropertyRedirects {
	public:
		void connectClicks(QObject*obj, const char* slot, Qt::ConnectionType type = Qt::AutoConnection);
		void init(QAbstractButton*d);

		PROPERTY_REDIRECT (QAbstractButton, QString, text, text, setText);
		PROPERTY_REDIRECT (QAbstractButton, QIcon, icon, icon, setIcon);
		PROPERTY_REDIRECTV(QAbstractButton, bool, checked, isChecked, setChecked);

		void set(const QIcon & i);
};