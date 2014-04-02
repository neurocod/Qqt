//Parser.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

class Parser {
	public:
		//search for strPart in str, not found -> return false, otherwise cut text before part and return true
		static bool removeBefore(IN const QString & strPart, IN OUT QString & str,
			bool bCutPart=true, Qt::CaseSensitivity cs = Qt::CaseSensitive);
		static bool removeAfter(IN const QString & strPart, IN OUT QString & str,
			bool bCutPart=true, Qt::CaseSensitivity cs = Qt::CaseSensitive);
		static bool leaveTextBetween(const QString & strStart, const QString & strEnd, IN OUT QString & str,
			Qt::CaseSensitivity cs = Qt::CaseSensitive);
		static bool removeBetween(const QString & strStart, const QString & strEnd, IN OUT QString & str,
			Qt::CaseSensitivity cs = Qt::CaseSensitive);
		static void removeHtmlComments(QString & str);
		static QStringList allBetween(const QString & all, const QString & start, const QString & end);

		static QString addOrIncrementSuffix(const QString & _str);
		static void ifGreaterTruncateAddEllipsis(QString & str, int length);
};