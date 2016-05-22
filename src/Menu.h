//Menu.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

class Menu: public WidgetPropertyRedirects {
	public:
		Menu();
		Menu(QMenu*other);
		Menu(QWidget*parent);
		Menu(const QString & title_, QWidget*parent = 0);
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