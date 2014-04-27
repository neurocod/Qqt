//RotatableToolBar.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

class RotatableToolBar: public QToolBar {
	Q_OBJECT
	public:
		RotatableToolBar(const QString & title, QWidget * parent = 0);
		RotatableToolBar(QWidget * parent = 0);
		virtual ~RotatableToolBar() {}
	public slots:
		void onOrientationChanged(Qt::Orientation orientation);
	protected:
		void init();//C++11
		void maybeRotate(QWidget*w, Qt::Orientation orientation);
};