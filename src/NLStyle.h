//NLStyle.h by Kostya Kozachuck as neurocod - 01.10.2009 21:31:31
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "CtorProcessorT.h"
#include "Object.h"
#include "FormLayout.h"
#include "CompactHBoxLayout.h"
#include "CompactVBoxLayout.h"
#include "WidgetPropertyRedirects.h"
#include "MsgBox.h"
#include "AbstractButtonPropertyRedirects.h"
#include "PushButton.h"
#include "ToolButton.h"
#include "CheckBox.h"
#include "Menu.h"
#include "Splitter.h"
#include "Widget.h"
#include "ToolBar.h"
#include "Action.h"
#include "Label.h"
#include "LineEdit.h"
#include "ButtonGroup.h"
#include "RadioButton.h"
#include "ComboBox.h"
#include "GroupBox.h"
#include "SpinBox.h"
#include "ProgressBar.h"
#include "TabWidget.h"
QPixmap pixmapFromText(QString text, int w, int h, QColor clrText);
QPixmap pixmapFromText(QString text, int w, int h, QColor clrText, int nFontSize);
//________________________________________________________________
class CompactTextEdit: public QTextEdit {
	MAYBE_SUPER(QTextEdit)
	public:
		CompactTextEdit(QWidget*parent);
		virtual ~CompactTextEdit() {}
		virtual QSize sizeHint()const;
		virtual QSize minimumSizeHint()const;
};
class CompactLineEdit: public QLineEdit {
	MAYBE_SUPER(QLineEdit)
	public:
		CompactLineEdit(QWidget*parent=0);
		virtual ~CompactLineEdit() {}
		virtual QSize sizeHint()const;
		virtual QSize minimumSizeHint()const;
};
class NLStyle {
	public:
		static LPCSTR s_strDateTimeFormatFull;
};