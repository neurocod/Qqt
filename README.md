Qqt
===

Quick Qt - syntactic sugar for Qt.
Compare Qt and Qqt:
//Qt
QVBoxLayout* layout = new QVBoxLayout();//Qt
window->setLayout(layout);

//Qqt
VBoxLayout lay(window);

layout->addWidget(w);//Qt
layout << w;//Qqt

layout->addChildLayout(lay2);//Qt
layout << lay2;//Qqt

layout->addWidget(new QLabel(tr("Text")));
layout << tr("Text");