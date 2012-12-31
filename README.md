Qqt = Quick Qt - syntactic sugar for Qt.
----------------------------------------
Write Qt code like html. Examples to compare Qt and Qqt:

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

Constructors of buttons, actions and other classes are templates, and can take several arguments, from 0 to more, where:

* first QString, if specified, is for setText()
* second QString, if specified, is for setToolTip()
* QIcon, if specified, is for setIcon()
* QKeySequence for setShortcut()
* Qt::ShortcutContext for setShortcutContext()
* etc

create QAction like this:

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
# copy all sources: create dir Qqt inside your project, place there all files from Qqt/src folder
# make traditional library, and commit it here so others can use it :) currently I use non-git version control system for my Qqt copy