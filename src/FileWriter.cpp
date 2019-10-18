//FileWriter.cpp by Kostya Kozachuck as neurocod - 22.10.2011 18:07:19
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "FileWriter.h"

StringStatus FileWriter::write(const QString & fileName, const QByteArray& arr) {
	QFile file(fileName);
	if(!file.open(QIODevice::WriteOnly))
		return formatError(fileName, file.errorString());
	file.write(arr);
	file.close();
	return true;
}
StringStatus FileWriter::write8bit(const QString & fileName, const QString & strFileData) {
	return write(fileName, strFileData.toLocal8Bit());
}
StringStatus FileWriter::writeUnicode(const QString & fileName, const QString & contents, const char*codec) {
	QFile file(fileName);
	if(!file.open(QIODevice::WriteOnly))
		return formatError(fileName, file.errorString());
	QTextStream stream(&file);
	stream.setCodec(codec);
	stream.setGenerateByteOrderMark(true);
	stream << contents;
	file.close();
	return true;
}
StringStatus FileWriter::removeFile(const QString & path, int tries, int msecs) {
	for(int i = 0; i<tries; ++i) {
		QFileInfo info(path);
		if(info.exists() && info.isFile()) {
			if(info.dir().remove(info.fileName()))
				return true;
		}
		Thread::msleep(msecs);
	}
	return StringStatus(QObject::tr("Can't remove file %1").arg(path));
}
StringStatus FileWriter::formatError(const QString & file, const QString & error) {
	return StringStatus(QObject::tr("Error writing file '%1': %2").arg(file).arg(error));
}
StringStatus FileWriter::formatError(const QFile & file) {
	if(file.error()==QFile::NoError)
		return true;
	return formatError(file.fileName(), file.errorString());
}
StringStatus FileWriter::mkPath(const QDir & dir, int tries, int msecForRetry) {
	for(int i = 0; i < tries; ++i) {
		if(i>0)
			QThread::msleep(msecForRetry);
		if(dir.mkpath(QStringLiteral("."))) {
			if(dir.exists()) {
				return true;
			}
		}
	}
	return QObject::tr("Can't create directory %1").arg(QDir::toNativeSeparators(dir.absolutePath()));
}