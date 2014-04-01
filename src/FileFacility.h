//FileFacility.h by Kostya Kozachuck as neurocod - 03.07.2010 13:34:46
//BSD license https://github.com/neurocod/Qqt
#pragma once
#include "DirString.h"
#include "FileReader.h"
#include "FileWriter.h"

//QObject for tr
class FileFacility: public QObject {
	public:
		static bool createDirForFile(const QString & strFile);
		static void showDirWithFile(const QString & dir, const QString & file);
		static void showDirWithFile(const QString & path);
		static void openInTextEdditor(const QString & strPath);

		static QString imageExtensionsForFileDialog(const QList<QByteArray> & li);
		template<class T>//T can be QImageReader/QImageWriter
		static QString imageExtensionsForFileDialog() {
			auto li = T::supportedImageFormats();
			return imageExtensionsForFileDialog(li);
		}
	private:
		FileFacility() {}
};

bool serializationCheck(bool bSave, QDataStream & stream, QString strCheck);