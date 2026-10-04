#include <iostream>
#include <clocale>                             //Подключаем библиотеку для локализации
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");             //Включаем поддержку русского языка в консоли
    
    cout << "Площадь круга" << endl;           //Выводим название программы

    double radius;                                  //Объявляем переменные для радиуса и площади
    double area;

    double Pi = 3.14;                          //Число пи

    cout << "Введите радиус: ";                //Просим пользователя ввести радиус
    cin >> radius;

    if (cin.fail()) {
        cout << "Ошибка! Вы ввели не число." << endl;      //Проверка на ввод буквы вместо числа
        return 1;
    }

    area = Pi * radius * radius;                            //Считаем площадь по формуле (пи * радиус в квадрате)

    cout << "Площадь: " << area << endl;          //Выводим результат вычисления

    return 0;
}
