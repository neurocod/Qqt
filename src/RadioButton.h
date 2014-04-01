//RadioButton.h by Kostya Kozachuck as neurocod - 11.03.2012 6:50:31
//BSD license https://github.com/neurocod/Qqt
#pragma once

class RadioButton: public AbstractButtonPropertyRedirects {
	public:
		RadioButton();
		template<class T1>
		RadioButton(T1 t1) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
		}
		template<class T1, class T2>
		RadioButton(T1 t1, T2 t2) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
		}
		virtual ~RadioButton() {}

		EMBED_QPOINTER_AND_CAST(QRadioButton)
	protected:
		void init();

		typedef CtorProcessorT<RadioButton> CtorProcessor;
};