#pragma once
#include <iostream>
#include <map>
#include "TPolinom.h"
#include <vector>
using namespace std;



// Замените типы KeyType и ValueType соответственно на типы ключей и значений, которые используете в вашей таблице
using KeyType = int; // пример типа ключа
using ValueType = string;

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
};

