//HBoxLayout.h by Kostya Kozachuck as neurocod
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