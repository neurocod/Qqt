//MsgBox.h by Kostya Kozachuck as neurocod - 23.12.2011 6:34:32
//BSD license https://github.com/neurocod/Qqt
#pragma once

class MsgBox: public QMessageBox {
	public:
		typedef CtorProcessorT<MsgBox> CtorProcessor;
		virtual ~MsgBox() {}
		MsgBox() {
			init();
		}
		template<class T1>
		MsgBox(T1 t1) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
		}
		template<class T1, class T2>
		MsgBox(T1 t1, T2 t2) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
		}
		template<class T1, class T2, class T3>
		MsgBox(T1 t1, T2 t2, T3 t3) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
			p.process(*this, t3);
		}

		typedef QMessageBox::StandardButton StandardButton;
		typedef QMessageBox::StandardButton Btn;
		typedef QMessageBox::StandardButtons StandardButtons;

		PROPERTY_REDIRECT (QMessageBox, QString, detailedText, detailedText, setDetailedText);
		PROPERTY_REDIRECTV(QMessageBox, Icon, icon, icon, setIcon);
		PROPERTY_REDIRECT (QMessageBox, QPixmap, iconPixmap, iconPixmap, setIconPixmap);
		PROPERTY_REDIRECT (QMessageBox, QString, informativeText, informativeText, setInformativeText);
		PROPERTY_REDIRECTV(QMessageBox, StandardButtons, standardButtons, standardButtons, setStandardButtons);
		PROPERTY_REDIRECT (QMessageBox, QString, text, text, setText);
		PROPERTY_REDIRECTV(QMessageBox, Qt::TextFormat, textFormat, textFormat, setTextFormat);

		//StandardButtons buttons;
		int m_nStringParam;

		void set(QWidget * _parent) {
			setParent(_parent);
		}
		void set(QString str) {
			if(m_nStringParam==0) {
				text = str;
			} else {
				setWindowTitle(text);
				text = str;
			}
			m_nStringParam++;
			if(m_nStringParam>2) {
				ASSERT(0);
				return;
			}
		}
		void set(QMessageBox::StandardButtons _buttons) {
			standardButtons = _buttons;
		}
		void set(QMessageBox::Icon ico) {
			icon = ico;
		}
		void set(QMessageBox::StandardButton _defaultButton) {
			setDefaultButton(_defaultButton);
		}
		Btn execReturnBtn() {
			if(exec()==-1)
				return Cancel;
			return standardButton(clickedButton());
		}

		QMessageBox* operator->() { return this; }
	private:
		void init();//C++11
};
//________________________________________________________________
MsgBox::Btn msgBox(QString t1);

//S means toString() first param
template<class T1>
MsgBox::Btn msgBoxS(T1 t1) {
	return msgBox(toString(t1));
}

template<class T1, class T2>
MsgBox::Btn msgBox(T1 t1, T2 t2) {
	MsgBox box;
	box.icon = MsgBox::Information;
	box.set(t1);
	box.set(t2);
	return box.execReturnBtn();
}
template<class T1, class T2, class T3>
MsgBox::Btn msgBox(T1 t1, T2 t2, T3 t3) {
	MsgBox box;
	box.icon = MsgBox::Information;
	box.set(t1);
	box.set(t2);
	box.set(t3);
	return box.execReturnBtn();
}