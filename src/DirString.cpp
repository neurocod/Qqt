//DirString.cpp by Kostya Kozachuck as neurocod - 12.08.2011 18:28:31
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "DirString.h"

DirString::DirString() {
}
DirString::DirString(const QString & path): m_str(path) {
	correctSlash();
}
void DirString::correctSlash() {
	if(!m_str.isEmpty() && !m_str.endsWith('/'))
		m_str += '/';
}
//static
int DirString::length(const QStringList & li) {
	int len = 0;
	foreach(QString str, li) {
		len += str.length();
		if(!str.endsWith('/'))
			len++;
	}
	return len;
}
bool DirString::isEmpty()const {
	return m_str.isEmpty();
}
DirString& DirString::operator+=(QString str) {
	if(!isEmpty() &&
		(str.startsWith('/') || str.startsWith('\\'))
	) {
		m_str.remove(0, 1);
	}
	m_str += str;
	correctSlash();
	return *this;
}