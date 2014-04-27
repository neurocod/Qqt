//FileWriter.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

class FileWriter {
	public:
		static bool write(IN const QString & strFileName, IN const QByteArray& arr);
		static bool writeAscii(IN const QString & strFileName, IN const QString & strFileData);
		static bool writeUnicode(IN const QString & strFileName, IN const QString & strFileData);
	private:
		FileWriter();
};