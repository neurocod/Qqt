//FileReader.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "FileReader.h"

//TODO: += FileReader::read(QString codec, ...)
bool FileReader::readAscii(IN const QString & fileName, OUT QString & strFileData) {
	QByteArray arr;
	if(!read(fileName, arr))
		return false;
	strFileData = QString::fromLatin1(arr.data(), arr.size());
	return true;
}
bool FileReader::read(IN const QString & fileName, OUT QByteArray & arrFileData) {
	arrFileData.clear();
	QFile file(fileName);
	if(file.open(QIODevice::ReadOnly)) {
		arrFileData = file.readAll();
		file.close();
		return true;
	}
	reportError(file);
	return false;
}
bool FileReader::readUnicode(IN const QString & fileName, OUT QString & strFileData) {
	QByteArray arr;
	if(!read(fileName, arr))
		return false;
	QTextStream readstream(&arr);
	readstream.setCodec("UTF-8");
	readstream.setAutoDetectUnicode(true);
	strFileData = readstream.readAll();
	return true;
}
//static
bool FileReader::readResourceFile(IN const QString & fileName, OUT QByteArray & arrFileData) {
	ASSERT(fileName.startsWith(":"));
	QResource resource(fileName);
	if(!resource.isValid()) {
		ASSERT(0);
		return false;
	}
	if(resource.isCompressed()) {
 		arrFileData = qUncompress(resource.data(), resource.size());
	} else {
		arrFileData = QByteArray((LPCSTR)resource.data(), resource.size());
	}
	return true;
}
//static
void FileReader::reportError(QFile & file) {
	QString strfileName = file.fileName();
	strfileName = QFileInfo(strfileName).absoluteFilePath();
	reportError(strfileName, file.errorString());
}
//static
void FileReader::reportError(QString file, QString error) {
	QString msg = QObject::tr("Error reading file '%1': %2\n")
		.arg(file)
		.arg(error)
		;
	msgBox(msg);
}