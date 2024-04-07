#include <iostream>
#include <list>
#include "TPolinom.h"
#include "..\tablelib\Table.h"
#include <vector>

using namespace std;

class ListTable : public Table {
private:
    list<pair<KeyType, ValueType>> data;
    list<pair<KeyType, ValueType>>::iterator it;

public:
    int GetDataCount() const override {
        return (int)data.size();
    }

    bool IsEmpty() const override {
        return data.empty();
    }

    bool IsFull() const override {
        return false; // В линейной структуре списка проверка на полноту не требуется
    }

    ValueType* Find(const KeyType& key) override {
        for (auto& entry : data) {
            if (entry.first == key) {
                return &(entry.second);
            }
        }
        return nullptr;
    }

    void Insert(const KeyType& key, const ValueType& value) override {
        data.push_back(pair<KeyType, ValueType>(key, value));
    }

    void Delete(const KeyType& key) override {
        for (it = data.begin(); it != data.end(); ++it) {
            if (it->first == key) {
                data.erase(it);
                break;
            }
        }
    }

    int Reset() override {
        it = data.begin();
        return data.size();
    }

    bool IsTabEnded() const override {
        return it == data.end();
    }

    int GoNext() override {
        if (!IsTabEnded()) {
            ++it;
        }
        return data.size();
    }

    const KeyType& GetKey() const override {
        return it->first;
    }

    const ValueType* GetValuePtr() const override {
        return &(it->second);
    }
};

