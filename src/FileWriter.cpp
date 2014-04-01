//FileWriter.cpp by Kostya Kozachuck as neurocod - 22.10.2011 18:07:19
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "FileWriter.h"

bool FileWriter::write(IN const QString & strFileName, IN const QByteArray& arr) {
	QFile file(strFileName);
	if(file.open(QIODevice::WriteOnly)) {
		file.write(arr);
		file.close();
		return true;
	}
	QString msg(
		QString("Error writing file '%1': %2\n")
		.arg(strFileName)
		.arg(file.errorString())
		);
	qWarning() << msg;
	return false;
}
bool FileWriter::writeAscii(IN const QString & strFileName,
						IN const QString & strFileData) {
	return write(strFileName,
		strFileData.toLocal8Bit()
		//file.write(strFileData.toAscii());
		);
}
bool FileWriter::writeUnicode(IN  const QString & strFileName,
											IN const QString & strFileData) {
	QFile file(strFileName);
	if(file.open(QIODevice::WriteOnly)) {
		QTextStream stream(&file);
		stream.setCodec("UTF-16");
		stream.setGenerateByteOrderMark(true);
		stream << strFileData;
		file.close();
		return true;
	}
	QString msg(
		QString("Error writing file '%1': %2\n")
		.arg(strFileName)
		.arg(file.errorString())
		);
	qWarning() << msg;
	return false;
}