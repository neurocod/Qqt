//AbstractButtonPropertyRedirects.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

class AbstractButtonPropertyRedirects: public WidgetPropertyRedirects {
	public:
		void set(const QIcon & i);
		void connectClicks(QObject*obj, const char* slot, Qt::ConnectionType type = Qt::AutoConnection);
		template<class T1, class T2>
		void connectClicksT(T1*receiver, const T2 slot, Qt::ConnectionType type = Qt::AutoConnection) {
			QAbstractButton* btn = icon.destination();
			QObject::connect(btn, &QAbstractButton::clicked, receiver, slot, type);
		}
		void addShortcutToTooltip();
		PROPERTY_REDIRECTV(QAbstractButton, bool, autoExclusive, autoExclusive, setAutoExclusive);
		PROPERTY_REDIRECTV(QAbstractButton, bool, autoRepeat, autoRepeat, setAutoRepeat)
		PROPERTY_REDIRECTV(QAbstractButton, int, autoRepeatDelay, autoRepeatDelay, setAutoRepeatDelay);
		PROPERTY_REDIRECTV(QAbstractButton, int, autoRepeatInterval, autoRepeatInterval, setAutoRepeatInterval);
		PROPERTY_REDIRECTV(QAbstractButton, bool, checkable, isCheckable, setCheckable);
		PROPERTY_REDIRECTV(QAbstractButton, bool, checked, isChecked, setChecked);
		PROPERTY_REDIRECTV(QAbstractButton, bool, down, isDown, setDown);
		PROPERTY_REDIRECT (QAbstractButton, QIcon, icon, icon, setIcon);
		PROPERTY_REDIRECT (QAbstractButton, QSize, iconSize, iconSize, setIconSize);
		PROPERTY_REDIRECT (QAbstractButton, QKeySequence, shortcut, shortcut, setShortcut);
		PROPERTY_REDIRECT (QAbstractButton, QString, text, text, setText);
		void init(QAbstractButton*d);
};