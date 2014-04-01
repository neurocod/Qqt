//RotatableToolBar.cpp by Kostya Kozachuck as neurocod - 21.11.2011 10:31:45
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "RotatableToolBar.h"
#ifdef USE_QXT
#include <qxtlabel.h>
#endif

RotatableToolBar::RotatableToolBar(const QString & title, QWidget * parent): QToolBar(title, parent) {
	init();
}
RotatableToolBar::RotatableToolBar(QWidget * parent): QToolBar(parent) {
	init();
}
void RotatableToolBar::init() {
	connect(this, SIGNAL(orientationChanged(Qt::Orientation)), SLOT(onOrientationChanged(Qt::Orientation)));
}
void RotatableToolBar::onOrientationChanged(Qt::Orientation orientation) {
	foreach(QAction*act, actions()) {
		QWidgetAction*wa = qobject_cast<QWidgetAction*>(act);
		if(wa) {
			QWidget*w = wa->defaultWidget();
			maybeRotate(w, orientation);
		}
	}
}
void RotatableToolBar::maybeRotate(QWidget*w, Qt::Orientation orientation) {
	if(!w)
		return;
	QSlider*slider = qobject_cast<QSlider*>(w);
	if(slider) {
		slider->setOrientation(orientation);
		return;
	}
	QTabBar*tabBar = qobject_cast<QTabBar*>(w);
	if(tabBar) {
		tabBar->setShape(Qt::Vertical==orientation ?
						QTabBar::RoundedEast: QTabBar::RoundedNorth);
		return;
	}
#ifdef USE_QXT
	QxtLabel*qxtLabel = qobject_cast<QxtLabel*>(w);
	if(qxtLabel) {
		qxtLabel->setRotation(Qt::Horizontal==orientation ?
							Qxt::NoRotation: Qxt::Clockwise);
		return;
	}
#endif
}