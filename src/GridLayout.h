//GridLayout.h by Kostya Kozachuck as neurocod - 11.03.2012 21:00:45
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