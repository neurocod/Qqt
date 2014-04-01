//PushButton.h by Kostya Kozachuck as neurocod - 27.08.2011 21:20:17
//BSD license https://github.com/neurocod/Qqt
#pragma once

class PushButton: public QObject, public AbstractButtonPropertyRedirects {
	public:
		PushButton() {
			init();
		}
		template<class T1>
		PushButton(T1 t1) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
		}
		template<class T1, class T2>
		PushButton(T1 t1, T2 t2) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
		}
		template<class T1, class T2, class T3>
		PushButton(T1 t1, T2 t2, T3 t3) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
			p.process(*this, t3);
		}
		template<class T1, class T2, class T3, class T4>
		PushButton(T1 t1, T2 t2, T3 t3, T4 t4) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
			p.process(*this, t3);
			p.process(*this, t4);
		}
		virtual ~PushButton() {}
		QAction* _defaultAction()const { return m_defaultAction; }
		void PushButton::setDefaultAction(QAction *action);

		PROPERTY_REDIRECTV(PushButton, QAction*, defaultAction, _defaultAction, setDefaultAction);

		EMBED_QPOINTER_AND_CAST(QPushButton)
	protected:
		QPointer<QAction> m_defaultAction;

		void init();//C++11 ctor
		typedef CtorProcessorT<PushButton> CtorProcessor;
};