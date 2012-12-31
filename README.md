Qqt
===

Quick Qt - syntactic sugar for Qt.
----------------------------------

Examples to compare Qt and Qqt:

	//Qt:
	QVBoxLayout* layout = new QVBoxLayout();
	window->setLayout(layout);
	//Qqt analogue:
	VBoxLayout lay(window);

	layout->addWidget(w);//Qt
	layout << w;//Qqt

	layout->addChildLayout(lay2);//Qt
	layout << lay2;//Qqt

	layout->addWidget(new QLabel(tr("Text")));
	layout << tr("Text");