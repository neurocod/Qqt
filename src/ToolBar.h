//ToolBar.h by Kostya Kozachuck as neurocod - 08.11.2011 1:25:55
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "RotatableToolBar.h"

class ToolBar: public WidgetPropertyRedirects {
	public:
		void operator=(QToolBar*b);
		ToolBar(QWidget*parent = 0);
		ToolBar(QString title, QWidget*parent);
		virtual ~ToolBar() {}

		ToolBar & operator<<(QWidget*w);
		ToolBar & operator<<(QAction*a);
		ToolBar & operator<<(const QList<QAction*>& li);
		PROPERTY_REDIRECTV(QToolBar, Qt::ToolBarAreas, allowedAreas, allowedAreas, setAllowedAreas);
		PROPERTY_REDIRECTV(QToolBar, bool, floatable, isFloatable, setFloatable);
		//PROPERTY_REDIRECTV(QToolBar, const bool floating, floating, setFloating);
		PROPERTY_REDIRECT (QToolBar, QSize, iconSize, iconSize, setIconSize);
		PROPERTY_REDIRECTV(QToolBar, bool, movable, isMovable, setMovable);
		PROPERTY_REDIRECTV(QToolBar, Qt::Orientation, orientation, orientation, setOrientation);
		PROPERTY_REDIRECTV(QToolBar, Qt::ToolButtonStyle, toolButtonStyle, toolButtonStyle, setToolButtonStyle);

		EMBED_QPOINTER_AND_CAST(RotatableToolBar)
	protected:
		void init(QWidget*parent);
};