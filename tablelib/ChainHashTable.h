#include "Table.h"
using namespace std;

class ChainHashTable : public Table {
private:
    struct Item {
        KeyType key;
        ValueType value;
        Item* next;

        Item(const KeyType& k, const ValueType& v, Item* n = nullptr)
            : key(k), value(v), next(n) {}
    };

    Item** table;
    int size;
    int count;
    int currentCount;
    int currentIndex;
    Item* currentItem;


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
        Item* item = table[hash];
        while (item && item->key != key) {
            item = item->next;
        }
        return item;
    }

public:
    ChainHashTable(int s = 15) {
        size = s;
        count = 0;
        table = new Item*[size];
        currentItem = nullptr;
        currentCount = 0;
        currentIndex = 0;
        for (int i = 0; i < size; ++i) {
            table[i] = nullptr;
        }
    }

    ~ChainHashTable() {
        for (int i = 0; i < size; ++i) {
            Item* item = table[i];
            while (item) {
                Item* next = item->next;
                delete item;
                item = next;
            }
        }
        delete[] table;
    }

    int GetDataCount() const override { return count; }
    bool IsEmpty() const override { return count == 0; }
    bool IsFull() const override { return false; }

    ValueType* Find(const KeyType& key) override {
        Item* item = FindItem(key);
        return item ? &item->value : nullptr;
    }

    void Insert(const KeyType& key, const ValueType& value) override {
        size_t hash = Hash(key);
        Item* item = new Item(key, value, table[hash]);
        table[hash] = item;
        count++;

        if (!currentItem) {
            currentItem = item;
            currentCount = 1;
            currentIndex = hash;
        }
    }

    void Delete(const KeyType& key) override {
        size_t hash = Hash(key);
        Item* prev = nullptr;
        Item* item = table[hash];
        while (item && item->key != key) {
            prev = item;
            item = item->next;
        }
        if (item) {
            if (prev) {
                prev->next = item->next;
            }
            else {
                table[hash] = item->next;
            }
            delete item;
            --count;
        }
    }

    int Reset() override {
        currentItem = nullptr;
        currentCount = 0;
        currentIndex = 0;
        return GoNext();
    }

    bool IsTabEnded() const override { return currentCount > count; }

    int GoNext() override {
        if (IsTabEnded()) return 0;
        
        if (currentItem && currentItem->next) {
            currentItem = currentItem->next;
            return ++currentCount;
        }

        do {
            ++currentIndex %= size;
        } while (table[currentIndex] == nullptr);

        currentItem = table[currentIndex];
        return ++currentCount;
    }

    const KeyType& GetKey() const override { return currentItem->key; }

    const ValueType* GetValuePtr() const override {
        return &currentItem->value;
    }
};
