//TopResult.h by Kostya Kozachuck as neurocod - 29.09.2011 3:03:53
//BSD license https://github.com/neurocod/Qqt
#pragma once

template<class Key, class Value>
class TopResult {
	protected:
		Key m_key;
		Value m_value;
		bool m_bInitialized;
	public:
		TopResult() { m_bInitialized = false; }
		TopResult(const Key key, const Value value):
				m_key(key), m_value(value), m_bInitialized(true) {
		}
		Key key()const { return m_key; }
		void setKey(Key key) { m_key = key; }
		Value value()const { return m_value; }
		void setValue(Value value) { m_value = value; }
		void addMaxKey(const Key key, const Value value) {
			if(!m_bInitialized || key>m_key) {
				m_bInitialized = true;
				m_key = key;
				m_value = value;
			}
		}
		void addMinKey(const Key key, const Value value) {
			if(!m_bInitialized || key<m_key) {
				m_bInitialized = true;
				m_key = key;
				m_value = value;
			}
		}
		void addMaxValue(const Key key, const Value value) {
			if(!m_bInitialized || value>m_value) {
				m_bInitialized = true;
				m_key = key;
				m_value = value;
			}
		}
		void addMinValue(const Key key, const Value value) {
			if(!m_bInitialized || value<m_value) {
				m_bInitialized = true;
				m_key = key;
				m_value = value;
			}
		}
		template<class T>
		void addMaxKeyByMap(const T & map) {
			for(auto it = map.begin(); it!=map.end(); ++it) {
				addMaxKey(it.key(), it.value());
			}
		}
		template<class T>
		void addMinKeyByMap(const T & map) {
			for(auto it = map.begin(); it!=map.end(); ++it) {
				addMinKey(it.key(), it.value());
			}
		}
		template<class T>
		void addMaxValueByMap(const T & map) {
			for(auto it = map.begin(); it!=map.end(); ++it) {
				addMaxValue(it.key(), it.value());
			}
		}
		template<class T>
		void addMinValueByMap(const T & map) {
			for(auto it = map.begin(); it!=map.end(); ++it) {
				addMinValue(it.key(), it.value());
			}
		}
};