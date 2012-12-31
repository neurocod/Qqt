Qqt
===

Quick Qt - syntactic sugar for Qt.
----------------------------------
Write Qt code like html.
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

	QPushButton*btn = new QPushButton();
	btn->setIcon(QIcon());
	btn->setText(QString());
	//Qqt:
	PushButton btn(QIcon(), QString());
	//or
	PushButton btn(QString(), QIcon());//parameters in any order

Constructors of buttons, actions and other classes are templates, and can take few arguments, from 0 to more, where:

	* first QString, if specified, is for setText
	* second QString, if specified, is for setToolTip
	* QIcon, if specified, is for setIcon
	* other classes support additional parameters, for example - Qt::ShortcutContext (for setShortcutContext), QKeySequence for setShortcut etc.