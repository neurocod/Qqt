//GroupBox.h by Kostya Kozachuck as neurocod - 11.03.2012 10:29:36
//BSD license https://github.com/neurocod/Qqt
#pragma once

class GroupBox: public WidgetPropertyRedirects {
	public:
		GroupBox();
		template<class T1>
		GroupBox(T1 t1) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
		}
		template<class T1, class T2>
		GroupBox(T1 t1, T2 t2) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
		}
		template<class T1, class T2, class T3>
		GroupBox(T1 t1, T2 t2, T3 t3) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
			p.process(*this, t3);
		}
		virtual ~GroupBox() {}

		void connectClicks(QObject*obj, const char * slot);
		//alignment: incompatible type, use redirect
		//PROPERTY_REDIRECTV(QGroupBox, Qt::Alignment, alignment, alignment, setAlignment);
		PROPERTY_REDIRECTV(QGroupBox, bool, checkable, isCheckable, setCheckable);
		PROPERTY_REDIRECTV(QGroupBox, bool, checked, isChecked, setChecked);
		PROPERTY_REDIRECTV(QGroupBox, bool, flat, isFlat, setFlat);
		PROPERTY_REDIRECT (QGroupBox, QString, title, title, setTitle);
		EMBED_QPOINTER_AND_CAST(QGroupBox)
	protected:
		void init();//C++11 ctor
		class CtorProcessor: public CtorProcessorT<GroupBox> {
			public:
				virtual void process(GroupBox&d, const QString & str) {
					switch(m_nStr) {
					case 0:
						d->setTitle(str);
						break;
					case 1:
						d->setToolTip(str);
						break;
					default:
						ASSERT(0);
					}
					m_nStr++;
				}
		};
};