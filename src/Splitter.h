//Splitter.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

class Splitter: public WidgetPropertyRedirects {
	public:
		Splitter(QWidget * parent = 0);
		Splitter(Qt::Orientation orientation, QWidget * parent = 0);
		virtual ~Splitter() {}
		PROPERTY_REDIRECTV(QSplitter, Qt::Orientation, orientation, orientation, setOrientation);
		PROPERTY_REDIRECTV(QSplitter, bool, childrenCollapsible, childrenCollapsible, setChildrenCollapsible);
		PROPERTY_REDIRECTV(QSplitter, int, handleWidth, handleWidth, setHandleWidth);
		PROPERTY_REDIRECTV(QSplitter, bool, opaqueResize, opaqueResize, setOpaqueResize);
		PROPERTY_REDIRECT (QSplitter, QList<int>, sizes, sizes, setSizes);

		Splitter & operator<<(QWidget*w);
		Splitter & operator<<(QLayout*lay);

		EMBED_QPOINTER_AND_CAST(QSplitter)
	protected:
		void init(QWidget * parent);//C++11 ctor
};