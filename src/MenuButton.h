//MenuButton.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

class MenuButton {
	protected:
		ToolButton _btn;
		Menu _menu;//watch creation order!
		bool _first;
	public:
		MenuButton(QWidget*parent = 0): _btn(parent), _menu(_btn), _first(true) {
			_btn->setMenu(_menu);
			_btn->setPopupMode(QToolButton::MenuButtonPopup);
		}
		operator QToolButton*() { return _btn; }
		QToolButton* operator->() { return _btn; }
		MenuButton& operator << (QAction*act);
		MenuButton& operator << (const QList<QAction *> & li);
};