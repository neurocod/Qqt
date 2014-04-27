//DirString.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

//ensures there is always / at the end of the path, if it's not empty
//default state is empty
class DirString {
	public:
		DirString();
		DirString(const QString & path);
		virtual ~DirString() {}

		operator QString()const { return m_str; }
		static int length(const QStringList & li);
		bool isEmpty()const;
		DirString& operator+=(QString str);
	protected:
		QString m_str;

		void correctSlash();
};