//MenuButton.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

class MenuButton {
	protected:
		ToolButton m_btn;
		Menu m_menu;//watch creation order!
		bool m_bFirst;
	public:
		MenuButton(QWidget*parent=0): m_btn(parent), m_menu(m_btn), m_bFirst(true)  {
			m_btn->setMenu(m_menu);
			m_btn->setPopupMode(QToolButton::MenuButtonPopup);
		}
		operator QToolButton*() { return m_btn; }
		QToolButton* operator->() { return m_btn; }
		MenuButton& operator << (QAction*act);
		MenuButton& operator << (const QList<QAction *> & li);
};