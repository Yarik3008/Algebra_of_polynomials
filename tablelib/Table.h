#pragma once
#include "TPolinom.h"
using namespace std;

using KeyType = string;
using ValueType = TPolinom;

class Table {
public:
    // информационные методы
    virtual int GetDataCount() const = 0; // количество записей
    virtual bool IsEmpty() const = 0;     // пуста?
    virtual bool IsFull() const = 0;      // заполнена?

    // основные методы
    virtual ValueType* Find(const KeyType& key) = 0;   // найти запись
    virtual void Insert(const KeyType& key, const ValueType& value) = 0; // вставить
    virtual void Delete(const KeyType& key) = 0;       // удалить запись

    // навигация
    virtual int Reset() = 0;         // установить на первую запись
    virtual bool IsTabEnded() const = 0;  // таблица завершена?
    virtual int GoNext() = 0;         // переход к следующей записи

    // доступ
    virtual const KeyType& GetKey() const = 0;
    virtual const ValueType* GetValuePtr() const = 0;

    virtual ~Table() = default;  // Виртуальный деструктор
    
    friend ostream& operator<<(ostream& os, Table& cont);
};

ostream& operator<<(ostream& os, Table& tab) {
    for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext())
    {
    os << " Key: " << tab.GetKey() << " Val: " << *tab.GetValuePtr() << endl;
    }
    return os;
}