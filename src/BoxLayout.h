//BoxLayout.h by Kostya Kozachuck as neurocod - 19.07.2011 9:47:16
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "Layout.h"

class BoxLayout: public Layout {
	public:
		BoxLayout();
		virtual ~BoxLayout() {}
		BoxLayout& operator<<(QWidget*w);
		BoxLayout& operator<<(QLayout*l);
		BoxLayout& operator<<(QLayoutItem * item);
		BoxLayout& operator<<(const QString & str);//adds QLabel
		void setCompact();
		void insertStretch(int index=-1, int stretch = 0);
		void addStretch(int stretch = 0);

		//int count
		EMBED_QPOINTER_AND_CAST(QBoxLayout)
	protected:
		void init(QBoxLayout*d);
};