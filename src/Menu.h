//Menu.h by Kostya Kozachuck as neurocod - 16.09.2011 2:01:02
//BSD license https://github.com/neurocod/Qqt
#pragma once

class Menu: public WidgetPropertyRedirects {
	public:
		Menu();
		Menu(QMenu*other);
		Menu(QWidget*parent);
		Menu(QString title, QWidget*parent=0);
		virtual ~Menu() {}
		void showUnder(QWidget*w);
		Menu& operator<<(QAction*act);

		PROPERTY_REDIRECT(QMenu, QIcon, icon, icon, setIcon);
		PROPERTY_REDIRECT(QMenu, QString, title, title, setTitle);
		PROPERTY_REDIRECTV(QMenu, bool, tearOffEnabled, isTearOffEnabled, setTearOffEnabled);
		PROPERTY_REDIRECTV(QMenu, bool, separatorsCollapsible, separatorsCollapsible, setSeparatorsCollapsible);

		EMBED_QPOINTER_AND_CAST(QMenu)
	protected:
		void init(QWidget*parent, QMenu*m);
};