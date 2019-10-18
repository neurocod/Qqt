//FileReader.cpp by Kostya Kozachuck as neurocod - 21.10.2011 12:26:29
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "FileReader.h"

//TODO: += FileReader::read(const QString & codec, ...)
ReadStatusV<QString> FileReader::readAscii(const QString & fileName) {
	auto ret = read(fileName);
	if(!ret.ok())
		return ret;
	return {true, ret._v};
}
ReadStatusT<QByteArray> FileReader::read(const QString & fileName) {
	QFile file(fileName);
	if(file.open(QIODevice::ReadOnly)) {
		auto arr = file.readAll();
		file.close();
		return arr;
	}
	return formatError(file);
}
ReadStatusV<QString> FileReader::readUnicode(const QString & fileName) {
	auto ret = read(fileName);
	if(!ret.ok())
		return ret;
	QTextStream readStream(ret._v);
	readStream.setCodec("UTF-8");
	readStream.setAutoDetectUnicode(true);
	auto text = readStream.readAll();
	return {true, text};
}
ReadStatusT<QByteArray> FileReader::readResourceFile(const QString & fileName) {
	ASSERT(fileName.startsWith(":"));
	QResource resource(fileName);
	if(!resource.isValid()) {
		ASSERT(0);
		return ReadStatus(QObject::tr("invalid resource %1").arg(fileName));
	}
	if(resource.isCompressed()) {
 		return qUncompress(resource.data(), resource.size());
	}
	return QByteArray((LPCSTR)resource.data(), resource.size());
}
ReadStatusV<QString> FileReader::readResourceToString(const QString & fileName) {
	auto s = readResourceFile(fileName);
	if(!s.ok())
		return s;
	QTextStream readStream(s._v);
	readStream.setCodec("UTF-8");
	readStream.setAutoDetectUnicode(true);
	ReadStatusV<QString> ret = ReadStatus(readStream);
	ret._v = readStream.readAll();
	return ret;
}
ReadStatus FileReader::formatError(const QFile & file) {
	QString strfileName = file.fileName();
	strfileName = QFileInfo(strfileName).absoluteFilePath();
	return formatError(strfileName, file.errorString());
}
ReadStatus FileReader::formatError(const QString & file, const QString & error) {
	QString msg = QObject::tr("Error reading file '%1': %2\n")
		.arg(file)
		.arg(error);
	return ReadStatus(msg);
}