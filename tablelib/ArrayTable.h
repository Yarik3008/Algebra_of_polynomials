#pragma once
#include <iostream>
#include <vector>
#include "..\tablelib\Table.h"
using namespace std;


class ArrayTable : public Table {
private:
    vector<pair<KeyType, ValueType>> data;
    size_t currentIndex;

public:
    ArrayTable() : currentIndex(0) {}

    int GetDataCount() const override {
        return (int)data.size();
    }

    bool IsEmpty() const override {
        return data.empty();
    }

    bool IsFull() const override {
        // В случае массива, с ограниченным размером, можно проверять на полноту
        return false;
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
        data.emplace_back(key, value);
    }

    void Delete(const KeyType& key) override {
        data.erase(remove_if(data.begin(), data.end(),
            [key](const pair<KeyType, ValueType>& entry) {
                return entry.first == key;
            }),
            data.end());
    }

    int Reset() override {
        currentIndex = 0;
        return (int)data.size();
    }

    bool IsTabEnded() const override {
        return currentIndex >= data.size();
    }

    int GoNext() override {
        currentIndex++;
        return (int)data.size();
    }

    const KeyType& GetKey() const override {
        return data[currentIndex].first;
    }

    const ValueType* GetValuePtr() const override {
        return &(data[currentIndex].second);
    }
    friend ostream& operator<<(ostream& os, ArrayTable& tab)
    {
        cout << "Table printing" << endl;
        for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext())
        {
            os << " Key: " << tab.GetKey() << " Val: ";
            tab.GetValuePtr()->PrintPolinom(os);
            os << endl;
        }
        return os;
    }
};

