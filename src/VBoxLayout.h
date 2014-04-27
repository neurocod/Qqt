//VBoxLayout.h by Kostya Kozachuck as neurocod
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