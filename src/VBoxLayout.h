//VBoxLayout.h by Kostya Kozachuck as neurocod - 19.07.2011 9:47:06
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "BoxLayout.h"

class VBoxLayout: public BoxLayout {
	public:
		VBoxLayout();
		VBoxLayout(QWidget*parent);
		VBoxLayout(QBoxLayout*parent);
		virtual ~VBoxLayout() {}

		EMBED_QPOINTER_AND_CAST(QVBoxLayout)
	protected:
		void init();
};