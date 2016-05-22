//TopResult.h by Kostya Kozachuck as neurocod - 29.09.2011 3:03:53
#pragma once

template<class Key, class Value>
class TopResult {
	protected:
		Key _key;
		Value _value;
		bool _isSet = false;
	public:
		TopResult() {}
		TopResult(const Key & key, const Value & value):
				_key(key), _value(value), _isSet(true) {
		}
		bool isSet()const { return _isSet; }
		Key key()const { return _key; }
		void setKey(const Key & key) { _key = key; }
		Value value()const { return _value; }
		void setValue(const Value & value) { _value = value; }
		bool addMaxKey(const Key & key, const Value & value) {
			if(!_isSet || key>_key) {
				_isSet = true;
				_key = key;
				_value = value;
				return true;
			}
			return false;
		}
		bool addMinKey(const Key & key, const Value & value) {
			if(!_isSet || key<_key) {
				_isSet = true;
				_key = key;
				_value = value;
				return true;
			}
			return false;
		}
		bool addMaxValue(const Key & key, const Value & value) {
			if(!_isSet || value>_value) {
				_isSet = true;
				_key = key;
				_value = value;
				return true;
			}
			return false;
		}
		bool addMinValue(const Key & key, const Value & value) {
			if(!_isSet || value<_value) {
				_isSet = true;
				_key = key;
				_value = value;
				return true;
			}
			return false;
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
