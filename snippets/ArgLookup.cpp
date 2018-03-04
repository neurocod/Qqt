//ArgLookup.cpp by Kostya Kozachuk as neurocod
//Logs passed arguments so you can debug what is going on
#include <QtCore>

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);
	QString path = QString("D:/path/to/save/log/args %1.txt")
		.arg(QDateTime::currentDateTime().toString("yyyy.MM.dd HH-mm-ss-zzz"));
	struct File: public QFile {
		File(QString path): QFile(path) {}
		void write(QString str) {
			__super::write(str.toLatin1());
		}
	};
	File f(path);
	if(!f.open(QIODevice::WriteOnly)) {
		qDebug() << "Can't open file " << path;
		return 1;
	}
	f.write(QString("argc: %1\n").arg(argc));
	for(int i = 0; i < argc; ++i) {
		QString str = QString("%1) %2\n")
			.arg(i)
			.arg(QString(argv[i]));
		qDebug() << str;
		f.write(str);
	}
	qDebug() << "ok";
	return 0;
}
