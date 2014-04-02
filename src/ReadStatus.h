//StringStatus.h by Kostya Kozachuck as neurocod
//BSD license https://github.com/neurocod/Qqt
#pragma once

class StringStatus {
	protected:
		bool m_ok;
		QString m_msg;
		void maybeStop();
	public:
		StringStatus(bool ok=true);
		StringStatus(const StringStatus & other);
		StringStatus(const QDataStream & stream);
		StringStatus(bool ok, const QString & msg);
		bool ok()const { return m_ok; }
		QString msg()const { return m_msg; }
};
typedef StringStatus ReadStatus;
typedef ReadStatus WriteStatus;