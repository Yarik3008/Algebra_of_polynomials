#include "../tablelib/PolinomTableController.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    PolinomTableController controller;
    
    // Создаем таблицы и добавляем их в контроллер
    controller.AddTable("array", new ArrayTable());
    controller.AddTable("sorted", new SortedTable());
    controller.AddTable("list", new ListTable());
    controller.AddTable("chain_hash", new ChainHashTable());
    controller.AddTable("double_hash", new DoubleHashTable());
    controller.AddTable("avl", new AVLTable());

    // Вставляем элементы в таблицы
    controller.Insert("pol2", TPolinom("3,2x^2y^3z^1-1,3x^1z^4"));
    controller.Insert("pol1", TPolinom("-3,2x^2y^3z^1+1,3x^1z^4"));
    controller.Insert("const6", TPolinom("6,0"));
    controller.Insert("q", TPolinom("4,0x^2"));

    controller.Insert("new_pol", "2 * pol1 + 2 * pol2 + 3,6 * q - const6");

    // Выводим все таблицы на экран
    controller.PrintAllTables(cout);

    // Ищем значение по ключу в активной таблице
    ValueType* ptrValue = controller.Find("pol2");
    if (ptrValue) {
        cout << "Значение для ключа \"pol2\": " << *ptrValue << endl;
    }
    else {
        cout << "Ключ \"pol2\" не найден." << endl;
    }

    // Удаляем элемент из всех таблиц
    controller.Delete("pol1");

    // Выводим все элементы активной таблицы
    controller.ChangeActiveTable("avl");
    cout << "Удаление pol1:" << endl << controller;

    return 0;
}