Qqt = Quick Qt - syntactic sugar for Qt.
----------------------------------------
Write Qt code like html. Examples to compare Qt and Qqt:

	QVBoxLayout* lay1 = new QVBoxLayout(widget);//Qt
	VBoxLayout lay2(widget);//Qqt

	lay1->addWidget(w);//Qt
	lay2 << w;//Qqt

	lay1->addChildLayout(lay3);//Qt
	lay2 << lay3;//Qqt

	lay1->addWidget(new QLabel(tr("Text")));//Qt
	lay2 << tr("Text");//Qqt

	QPushButton*btn = new QPushButton();
	btn->setIcon(QIcon());
	btn->setText(QString());
	btn->set...(...)
	//Qqt:
	PushButton btn(QIcon(), QString(), ...);
	//or
	PushButton btn(QString(), QIcon(), ...);//parameters in any order

Constructors of buttons, actions and other classes are templates, and can take several arguments, from 0 to more, where:

* first QString parameter, if specified, is for setText()
* second QString parameter, if specified, is for setToolTip()
* QIcon, if specified, is for setIcon()
* QKeySequence is for setShortcut()
* Qt::ShortcutContext is for setShortcutContext()
* etc

Using this approach, create QAction like this:

	Action act(tr("Text"));
	//parameters in any order:
	Action act(tr("Text"), QIcon(":/iconPath"), tr("tooltip"), QKeySequence("Ctrl+f"));
	Action act(QIcon(":/iconPath"), tr("Text"), tr("tooltip"), QKeySequence("Ctrl+f"));
	Action act(QIcon(":/onlyIcon"));
	
	//buttons use the same approach
	ToolButton btn(QIcon(), QKeySequence("..."));

Use properties instead of set* functions:

	Action act;
	act.tooltip = "";
	act.shortcut = QKeySequence("Ctrl+F");

	msgBox("Visual Basic style!");

More complex examples, how to place several widgets like html:

	Widget w;
	VBoxLayout lay(w);
	
	lay << tr("See toolbar below:");
	{
		HBoxLayout lay2(lay);
		
		Action act0(tr("First action"));
		connect(act0, SIGNAL(triggered()), w, SLOT(a0()));
		lay2 << act0;

		Action act1(tr("Second action"));
		connect(act1, SIGNAL(triggered()), w, SLOT(a1()));
		lay2 << act1;
	}
	lay << new QTextEdit();

License
-------
BSD-like
How to include
--------------
There are few ways:

1) copy all sources: mkdir Qqt inside your project, place there all the files from Qqt/src folder, include Qqt/includeMe.h in your precompiled header file

2) make traditional library, and commit it here so others can use it :)
Project is updated rarely on git cause currently I use non-git version control system for my Qqt copy.
