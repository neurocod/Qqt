//WidgetPropertyRedirects.h by Kostya Kozachuck as neurocod - 16.09.2011 2:05:57
//BSD license https://github.com/neurocod/Qqt
#pragma once

class WidgetPropertyRedirects: public ObjectPropertyRedirects {
	public:
		WidgetPropertyRedirects();
		virtual ~WidgetPropertyRedirects() {}
		void init(QWidget*w);

		PROPERTY_REDIRECTV(QWidget, int, maximumWidth, maximumWidth, setMaximumWidth);
		PROPERTY_REDIRECTV(QWidget, bool, acceptDrops, acceptDrops, setAcceptDrops);
		PROPERTY_REDIRECT (QWidget, QString, accessibleDescription, accessibleDescription, setAccessibleDescription);
		PROPERTY_REDIRECT (QWidget, QString, accessibleName, accessibleName, setAccessibleName);
		PROPERTY_REDIRECTV(QWidget, bool, autoFillBackground, autoFillBackground, setAutoFillBackground);
		PROPERTY_REDIRECT (QWidget, QSize, baseSize, baseSize, setBaseSize);
		//PROPERTY_REDIRECTV(QWidget, const QRect, childrenRect, childrenRect, setChildrenRect);
		//PROPERTY_REDIRECTV(QWidget, const QRegion, childrenRegion
		PROPERTY_REDIRECTV(QWidget, Qt::ContextMenuPolicy, contextMenuPolicy, contextMenuPolicy, setContextMenuPolicy);
		PROPERTY_REDIRECT (QWidget, QCursor, cursor, cursor, setCursor);
		PROPERTY_REDIRECTV(QWidget, bool, enabled, isEnabled, setEnabled);
		//PROPERTY_REDIRECTV(QWidget, const bool, focus
		PROPERTY_REDIRECTV(QWidget, Qt::FocusPolicy, focusPolicy, focusPolicy, setFocusPolicy);
		PROPERTY_REDIRECTV(QWidget, const QFont &, font, font, setFont);
		//PROPERTY_REDIRECTV(QWidget, const QRect, frameGeometry
		//PROPERTY_REDIRECTV(QWidget, const QSize, frameSize
		//PROPERTY_REDIRECTV(QWidget, const bool, fullScreen
		PROPERTY_REDIRECTV(QWidget, const QRect &, geometry, geometry, setGeometry);
		//PROPERTY_REDIRECTV(QWidget, const int, height
		PROPERTY_REDIRECTV(QWidget, Qt::InputMethodHints, inputMethodHints, inputMethodHints, setInputMethodHints);
		//PROPERTY_REDIRECTV(QWidget, const bool, isActiveWindow
		PROPERTY_REDIRECTV(QWidget, Qt::LayoutDirection, layoutDirection, layoutDirection, setLayoutDirection);
		PROPERTY_REDIRECT (QWidget, QLocale, locale, locale, setLocale);
		//PROPERTY_REDIRECTV(QWidget, const bool, maximized
		PROPERTY_REDIRECTV(QWidget, int, maximumHeight, maximumHeight, setMaximumHeight);
		PROPERTY_REDIRECT (QWidget, QSize, maximumSize, maximumSize, setMaximumSize);
		//PROPERTY_REDIRECTV(QWidget, const bool, minimized
		PROPERTY_REDIRECTV(QWidget, int, minimumHeight, minimumHeight, setMinimumHeight);
		PROPERTY_REDIRECT (QWidget, QSize, minimumSize, minimumSize, setMinimumSize);
		//PROPERTY_REDIRECTV(QWidget, const QSize, minimumSizeHint
		PROPERTY_REDIRECTV(QWidget, int, minimumWidth, minimumWidth, setMinimumWidth);
		//PROPERTY_REDIRECTV(QWidget, const bool, modal
		PROPERTY_REDIRECTV(QWidget, bool, mouseTracking, hasMouseTracking, setMouseTracking);
		//PROPERTY_REDIRECTV(QWidget, const QRect, normalGeometry
		PROPERTY_REDIRECTV(QWidget, const QPalette &, palette, palette, setPalette);
		PROPERTY_REDIRECT (QWidget, QPoint, pos, pos, move);
		//PROPERTY_REDIRECTV(QWidget, const QRect, rect
		PROPERTY_REDIRECT (QWidget, QSize, size, size, resize);
		//PROPERTY_REDIRECTV(QWidget, const QSize, sizeHint
		PROPERTY_REDIRECT (QWidget, QSize, sizeIncrement, sizeIncrement, setSizeIncrement);
		PROPERTY_REDIRECTV(QWidget, QSizePolicy, sizePolicy, sizePolicy, setSizePolicy);
		PROPERTY_REDIRECT (QWidget, QString, statusTip, statusTip, setStatusTip);
		PROPERTY_REDIRECT (QWidget, QString, styleSheet, styleSheet, setStyleSheet);
		PROPERTY_REDIRECT(QWidget, QString, toolTip, toolTip, setToolTip);
		PROPERTY_REDIRECTV(QWidget, bool, updatesEnabled, updatesEnabled, setUpdatesEnabled);
		PROPERTY_REDIRECTV(QWidget, bool, visible, isVisible, setVisible);
		PROPERTY_REDIRECT (QWidget, QString, whatsThis, whatsThis, setWhatsThis);
		//PROPERTY_REDIRECTV(QWidget, const int, width
		PROPERTY_REDIRECT (QWidget, QString, windowFilePath, windowFilePath, setWindowFilePath);
		PROPERTY_REDIRECTV(QWidget, Qt::WindowFlags, windowFlags, windowFlags, setWindowFlags);
		PROPERTY_REDIRECT (QWidget, QIcon, windowIcon, windowIcon, setWindowIcon);
		PROPERTY_REDIRECT(QWidget, QString, windowIconText, windowIconText, setWindowIconText);
		PROPERTY_REDIRECTV(QWidget, Qt::WindowModality, windowModality, windowModality, setWindowModality);
		PROPERTY_REDIRECTV(QWidget, bool, windowModified, isWindowModified, setWindowModified);
		PROPERTY_REDIRECTV(QWidget, qreal, windowOpacity, windowOpacity, setWindowOpacity);
		PROPERTY_REDIRECT(QWidget, QString, windowTitle, windowTitle, setWindowTitle);
		//PROPERTY_REDIRECTV(QWidget, const int, x
		//PROPERTY_REDIRECTV(QWidget, const int, y
};