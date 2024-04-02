#include "..\tablelib\Table.h"
#include "..\tablelib\ArrayTable.h"
#include "..\tablelib\ListTable.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    ArrayTable arrayTable;

    // Вставляем элементы в массивную таблицу
    arrayTable.Insert(1, "Value1");
    arrayTable.Insert(2, "Value2");
    arrayTable.Insert(3, "Value3");

    // Выводим массивную таблицу на экран
    cout << arrayTable;

    ListTable listTable;

    // Вставляем элементы в список
    listTable.Insert(10, "key1");
    listTable.Insert(20, "key2");
    listTable.Insert(30, "key3");

    // Ищем значение по ключу
    const int* value = nullptr;
    ValueType* ptrValue = listTable.Find(20);
    if (ptrValue) {
        value = reinterpret_cast<const int*>(ptrValue);
        cout << "Значение для ключа 20: " << *value << endl;
    }
    else {
        cout << "Ключ 20 не найден." << endl;
    }

    // Удаляем элемент
    listTable.Delete(10);

    // Выводим все элементы таблицы
    cout << "Table contents:" << endl;
    for (listTable.Reset(); !listTable.IsTabEnded(); listTable.GoNext()) {
        cout << "Key: " << listTable.GetKey() << ", Value: " << *listTable.GetValuePtr() << endl;
    }

    return 0;
}