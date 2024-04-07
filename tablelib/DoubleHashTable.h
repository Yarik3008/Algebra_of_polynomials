#include "Table.h"
using namespace std;


class DoubleHashTable : public Table {
private:
    struct Item {
        KeyType key;
        ValueType value;

        Item() : key(KeyType()), value(ValueType()) {}
        Item(const KeyType& k, const ValueType& v)
            : key(k), value(v) {}
    };

    Item* table;
    int size;
    int count;
    int currentPos;
    int currentCount;
         
    int Hash(const KeyType& key) const {
        // Хеш-функция
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % size;
    }

    Item* FindItem(const KeyType& key) const {
        size_t hash = Hash(key);
        while (table[hash].key != KeyType() && table[hash].key != key) {
            hash = (1 + hash) % size;
        }
        if (table[hash].key == KeyType()) return nullptr;
        return &table[hash];
    }

public:
    DoubleHashTable(int s = 100) {
        size = s;
        count = 0;
        currentPos = -1;
        currentCount = 0;
        table = new Item[size];
    }

    ~DoubleHashTable() {
        delete[] table;
    }

    int GetDataCount() const override { return count; }
    bool IsEmpty() const override { return count == 0; }
    bool IsFull() const override { return count == size; }

    ValueType* Find(const KeyType& key) override {
        Item* item = FindItem(key);
        return (item && item->key != KeyType()) ? &item->value : nullptr;
    }

    void Insert(const KeyType& key, const ValueType& value) override {
        if (IsFull())
            return;

        size_t hash = Hash(key);
        while (table[hash].key != KeyType() && table[hash].key != key) {
            hash = (1 + hash) % size;
        }
        table[hash] = Item(key, value);
        count++;
        if (currentPos == -1)
            currentPos = hash;
    }

    void Delete(const KeyType& key) override {
        size_t hash = Hash(key);
        
        while (table[hash].key != KeyType() && table[hash].key != key) {
            hash = (1 + hash) % size;
        }

        if (table[hash].key != KeyType()) {
            table[hash].key = KeyType();
            table[hash].value = ValueType();
            --count;
        }
    }

    int Reset() override {
        currentPos = 0;
        currentCount = 0;
        if (table[currentPos].key != KeyType())
            return ++currentCount;
        return GoNext();
    }

    bool IsTabEnded() const override { return currentCount > count; }

    int GoNext() override {
        if (IsTabEnded()) return 0;
        do {
            ++currentPos %= size;

        } while (table[currentPos].key == KeyType());
        return ++currentCount;
    }

    const KeyType& GetKey() const override { return table[currentPos].key; }

    const ValueType* GetValuePtr() const override {
        return &table[currentPos].value;
    }
};
