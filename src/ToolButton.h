//ToolButton.h by Kostya Kozachuck as neurocod - 28.08.2011 0:27:58
//BSD license https://github.com/neurocod/Qqt
#pragma once

class ToolButton: public AbstractButtonPropertyRedirects {
	public:
		ToolButton() {
			init();
		}
		template<class T1>
		ToolButton(T1 t1) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
		}
		template<class T1, class T2>
		ToolButton(T1 t1, T2 t2) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
		}
		template<class T1, class T2, class T3>
		ToolButton(T1 t1, T2 t2, T3 t3) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
			p.process(*this, t3);
		}
		template<class T1, class T2, class T3, class T4>
		ToolButton(T1 t1, T2 t2, T3 t3, T4 t4) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
			p.process(*this, t3);
			p.process(*this, t4);
		}
		virtual ~ToolButton() {}
		PROPERTY_REDIRECTV(QToolButton, Qt::ToolButtonStyle, toolButtonStyle, toolButtonStyle, setToolButtonStyle);
		PROPERTY_REDIRECTV(QToolButton, QAction*, defaultAction, defaultAction, setDefaultAction);

		EMBED_QPOINTER_AND_CAST(QToolButton)
	protected:
		void init();//C++11 ctor
		typedef CtorProcessorT<ToolButton> CtorProcessor;
};