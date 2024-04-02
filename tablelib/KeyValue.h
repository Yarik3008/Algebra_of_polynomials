#pragma once
#include <iostream>
#include <string>
#include "..\tablelib\Table.h"

using namespace std;

template <typename KeyType, typename ValueType>
class KeyValue {
private:
    KeyType key;
    ValueType value;

public:
    KeyValue(const KeyType& k, const ValueType& v) : key(k), value(v) {}

    KeyType getKey() const {
        return key;
    }

    void setKey(const KeyType& k) {
        key = k;
    }

    ValueType getValue() const {
        return value;
    }

    void setValue(const ValueType& v) {
        value = v;
    }


};
