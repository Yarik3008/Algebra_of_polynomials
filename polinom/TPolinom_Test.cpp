#include <iostream>
#include "TList.h"
#include "TMonom.h"
#include "TPolinom.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите полином:" << endl;
    string str;
    cin >> str;

    TPolinom p1(str);

    double x, y, z;
    std::cout << "Введите значения x, y, z для вычисления полинома в точке:" << std::endl;
    std::cin >> x >> y >> z;

    TPolinom resultPoint = p1.CalcPoint(x, y, z);
    std::cout << "Результат вычисления полинома в точке (" << x << ", " << y << ", " << z << "): " << resultPoint.ToString() << std::endl;

    TPolinom resultDerivative = p1.Derivative();
    std::cout << "Производная полинома: " << resultDerivative.ToString() << std::endl;

    TPolinom resultIntegral = p1.Integral();
    std::cout << "Интеграл полинома: " << resultIntegral.ToString() << std::endl;

    cout << "Введите второй полином:" << endl;
    string str2;
    cin >> str2;

    TPolinom p2(str2);

    TPolinom res;
    res = p1 + p2;

    TPolinom res1;
    res1 = p1 - p2;

    TPolinom res2;
    res2 = p1 / p2;

    TPolinom res3;
    res3 = p1 * p2;

    double constant = 5.0;
    TPolinom res4;
    res4 = p1 * constant; // умножение полинома на константу

    cout << "Результат сложения: " << res.ToString() << endl;
    cout << "Результат вычитания: " << res1.ToString() << endl;
    cout << "Результат деления: " << res2.ToString() << endl;
    cout << "Результат умножения: " << res3.ToString() << endl;
    cout << "Результат умножения на константу: " << res4.ToString() << endl;

    return 0;
}