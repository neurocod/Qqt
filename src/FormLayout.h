//FormLayout.h by Kostya Kozachuck as neurocod - 28.06.2012 21:59:10
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "Layout.h"

class FormLayout: public Layout {
	public:
		FormLayout(QWidget * parent = 0);
		FormLayout(QBoxLayout*parent);
		virtual ~FormLayout() {}

		FormLayout& operator << (QWidget*w);
		FormLayout& operator << (const QString & str);

		PROPERTY_REDIRECTV(QFormLayout, QFormLayout::FieldGrowthPolicy, fieldGrowthPolicy, fieldGrowthPolicy, setFieldGrowthPolicy);
		PROPERTY_REDIRECTV(QFormLayout, Qt::Alignment, formAlignment, formAlignment, setFormAlignment);
		PROPERTY_REDIRECTV(QFormLayout, int, horizontalSpacing, horizontalSpacing, setHorizontalSpacing);
		PROPERTY_REDIRECTV(QFormLayout, Qt::Alignment, labelAlignment, labelAlignment, setLabelAlignment);
		PROPERTY_REDIRECTV(QFormLayout, QFormLayout::RowWrapPolicy, rowWrapPolicy, rowWrapPolicy, setRowWrapPolicy);
		PROPERTY_REDIRECTV(QFormLayout, int, verticalSpacing, verticalSpacing, setVerticalSpacing);

		EMBED_QPOINTER_AND_CAST(QFormLayout)
	protected:
		void init();
};