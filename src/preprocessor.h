//preprocessor.h by Kostya Kozachuck as neurocod - 27.11.2007 21:31:17
//BSD license https://github.com/neurocod/Qqt
#pragma once

#define EMBED_QPOINTER_AND_CAST(ClassName) public:\
	inline ClassName* operator->() { return d; };\
	inline const ClassName* operator->()const { return d; };\
	inline operator ClassName*() { return d; }\
	inline operator const ClassName*()const { return d; }\
	protected: QPointer<ClassName> d;

#ifndef FromUnicode
#define FromUnicode(x) (QString::fromUtf16(reinterpret_cast<const ushort *>(x)))
#endif

#ifndef CONSTRQString
#define CONSTRQString const QString &
#endif

#define PI 3.1415926535897932384626433832795

#ifndef Q_OS_WIN32
#define NEED_SUPER
//MS VC++ under win32 has this;
#endif//Q_OS_WIN32

#ifdef NEED_SUPER
#define MAYBE_SUPER(name) private: typedef name __super;
#else
#define MAYBE_SUPER(name) ;
#endif//NEED_SUPER

#ifndef CONST
#define CONST const
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#ifndef VOID
#define VOID		void
#endif

#ifndef LPVOID
typedef void* LPVOID;
#endif

#ifndef offsetofclass
#define _ATL_PACKING 8
#define offsetofclass(base, derived) ((UINT64)(static_cast<base*>((derived*)_ATL_PACKING))-_ATL_PACKING)
#endif

#ifndef offsetof
#ifdef  _WIN64
#define offsetof(s,m)   (size_t)( (ptrdiff_t)&reinterpret_cast<const volatile char&>((((s *)0)->m)) )
#else
#define offsetof(s,m)   (size_t)&reinterpret_cast<const volatile char&>((((s *)0)->m))
#endif
#endif

#define IF_DELETE0(x) if(x) {\
	delete x;\
	x = 0;\
}
//#ifndef _WCHAR_T_DEFINED
//typedef unsigned short wchar_t;
//#define _WCHAR_T_DEFINED
//#endif

#define WIDEN2(x) L ## x
#define WIDEN(x) WIDEN2(x)
#define __WFILE__ WIDEN(__FILE__)
#define __WFUNCTION__ WIDEN(__FUNCTION__)

#ifndef CONCAT
#define CONCAT(a, b) a ## b
#endif

#ifndef CONCAT2
#define CONCAT2(a, b) CONCAT(a, b)
#endif

#ifndef CONCAT3
#define CONCAT3(a, b, c) a ## b ## c
#endif

typedef unsigned char				    BYTE;
typedef unsigned short      			WORD;
typedef unsigned long       			DWORD;
typedef unsigned int	 				UINT;
typedef int		 						BOOL;
typedef short							SHORT;
typedef long							LONG;

#define INT2BOOL(x) ((0==x) ? false : true)

//#define LPCSTR const char *
typedef const char *LPCSTR, *PCSTR;
typedef const wchar_t *LPCWSTR, *PCWSTR;

#ifndef UINT64
typedef quint64 UINT64;
typedef quint32 UINT32;
typedef quint16 UINT16;
typedef unsigned char UCHAR;
#endif

#ifndef interface
#define interface struct
#endif

/*#ifndef ASSERT
#define ASSERT(x) Q_ASSERT(x)
#endif*/
void assertWithFunc(const char *assertion, const char *file, const char *func, int line);
#if !defined(ASSERT)
#  ifndef QT_NO_DEBUG
#    define ASSERT(cond) ((!(cond)) ? assertWithFunc(#cond,__FILE__,__FUNCTION__,__LINE__) : qt_noop())
#  else
#    define ASSERT(cond) qt_noop()
#  endif
#endif

/*INDEX_OF_EXPR usage example:
	QList<int> intList; intList << 1 << 5;
	int index = INDEX_OF_EXPR(intList, num, num>4);
	//now index==1
	index = INDEX_OF_EXPR(intList, num, num<0);
	//now index==-1
*/
#define INDEX_OF_EXPR(list, v, expr) indexOfExprMacroHelper(list, \
	[&](decltype((*list.begin())) & v) -> bool { return expr; }\
	)
template<class List, class Expr>
int indexOfExprMacroHelper(List & list, Expr expr) {
	int ret = -1;
	int index = 0;
	for(auto it = list.begin(); it!=list.end(); ++it, index++) {
		auto & v = *it;
		if(expr(v)) {
			ret = index;
			break;
		}
	}
	return ret;
}

//оптимизация возврата из функции, в том числе из switch (поэтому и скобки)
#define RETURN_LOCAL_STATIC_VARIABLE(Type, val) \
	{\
		static Type ret##__LINE__(val);\
		return ret##__LINE__;\
	}

template<class T>
bool isIndexValid(const T & list, int index) {
	return index>=0 && index<list.size();
}