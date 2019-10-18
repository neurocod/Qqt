//FileReader.h by Kostya Kozachuck as neurocod - 21.10.2011 12:26:28
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "StringStatus.h"

class FileReader {
	public:
		static ReadStatusT<QByteArray> read(const QString & fileName);
		static ReadStatusV<QString> readAscii(const QString & fileName);
		static ReadStatusV<QString> readUnicode(const QString & fileName);
		static ReadStatusT<QByteArray> readResourceFile(const QString & fileName);
		static ReadStatusV<QString> readResourceToString(const QString & fileName);
		static ReadStatus formatError(const QFile & file);
		static ReadStatus formatError(const QString & file, const QString & error);
};