//GridLayout.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

//TODO: QLayout
class GridLayout: public Layout {
	public:
		GridLayout();
		virtual ~GridLayout() {}

		EMBED_QPOINTER_AND_CAST(QGridLayout)
	protected:
		void init();
};