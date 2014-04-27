//CompactVBoxLayout.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "VBoxLayout.h"
QVBoxLayout* compactVBoxLayout(QWidget*parent);

class CompactVBoxLayout: public VBoxLayout {
	public:
		CompactVBoxLayout();
		CompactVBoxLayout(QWidget*parent);
		CompactVBoxLayout(QBoxLayout*parent);
		virtual ~CompactVBoxLayout() {}
};
typedef CompactVBoxLayout VBoxLayout00;