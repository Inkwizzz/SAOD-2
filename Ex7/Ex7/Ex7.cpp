#include <iostream>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Функция для вывода set на консоль в строку
string toString(const set<int>& s)
{
    string result = "{ ";
    for (int x : s)
    {
        result += to_string(x) + " ";
    }
    result += "}";
    return result;
}

// Функция для вывода unordered_set на консоль в строку
string toString(const unordered_set<int>& s)
{
    string result = "{ ";
    for (int x : s)
    {
        result += to_string(x) + " ";
    }
    result += "}";
    return result;
}

// Оператор для объединения двух объектов set
set<int> operator+(const set<int>& a, const set<int>& b)
{
    set<int> result = a;
    for (int x : b)
    {
        result.insert(x);
    }
    return result;
}

// Оператор для пересечения двух объектов set
set<int> operator*(const set<int>& a, const set<int>& b)
{
    set<int> result;
    for (int x : a)
    {
        if (b.count(x) > 0)
        {
            result.insert(x);
        }
    }
    return result;
}

// Оператор для объединения двух объектов unordered_set
unordered_set<int> operator+(const unordered_set<int>& a, const unordered_set<int>& b)
{
    unordered_set<int> result = a;
    for (int x : b)
    {
        result.insert(x);
    }
    return result;
}

// Оператор для пересечения двух объектов unordered_set
unordered_set<int> operator*(const unordered_set<int>& a, const unordered_set<int>& b)
{
    unordered_set<int> result;
    for (int x : a)
    {
        if (b.count(x) > 0)
        {
            result.insert(x);
        }
    }
    return result;
}

int main()
{
    // Инициализация генератора случайных чисел
    srand(time(nullptr));

    // Создание объектов set и unordered_set
    set<int> s;
    unordered_set<int> us;

    // Заполнение объектов случайными числами
    for (int i = 0; i < 15; i++)
    {
        int x = rand() % 100;
        s.insert(x);
        us.insert(x);
    }

    // Вывод на консоль заполненных объектов
    cout << "s = " << toString(s) << endl;
    cout << "us = " << toString(us) << endl;

    // Объединение и пересечение объектов set
    set<int> a = { 1, 2, 3, 4, 5 };
    set<int> b = { 3, 4, 5, 6, 7 };
    set<int> c = a + b;
    set<int> d = a * b;
    cout << "a = " << toString(a) << endl;
    cout << "b = " << toString(b) << endl;
    cout << "a + b = " << toString(c) << endl;
    cout << "a * b = " << toString(d) << endl;

    // Объединение и пересечение объектов unordered_set
    unordered_set<int> ua = { 1, 2, 3, 4, 5 };
    unordered_set<int> ub = { 3, 4, 5, 6, 7 };
    unordered_set<int> uc = ua + ub;
    unordered_set<int> ud = ua * ub;
    cout << "ua = " << toString(ua) << endl;
    cout << "ub = " << toString(ub) << endl;
    cout << "ua + ub = " << toString(uc) << endl;
    cout << "ua * ub = " << toString(ud) << endl;

    return 0;
}