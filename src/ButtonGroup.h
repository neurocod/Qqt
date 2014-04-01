//ButtonGroup.h by Kostya Kozachuck as neurocod - 11.03.2012 6:41:26
//BSD license https://github.com/neurocod/Qqt
#pragma once

class ButtonGroup {
	public:
		ButtonGroup(QObject * parent = 0);
		virtual ~ButtonGroup() {}

		PROPERTY_REDIRECTV(QButtonGroup, bool, exclusive, exclusive, setExclusive);
		ButtonGroup& operator<<(QAbstractButton * button);
		EMBED_QPOINTER_AND_CAST(QButtonGroup)
};