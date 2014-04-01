//CheckBox.h by Kostya Kozachuck as neurocod - 16.09.2011 1:08:43
//BSD license https://github.com/neurocod/Qqt
#pragma once

class CheckBox: public AbstractButtonPropertyRedirects {
	public:
		CheckBox() { init(); }
		template<class T1>
		CheckBox(T1 t1) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
		}
		template<class T1, class T2>
		CheckBox(T1 t1, T2 t2) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
		}
		template<class T1, class T2, class T3>
		CheckBox(T1 t1, T2 t2, T3 t3) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
			p.process(*this, t3);
		}
		virtual ~CheckBox() {}
		PROPERTY_REDIRECTV(QCheckBox, bool, tristate, isTristate, setTristate);
		PROPERTY_REDIRECTV(QCheckBox, Qt::CheckState, checkState, checkState, setCheckState);

		EMBED_QPOINTER_AND_CAST(QCheckBox)
	protected:
		void init();//C++11 ctor
		typedef CtorProcessorT<CheckBox> CtorProcessor;
	private:
		void operator=(CheckBox&);//C++11 =delete
};