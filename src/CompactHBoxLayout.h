//CompactHBoxLayout.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "HBoxLayout.h"

QHBoxLayout* compactHBoxLayout(QWidget*parent);

class CompactHBoxLayout: public HBoxLayout {
	public:
		CompactHBoxLayout();
		CompactHBoxLayout(QWidget*parent);
		CompactHBoxLayout(QBoxLayout*parent);
		virtual ~CompactHBoxLayout() {}
};
typedef CompactHBoxLayout HBoxLayout00;