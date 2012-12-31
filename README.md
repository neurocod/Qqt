Qqt
===

Quick Qt - syntactic sugar for Qt.
----------------------------------

Examples to compare Qt and Qqt:


	QVBoxLayout* layout = new QVBoxLayout();//Qt

	window->setLayout(layout);

VBoxLayout lay(window);//Qqt

layout->addWidget(w);//Qt

layout << w;//Qqt


layout->addChildLayout(lay2);//Qt

layout << lay2;//Qqt


layout->addWidget(new QLabel(tr("Text")));

layout << tr("Text");