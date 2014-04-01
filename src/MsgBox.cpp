//MsgBox.cpp by Kostya Kozachuck as neurocod - 23.12.2011 6:34:33
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "MsgBox.h"

MsgBox::Btn msgBox(QString t1) {
	MsgBox box(t1);
	return box.execReturnBtn();
}
void MsgBox::init() {
	m_nStringParam = 0;

	detailedText.init(this);
	icon.init(this);
	iconPixmap.init(this);
	informativeText.init(this);
	standardButtons.init(this);
	text.init(this);
	textFormat.init(this);

	icon = MsgBox::Information;
	standardButtons = QMessageBox::Ok;
	setStyleSheet("QMessageBox{messagebox-text-interaction-flags:15}");//Qt::TextInteractionFlags
}