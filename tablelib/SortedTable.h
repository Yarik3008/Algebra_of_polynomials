#pragma once
#include "..\tablelib\ArrayTable.h"
using namespace std;

class SortedTable : public ArrayTable {
public:
    SortedTable() : ArrayTable() {}

    void Insert(const KeyType& key, const ValueType& value) override {
        auto elm = pair<KeyType, ValueType>(const_cast<KeyType&>(key), const_cast<ValueType&>(value));
        for (auto& it = data.begin(); it < data.end(); it++) {
            if (it->first > key) {
                data.insert(it, elm);
                return;
            }
        }
        data.push_back(elm);
    }
};

