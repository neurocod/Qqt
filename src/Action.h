//Action.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

//TODO: C++11 use enum NoType { NoTypeValue }; and only one ctor with default arguments = NoTypeValue,
//and move CtorProcessor to that ctor
class Action {
	public:
		static void insertToBegin(QWidget*w, QAction*act);
		static void insertToBegin(QWidget*w, const QList<QAction*> & lact);
		void operator=(QAction*a);
		Action() {}//this ctor is to use operator= later
		Action(QObject * parent);
		Action(QAction*act);
		//all template ctors parameters need either QIcon, QString for text and QString fot tooltip in any order
		template<class T1>
		Action(T1 p1);
		template<class T1, class T2>
		Action(T1 p1, const T2 & p2);
		template<class T1, class T2, class T3>
		Action(T1 p1, const T2 & p2, const T3 & p3);
		template<class T1, class T2, class T3, class T4>
		Action(T1 p1, const T2 & p2, const T3 & p3, const T4 & p4);
		virtual ~Action() {}
		void connectClicks(QObject*obj, const char* slot, Qt::ConnectionType conn=Qt::AutoConnection);

		PROPERTY_REDIRECTV(QAction, bool, autoRepeat, autoRepeat, setAutoRepeat);
		PROPERTY_REDIRECTV(QAction, bool, checkable, isCheckable, setCheckable);
		PROPERTY_REDIRECTV(QAction, bool, checked, isChecked, setChecked);
		PROPERTY_REDIRECTV(QAction, bool, enabled, isEnabled, setEnabled);
		PROPERTY_REDIRECTV(QAction, bool, iconVisibleInMenu, isIconVisibleInMenu, setIconVisibleInMenu);
		PROPERTY_REDIRECTV(QAction, bool, visible, isVisible, setVisible);
		PROPERTY_REDIRECTV(QAction, bool, separator, isSeparator, setSeparator);
		PROPERTY_REDIRECTV(QAction, QAction::MenuRole, menuRole, menuRole, setMenuRole);
		PROPERTY_REDIRECTV(QAction, QAction::Priority, priority, priority, setPriority);
		PROPERTY_REDIRECTV(QAction, Qt::ShortcutContext, shortcutContext, shortcutContext, setShortcutContext);
		PROPERTY_REDIRECT (QAction, QKeySequence, shortcut, shortcut, setShortcut);
		PROPERTY_REDIRECT (QAction, QFont, font, font, setFont);
		PROPERTY_REDIRECT (QAction, QIcon, icon, icon, setIcon);
		PROPERTY_REDIRECT (QAction, QString, iconText, iconText, setIconText);
		PROPERTY_REDIRECT (QAction, QString, statusTip, statusTip, setStatusTip);
		PROPERTY_REDIRECT (QAction, QString, text, text, setText);
		PROPERTY_REDIRECT (QAction, QString, toolTip, toolTip, setToolTip);
		PROPERTY_REDIRECT (QAction, QString, whatsThis, whatsThis, setWhatsThis);

		void set(const QIcon & i) { d->setIcon(i); }
		void operator=(const QKeySequence& _shortcut) { d->setShortcut(_shortcut); }
		EMBED_QPOINTER_AND_CAST(QAction);
	protected:
		void init(QAction*_d=0);//C++11 ctor
	private:
		typedef CtorProcessorT<Action> CtorProcessor;
};
template<class T1>
Action::Action(T1 p1) {
	init();
	CtorProcessor p;
	p.process(*this, p1);
}
template<class T1, class T2>
Action::Action(T1 p1, const T2 & p2) {
	init();
	CtorProcessor p;
	p.process(*this, p1);
	p.process(*this, p2);
}
template<class T1, class T2, class T3>
Action::Action(T1 p1, const T2 & p2, const T3 & p3) {
	init();
	CtorProcessor p;
	p.process(*this, p1);
	p.process(*this, p2);
	p.process(*this, p3);
}
template<class T1, class T2, class T3, class T4>
Action::Action(T1 p1, const T2 & p2, const T3 & p3, const T4 & p4) {
	init();
	CtorProcessor p;
	p.process(*this, p1);
	p.process(*this, p2);
	p.process(*this, p3);
	p.process(*this, p4);
}