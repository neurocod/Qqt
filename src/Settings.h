//Settings.h by Kostya Kozachuck as neurocod - 03.12.2010 4:16:04
#pragma once
#include "RestrictedValueT.h"
#include "RestrictedValueTT.h"

class Settings: public QSettings {
	public:
		Settings();
		virtual ~Settings() {}

		template<typename T>
		void save(const QString & key, const T & t) {
			setValue(key, t);
		}
		template<typename T>
		void load(const QString & key, IN OUT T & t) {
			t = value(key, t).template value<T>();
		}
		template<typename T>
		void update(bool bSave, const QString & key, IN OUT T & t) {
			if(bSave) {
				save(key, t);
			} else {
				load(key, t);
			}
		}
		template<typename T>//T = RestrictedValueT || RestrictedValueTT
		void loadRestricted(const QString & key, IN OUT T & t) {
			t = value(key, t);
		}
		template<typename T>
		void updateRestricted(bool bSave, const QString & key, IN OUT T & t) {
			if(bSave) {
				save(key, t);
			} else {
				loadRestricted(key, t);
			}
		}
		using QSettings::beginGroup;
		using QSettings::endGroup;
		static QVariant singleValue(const QString & name, const QVariant & defaultValue = QVariant());//for convenience
		void beginGroup(QObject*p);
		void endGroup(QObject*p);
		void beginGroups(const QStringList & li);
		void endGroups(const QStringList & li);
		void updateValue(bool bSave, const QString & key, IN OUT QLineEdit*edit);
		void updateValue(bool bSave, const QString & key, IN OUT QSpinBox*box);
		void updateValue(bool bSave, const QString & key, IN OUT QSplitter*split);
		void updateState(bool bSave, const QString & key, IN OUT QHeaderView*v);
		void updateCheckState(bool bSave, const QString & key, IN OUT QAction*act);
		void updateCheckState(bool bSave, const QString & key, IN OUT QCheckBox*box);
		void updateCheckState(bool bSave, const QString & key, IN OUT QGroupBox*box);
		template<class T>
		void updateCurrentIndex(bool bSave, const QString & key, IN OUT T*edit, const QVariant defaultValue = -1) {
			ASSERT(edit);
			if(bSave) {
				setValue(key, edit->currentIndex());
			} else {
				edit->setCurrentIndex(value(key, defaultValue).toInt());
			}
		}
		void copyFrom(const QString & organization, const QString & application);
};
class FileDialogLastDir {
	public:
		static QString get(const QString & key = QString());
		static void set(const QString & key, const QString & file);
		static void set(const QString & file) { set(QString(), file); }
	protected:
		static QString dir;
};