//ComboBox.h by Kostya Kozachuck as neurocod - 11.03.2012 7:19:02
//BSD license https://github.com/neurocod/Qqt
#pragma once

class ComboBox: public WidgetPropertyRedirects {
	public:
		ComboBox();
		template<class T1>
		ComboBox(T1 t1) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
		}
		template<class T1, class T2>
		ComboBox(T1 t1, T2 t2) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
		}
		template<class T1, class T2, class T3>
		ComboBox(T1 t1, T2 t2, T3 t3) {
			init();
			CtorProcessor p;
			p.process(*this, t1);
			p.process(*this, t2);
			p.process(*this, t3);
		}
		virtual ~ComboBox() {}

		ComboBox& operator<<(QStringList texts);
		ComboBox& operator<<(QString text);
		void add(const QString & text, const QVariant & userData = QVariant());
		void add(const QIcon & icon, const QString & text, const QVariant & userData = QVariant());
		//count : const int;
		PROPERTY_REDIRECTV(QComboBox, bool, duplicatesEnabled, duplicatesEnabled, setDuplicatesEnabled);
		//currentText: const QString;
		PROPERTY_REDIRECTV(QComboBox, bool, editable, isEditable, setEditable);
		PROPERTY_REDIRECTV(QComboBox, bool, frame, hasFrame, setFrame);
		PROPERTY_REDIRECT (QComboBox, QSize, iconSize, iconSize, setIconSize);
		PROPERTY_REDIRECTV(QComboBox, QComboBox::InsertPolicy, insertPolicy, insertPolicy, setInsertPolicy);
		PROPERTY_REDIRECTV(QComboBox, int, currentIndex, currentIndex, setCurrentIndex);
		PROPERTY_REDIRECTV(QComboBox, int, maxCount, maxCount, setMaxCount);
		PROPERTY_REDIRECTV(QComboBox, int, maxVisibleItems, maxVisibleItems, setMaxVisibleItems);
		PROPERTY_REDIRECTV(QComboBox, int, minimumContentsLength, minimumContentsLength, setMinimumContentsLength);
		PROPERTY_REDIRECTV(QComboBox, int, modelColumn, modelColumn, setModelColumn);
		PROPERTY_REDIRECTV(QComboBox, QComboBox::SizeAdjustPolicy, sizeAdjustPolicy, sizeAdjustPolicy, setSizeAdjustPolicy);
		EMBED_QPOINTER_AND_CAST(QComboBox)
	protected:
		void init();//C++11 ctor

		typedef CtorProcessorT<ComboBox> CtorProcessor;
};