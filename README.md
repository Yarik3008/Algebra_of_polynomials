# **Лабораторная работа №1 "Алгебра полиномов"**
## **Техническое задание**
### **Введение**

Проект, над которым мы работаем, это программа, которая поможет упростить работу с полиномами, содержащими три переменные. Основная задача проекта заключается в том, чтобы сделать математические вычисления более удобными и доступными для всех пользователей.

----

### **Общая информация о проекте и участниках**

#### **Длительность проекта**

:hourglass: Время выполнения проекта составит 8 недель весеннего семестра.


#### **Участники проекта**

:boom: Состав: Кондратьев Ярослав, Матюнина Александра, Майк Мурадов

----
### **Постановка задачи**

:pushpin: Разработать программную систему для выполнения алгебраических операций над полиномами от трех переменных.

-----------


### **Цели**
:black_square_button: Разработка программной системы, эффективно взаимодействующей с полиномами

:black_square_button: Обеспечение высокой производительности при выполнении основных операций над полиномами

:black_square_button: Сохранение точности и эффективности математических операций над полиномами

:black_square_button: Предоставление удобного интерфейса для пользователей работы с полиномами и их результатами

---------------

### **Условия и функциональные требования**
  
1. **Хранение полиномов**
   - Полиномы хранятся в виде списка.
   - Полиномы хранятся во всех таблицах одновременно.
   - Ключом является имя полинома.

2. **Виды таблиц**
   - Линейная таблица на массиве.
   - Линейная таблица на списке.
   - Упорядоченная таблица на массиве.
   - Дерево (АВЛ или красно-черное).
   - Две хэш-таблицы.

3. **Операции над отдельными полиномами**
   - Вычисление в точке.
   - Умножение на константу.
   - Производная.
   - Интеграл.

4. **Операции в выражениях из полиномов**
   - Сложение.
   - Вычитание.
   - Умножение на константу.
   - Умножение полиномов.
   - Деление полиномов.
   - Использование постфиксной формы.

5. **Операции над таблицами**
   - Добавление полинома (все таблицы одновременно).
   - Удаление полинома (все таблицы одновременно).
   - Поиск (только в активной таблице).
   - Вывод активной таблицы на экран (в формате: имя полинома, строковое представление полинома).
  
----

### **Пример**

Пусть к настоящему моменту в таблицах хранятся полиномы, указанные ниже: 

```
pol1 = 3.2x²y³z - 1.3x¹z⁴  
pol2 = -3.2x²y³z + 1.3x¹z⁴  
const6 = 6.0  
q = 4.0x²
```


Пусть введено следующее выражение: `new_pol = 2 * pol1 + 2 * pol2 + 3.6 * q – const6`

#### **Требования к примеру**

Требуется:

- Найти в активной таблице все полиномы (сообщить об ошибке при необходимости).
- Сформировать новый полином, вычислив выражение. В данном случае должен получиться полином `new_pol = 14.4x2 – 6.0`.
- Добавить новый полином во все таблицы.

