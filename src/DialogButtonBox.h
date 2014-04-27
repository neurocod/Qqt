//DialogButtonBox.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

class DialogButtonBox: public QDialogButtonBox {
	public:
		DialogButtonBox(QDialog*parent=0, bool addOkCancel=false);
		virtual ~DialogButtonBox() {}
		QPushButton* addOk();
		QPushButton* addCancel();
		void acceptRejectTo(QDialog*dlg);
		static QIcon cancelIcon();
};