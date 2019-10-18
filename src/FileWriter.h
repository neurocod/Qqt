//FileWriter.h by Kostya Kozachuck as neurocod - 22.10.2011 18:07:18
//BSD license https://github.com/neurocod/Qqt
#pragma once

class FileWriter {
	public:
		static StringStatus write(const QString & fileName, const QByteArray& arr);
		static StringStatus write8bit(const QString & fileName, const QString & strFileData);
		static StringStatus writeUnicode(const QString & fileName, const QString & strFileData, const char*codec = "UTF-16");
		static StringStatus removeFile(const QString & path, int tries, int msecs);
		static StringStatus formatError(const QString & file, const QString & error);
		static StringStatus formatError(const QFile & file);
		static StringStatus mkPath(const QDir & dir, int tries = 5, int msecForRetry=50);
};