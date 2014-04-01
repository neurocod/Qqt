//DirString.h by Kostya Kozachuck as neurocod - 12.08.2011 18:28:30
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