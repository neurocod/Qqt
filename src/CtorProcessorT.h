//CtorProcessorT.h by Kostya Kozachuck as neurocod - 10.03.2012 20:05:49
//BSD license https://github.com/neurocod/Qqt
#pragma once

template<class T>
class CtorProcessorT {
	public:
		int m_nStr;
		CtorProcessorT() { m_nStr = 0; }
		template<class T2>
		void process(T&d, QPointer<T2> p) {
			T2* t = p;
			process(d, t);
		}
		void process(T&d, QObject*parent) {
			ASSERT(d->parent()==0);
			d->setParent(parent);
		}
		void process(T&d, QWidget*parent) {
			ASSERT(0==d->parentWidget());
			d->setParent(parent);
		}
		void process(T&d, const QImage& img) {
			d.set(img);
		}
		void process(T&d, const QIcon& img) {
			d.set(img);
		}
		void process(T&d, const QPixmap& img) {
			d.set(img);
		}
		void process(T&d, Qt::ShortcutContext c) {
			d->setShortcutContext(c);
		}
		void process(T&d, const QKeySequence & c) {
			d->setShortcut(c);
		}
		void process(T&d, const QString & str) {
			switch(m_nStr) {
			case 0:
				d->setText(str);
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