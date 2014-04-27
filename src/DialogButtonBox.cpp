//DialogButtonBox.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "DialogButtonBox.h"

DialogButtonBox::DialogButtonBox(QDialog*parent, bool addOkCancel): QDialogButtonBox(parent) {
	if(addOkCancel) {
		addOk();
		addCancel();
		acceptRejectTo(parent);
	}
}
QPushButton* DialogButtonBox::addOk() {
	auto ret = addButton(QDialogButtonBox::Ok);
	ret->setIcon(QIcon(":/qt-project.org/styles/commonstyle/images/standardbutton-apply-32.png"));
	return ret;
}
QPushButton* DialogButtonBox::addCancel() {
	auto ret = addButton(QDialogButtonBox::Cancel);
	ret->setIcon(cancelIcon());
	return ret;
}
void DialogButtonBox::acceptRejectTo(QDialog*dlg) {
	connect(this, SIGNAL(accepted()), dlg, SLOT(accept()));
	connect(this, SIGNAL(rejected()), dlg, SLOT(reject()));
}
QIcon DialogButtonBox::cancelIcon() {
	static QIcon ret(QIcon(":/qt-project.org/styles/commonstyle/images/standardbutton-cancel-32.png"));
	return ret;
}