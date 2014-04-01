//Layout.h by Kostya Kozachuck as neurocod - 11.03.2012 21:04:56
//BSD license https://github.com/neurocod/Qqt
#pragma once

//abstract - properties redirect
class Layout: public ObjectPropertyRedirects {
	public:
		Layout();
		virtual ~Layout() {}

		PROPERTY_REDIRECTV(QLayout, QLayout::SizeConstraint, sizeConstraint, sizeConstraint, setSizeConstraint);
		PROPERTY_REDIRECTV(QLayout, int, spacing, spacing, setSpacing);
		EMBED_QPOINTER_AND_CAST(QLayout)
	protected:
		void init(QLayout*d);
};