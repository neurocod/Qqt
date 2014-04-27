//FileReader.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

class FileReader {
	public:
		static bool read(IN const QString & fileName, OUT QByteArray & arrFileData);
		static bool readAscii(IN const QString & fileName, OUT QString & strFileData);
		static bool readUnicode(IN const QString & fileName, OUT QString & strFileData);
		static bool readResourceFile(IN const QString & fileName, OUT QByteArray & arrFileData);
		static void reportError(QFile & file);
		static void reportError(QString file, QString error);
};