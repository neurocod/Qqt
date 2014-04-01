//LineEdit.h by Kostya Kozachuck as neurocod - 11.03.2012 10:53:18
//BSD license https://github.com/neurocod/Qqt
#pragma once

class LineEdit: public WidgetPropertyRedirects {
	public:
		LineEdit(QWidget * parent = 0);
		virtual ~LineEdit() {}

		//PROPERTY_REDIRECTV(QLineEdit, acceptableInput : const bool
		PROPERTY_REDIRECTV(QLineEdit, Qt::Alignment, alignment, alignment, setAlignment);
		PROPERTY_REDIRECTV(QLineEdit, Qt::CursorMoveStyle, cursorMoveStyle, cursorMoveStyle, setCursorMoveStyle);
		PROPERTY_REDIRECTV(QLineEdit, int, cursorPosition, cursorPosition, setCursorPosition);
		PROPERTY_REDIRECTV(QLineEdit, QCompleter*, completer, completer, setCompleter);
		//PROPERTY_REDIRECTV(QLineEdit, displayText : const QString
		PROPERTY_REDIRECTV(QLineEdit, bool, dragEnabled, dragEnabled, setDragEnabled);
		PROPERTY_REDIRECTV(QLineEdit, QLineEdit::EchoMode, echoMode, echoMode, setEchoMode);
		PROPERTY_REDIRECTV(QLineEdit, bool, frame, hasFrame, setFrame);
		//PROPERTY_REDIRECTV(QLineEdit, hasSelectedText : const bool
		PROPERTY_REDIRECT (QLineEdit, QString, inputMask, inputMask, setInputMask);
		PROPERTY_REDIRECTV(QLineEdit, int, maxLength, maxLength, setMaxLength);
		PROPERTY_REDIRECTV(QLineEdit, bool, modified, isModified, setModified);
		PROPERTY_REDIRECT (QLineEdit, QString, placeholderText, placeholderText, setPlaceholderText);
		PROPERTY_REDIRECTV(QLineEdit, bool, readOnly, isReadOnly, setReadOnly);
		//PROPERTY_REDIRECTV(QLineEdit, redoAvailable : const bool
		//PROPERTY_REDIRECTV(QLineEdit, selectedText : const QString
		PROPERTY_REDIRECT (QLineEdit, QString, text, text, setText);
		//PROPERTY_REDIRECTV(QLineEdit, undoAvailable : const bool

		EMBED_QPOINTER_AND_CAST(QLineEdit)
	protected:
		void init();//C++11 ctor
};