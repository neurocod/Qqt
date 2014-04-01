//FileFacility.cpp by Kostya Kozachuck as neurocod - 03.07.2010 13:34:47
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "FileFacility.h"
#include "DirString.h"

bool FileFacility::createDirForFile(const QString & strFile) {
	int pos = strFile.lastIndexOf('/');
	if(-1==pos) {
		//current directory
		return true;
	}
	QString strPath = strFile.left(pos);
	return QDir().mkpath(strPath);
}
bool serializationCheck(bool bSave, QDataStream & stream, QString strCheck) {
	if(stream.status()!=QDataStream::Ok)
		return false;
	const QChar nMagicCheck = 0xf00d;//food
	if(bSave) {
		stream << nMagicCheck;
		stream << strCheck;
		return true;
	} else {
		bool ret = false;
		QChar nCheck;
		stream >> nCheck;
		if(stream.status()!=QDataStream::Ok)
			return false;
		if(nMagicCheck==nCheck) {
			QString strTest;
			stream >> strTest;
			if(stream.status()!=QDataStream::Ok)
				return false;
			ret = strCheck==strTest;
			if(!ret) {
				QString strError = QObject::tr("Loading check failed: not found string '%1'\n")
					.arg(strCheck);
				msgBox(strError);
			}
		} else {
			QString strError = QObject::tr("Loading check failed: not found number before string '%1'\n").arg(strCheck);
			msgBox(strError);
		}

		return ret;
	}
}
//static
void FileFacility::showDirWithFile(const QString & dir, const QString & file) {
	#ifdef Q_OS_WIN32
		QString path = DirString(dir);
		path += file;
		//problems when path contains ','
		QProcess::startDetached("explorer.exe", QStringList() << "/select," << QDir::toNativeSeparators(path));
	#else
		QDesktopServices::openUrl(QUrl::fromLocalFile(dir));
	#endif
}
//static
void FileFacility::showDirWithFile(const QString & _path) {
	QString path = _path;
	path.replace('\\', '/');
	QString dir, file;
	int index = path.lastIndexOf('/');
	if(-1==index) {
		dir = path;
	} else {
		index++;
		dir = path.left(index);
		file = path.mid(index);
	}
	showDirWithFile(dir, file);
}
//static
void FileFacility::openInTextEdditor(const QString & strPath) {
	//TODO: choose Program files, if no Notepad++ - use notepad
	QString editorPathName = "C:/Program Files (x86)/Notepad++/notepad++.exe";
	QStringList args;
	args << strPath;
	/*if (lineNumber != -1) {
		args << "-n" + Int32::toString(lineNumber);
	}*/
	QProcess::startDetached("\"" + editorPathName + "\"", args);
}
//static
QString FileFacility::imageExtensionsForFileDialog(const QList<QByteArray> & li) {
	static QHash<QString, QString> haNames;
	if(haNames.isEmpty()) {
		haNames["bmp"] = "Windows Bitmap";
		haNames["gif"] = "Graphic Interchange Format (optional)";
		haNames["jpg"] = "Joint Photographic Experts Group";
		haNames["jpeg"] = "Joint Photographic Experts Group";
		haNames["png"] = "Portable Network Graphics";
		haNames["pbm"] = "Portable Bitmap";
		haNames["pgm"] = "Portable Graymap";
		haNames["ppm"] = "Portable Pixmap";
		haNames["tiff"] = "Tagged Image File Format";
		haNames["xbm"] = "X11 Bitmap";
		haNames["xpm"] = "X11 Pixmap";
		haNames["ico"] = "Windows icon";
	}
	QString ret;

	//Images (*.png *.xpm *.jpg);;
	ret += tr("Images (");
	foreach(QByteArray arr, li) {
		ret += "*.";
		ret += arr;
		ret += " ";
	}
	ret.remove(ret.length()-1, 1);
	ret += ");;";
	//
	foreach(QByteArray arr, li) {
		QString ext = arr;
		QString desc = haNames[ext];
		if(desc.isEmpty())
			desc = tr("%1 files").arg(ext.toUpper());
		ret += desc + QString(" (*.%1);;").arg(ext);
	}
	ret += tr("All files (*);;");
	return ret;
}