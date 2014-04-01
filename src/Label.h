//Label.h by Kostya Kozachuck as neurocod - 29.02.2012 1:30:10
//BSD license https://github.com/neurocod/Qqt
#pragma once

class Label: public WidgetPropertyRedirects {
	public:
		Label();
		template<class T1>
		Label(T1 t1) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
		}
		template<class T1, class T2>
		Label(T1 t1, T2 t2) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
		}
		template<class T1, class T2, class T3>
		Label(T1 t1, T2 t2, T3 t3) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
			p.process(*this, t3);
		}
		void set(const QImage & img);
		void set(const QPixmap& img);
		void set(const QString& str);
		void operator=(const QImage & img);
		void operator=(const QPixmap& img);
		void operator=(const QString& str);

		PROPERTY_REDIRECTV(QLabel, Qt::Alignment, alignment, alignment, setAlignment);
		PROPERTY_REDIRECTV(QLabel, int, indent, indent, setIndent);
		PROPERTY_REDIRECTV(QLabel, int, margin, margin, setMargin);
		PROPERTY_REDIRECTV(QLabel, bool, openExternalLinks, openExternalLinks, setOpenExternalLinks);
		//PROPERTY_REDIRECTV(QLabel, QPixmap, pixmap, setPixmap, pixmap);
		PROPERTY_REDIRECTV(QLabel, bool, scaledContents, hasScaledContents, setScaledContents);
		//selectedText : const QString
		PROPERTY_REDIRECT (QLabel, QString, text, text, setText);
		PROPERTY_REDIRECTV(QLabel, Qt::TextFormat, textFormat, textFormat, setTextFormat);
		PROPERTY_REDIRECTV(QLabel, Qt::TextInteractionFlags, textInteractionFlags, textInteractionFlags, setTextInteractionFlags);
		PROPERTY_REDIRECTV(QLabel, bool, wordWrap, wordWrap, setWordWrap);

		EMBED_QPOINTER_AND_CAST(QLabel)
	protected:
		void init();//C++11 ctor
		typedef CtorProcessorT<Label> CtorProcessor;
};