//Settings.h by Kostya Kozachuck as neurocod - 03.12.2010 4:16:04
//BSD license https://github.com/neurocod/Qqt
#pragma once

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
			t = value(key, t).value<T>();
		}
		template<typename T>
		void update(bool bSave, const QString & key, IN OUT T & t) {
			if(bSave) {
				save(key, t);
			} else {
				load(key, t);
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
		template<class T>
		void updateCurrentIndex(bool bSave, const QString & key, IN OUT T*edit, const QVariant defaultValue = -1) {
			ASSERT(edit);
			if(bSave) {
				setValue(key, edit->currentIndex());
			} else {
				edit->setCurrentIndex(value(key, defaultValue).toInt());
			}
		}
};
class FileDialogLastDir {
	public:
		static QString get(const QString & key = QString());
		static void set(QString str, const QString & key = QString());
	protected:
		static QString dir;
};