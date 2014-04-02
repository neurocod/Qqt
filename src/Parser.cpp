//Parser.cpp by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#include "pch.h"
#include "Parser.h"

//static
bool Parser::removeBefore(IN const QString & strPart, IN OUT QString & str, bool bCutPart, Qt::CaseSensitivity cs) {
	if(strPart.isEmpty() || str.isEmpty())
		return false;

	int nIndex = str.indexOf(strPart, 0, cs);
	if(-1==nIndex)
		return false;
	if(bCutPart)
		nIndex += strPart.length();
	str = str.mid(nIndex);
	return true;
}
//static
bool Parser::removeAfter(IN const QString & strPart, IN OUT QString & str, bool bCutPart, Qt::CaseSensitivity cs) {
	if(strPart.isEmpty() || str.isEmpty())
		return false;

	int nIndex = str.indexOf(strPart, 0, cs);
	if(-1==nIndex)
		return false;
	if(!bCutPart)
		nIndex += strPart.length();
	str = str.mid(0, nIndex);
	return true;
}
//static
bool Parser::leaveTextBetween(const QString & strStart, const QString & strEnd, IN OUT QString & str, Qt::CaseSensitivity cs) {
	QString ret = str;
	if(removeBefore(strStart, ret, true, cs) && removeAfter(strEnd, ret, true, cs)) {
		str = ret;
		return true;
	}
	return false;
}
//static
bool Parser::removeBetween(const QString & strStart, const QString & strEnd, IN OUT QString & str, Qt::CaseSensitivity cs) {
	int i0 = str.indexOf(strStart, 0, cs);
	if(-1==i0)
		return false;
	int i1 = str.indexOf(strEnd, i0 /* + strStart.length() ? */, cs);
	if(-1==i1)
		return false;
	str.remove(i0, i1 + strEnd.length() - i0);
	return true;
}
void Parser::removeHtmlComments(QString & str) {
	bool bCheck = true;
	QString strCommentStart = "<!--";
	QString strCommentEnd = "-->";
	while(bCheck) {
		bCheck = false;
		int nStart = str.indexOf(strCommentStart);
		if(-1!=nStart) {
			int nEnd = str.indexOf("-->", nStart + strCommentStart.length());
			if(-1!=nEnd)
			{
				bCheck = true;
				str.remove(nStart, nEnd - nStart + strCommentEnd.length());
			}
		}
	}
}
QString Parser::addOrIncrementSuffix(const QString & _str) {
	QString str(_str);
	int num = 0;
	//get num, prepare end for adding
	if(str.length()>3 && str.contains('(') && str.endsWith(')')) {
		bool onlyNumberAfterLeftbrace=true;
		int index = str.length()-2;
		while(onlyNumberAfterLeftbrace && index>=0) {
			QChar ch = str.at(index);
			if('('==ch)
				break;
			if(!ch.isDigit()) {
				onlyNumberAfterLeftbrace = false;
			}
			index--;
		}
		ASSERT(index>=0);
		if(onlyNumberAfterLeftbrace) {
			QByteArray arr = str.toLocal8Bit();
			const char* chInt = arr.constData();
			const char* chInt2 = chInt + index + 1;
			num = atoi(chInt2);
			//next index
			++num;
			str.truncate(index);
		}
	}
	str += QString("(%1)").arg(num);
	return str;
}
QStringList Parser::allBetween(const QString & all, const QString & start, const QString & end) {
	QStringList ret;
	int len0 = start.length();
	int len1 = end.length();
	if(len0==0 || len1==0)
		return ret;
	int i = 0;
	forever{
		i = all.indexOf(start, i);
		if(-1==i)
			break;
		i += len0;
		int i2 = all.indexOf(end, i);
		if(-1==i2)
			break;
		QString str = all.mid(i, i2-i);
		ret << str;
		i = i2;
	}
	return ret;
}
void Parser::ifGreaterTruncateAddEllipsis(QString & str,int length) {
	if(str.length() > length) {
		str.truncate(length);
		str += "...";
	}
}