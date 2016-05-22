//Settings.cpp by Kostya Kozachuck as neurocod - 03.12.2010 4:16:05
#include "pch.h"
#include "Settings.h"

Settings::Settings() {
	if(QCoreApplication::applicationName().isEmpty()
		|| QCoreApplication::organizationName().isEmpty()
		//QCoreApplication::organizationDomain().isEmpty()
		//QCoreApplication::applicationVersion
		)
	{
		msgBox(tr("Forget to set application strings"));
		ASSERT(0);
	}
}
void Settings::updateValue(bool bSave, const QString & key, IN OUT QLineEdit*edit) {
	ASSERT(edit);
	if(bSave) {
		setValue(key, edit->text());
	} else {
		edit->setText(value(key).toString());
	}
}
void Settings::updateValue(bool bSave, const QString & key, IN OUT QSpinBox*box) {
	ASSERT(box);
	if(bSave) {
		setValue(key, box->value());
	} else {
		if(contains(key))
			box->setValue(value(key).toInt());
	}
}
void Settings::updateValue(bool bSave, const QString & key, IN OUT QSplitter*split) {
	if(bSave) {
		setValue(key, split->saveState());
	} else {
		split->restoreState(value(key).toByteArray());
	}
}
void Settings::updateState(bool bSave, const QString & key, IN OUT QHeaderView*view) {
	if(bSave) {
		setValue(key + ".columnsCount", view->count());
		setValue(key, view->saveState());
	} else {
		int count = value(key + ".columnsCount", 0).toInt();
		if(count==view->count()) {
			view->restoreState(value(key).toByteArray());
		}
	}
}
void Settings::updateCheckState(bool bSave, const QString & key, IN OUT QAction*act) {
	ASSERT(act);
	if(bSave) {
		setValue(key, act->isChecked());
	} else {
		if(contains(key))
			act->setChecked(value(key).toBool());
	}
}
void Settings::updateCheckState(bool bSave, const QString & key, IN OUT QCheckBox*box) {
	ASSERT(box);
	if(bSave) {
		setValue(key, box->isChecked());
	} else {
		if(contains(key))
			box->setChecked(value(key).toBool());
	}
}
void Settings::updateCheckState(bool bSave, const QString & key, IN OUT QGroupBox*box) {
	ASSERT(box);
	if(bSave) {
		setValue(key, box->isChecked());
	} else {
		if(contains(key))
			box->setChecked(value(key).toBool());
	}
}
void Settings::beginGroup(QObject*p) {
	ASSERT(p);
	if(!p)
		return;
	beginGroup(p->metaObject()->className());
	if(!p->objectName().isEmpty())
		beginGroup(p->objectName());
}
void Settings::endGroup(QObject*p) {
	ASSERT(p);
	if(!p)
		return;
	if(!p->objectName().isEmpty())
		endGroup();
	endGroup();
}
void Settings::beginGroups(const QStringList & li) {
	for(auto str: li)
		beginGroup(str);
}
void Settings::endGroups(const QStringList & li) {
	for(auto str: li)
		endGroup();
}
void Settings::copyFrom(const QString & organization, const QString & application) {
	QSettings sett(organization, application);
	auto li = sett.allKeys();
	for(auto strKey: li) {
		auto v = sett.value(strKey);
		save(strKey, v);
	}
}
//static
QVariant Settings::singleValue(const QString & name, const QVariant & defaultValue) {
	Settings sett;
	return sett.value(name, defaultValue);
}
QString FileDialogLastDir::dir;
QString FileDialogLastDir::get(const QString & key) {
	if(dir.isEmpty()) {
		Settings sett;
		sett.load("FileDialogLastDir"+key, dir);
	}
	return dir;
}
void FileDialogLastDir::set(const QString & key, const QString & _file) {
	QString file = _file;
	QFileInfo info(file);
	if(info.isFile())
		file = info.dir().absolutePath();
	dir = file;
	Settings sett;
	sett.save("FileDialogLastDir"+key, dir);
}