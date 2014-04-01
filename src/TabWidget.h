//TabWidget.h by Kostya Kozachuck as neurocod - 08.12.2012 13:28:55
//BSD license https://github.com/neurocod/Qqt
#pragma once

class TabWidget: public WidgetPropertyRedirects {
	public:
		TabWidget(QWidget*parent = 0);
		virtual ~TabWidget() {}

		//count : const int
		PROPERTY_REDIRECTV(QTabWidget, int, currentIndex, currentIndex, setCurrentIndex);
		PROPERTY_REDIRECTV(QTabWidget, bool, documentMode, documentMode, setDocumentMode);
		PROPERTY_REDIRECTV(QTabWidget, Qt::TextElideMode, elideMode, elideMode, setElideMode);
		PROPERTY_REDIRECT (QTabWidget, QSize, iconSize, iconSize, setIconSize);
		PROPERTY_REDIRECTV(QTabWidget, bool, movable, isMovable, setMovable);
		PROPERTY_REDIRECTV(QTabWidget, QTabWidget::TabPosition, tabPosition, tabPosition, setTabPosition);
		PROPERTY_REDIRECTV(QTabWidget, QTabWidget::TabShape, tabShape, tabShape, setTabShape);
		PROPERTY_REDIRECTV(QTabWidget, bool, tabsClosable, tabsClosable, setTabsClosable);
		PROPERTY_REDIRECTV(QTabWidget, bool, usesScrollButtons, usesScrollButtons, setUsesScrollButtons);

		EMBED_QPOINTER_AND_CAST(QTabWidget)
	protected:
		void init(QWidget*parent);
};