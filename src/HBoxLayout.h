//HBoxLayout.h by Kostya Kozachuck as neurocod - 19.07.2011 9:46:49
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "BoxLayout.h"

class HBoxLayout: public BoxLayout {
	public:
		HBoxLayout();
		HBoxLayout(QWidget*parent);
		HBoxLayout(QBoxLayout*parent);
		virtual ~HBoxLayout() {}

		EMBED_QPOINTER_AND_CAST(QHBoxLayout)
	protected:
		void init();
};