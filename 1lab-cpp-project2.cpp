#include <iostream>
#include <clocale>                           //Подключаем библиотеку для локализации
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");            //Включаем поддержку русского языка в консоли

    double price, weight, t_cost;            //Объявляем переменные для цены, массы и итоговой стоимости

    cout << "Введите цену: ";                //Просим пользователя ввести цену
    cin >> price;

    cout << "Введите массу: ";                 //Просим пользователя ввести массу
    cin >> weight;

    if (cin.fail()) {
        cout << "Ошибка! Вы ввели не число." << endl;      //Проверка на ввод буквы вместо числа
        return 1;
    }

    t_cost = price * weight;                 //Вычисляем итоговую стоимость

    cout << "Итоговая стоимость: " << t_cost << " руб." << endl;          //Выводим результат

    return 0;
}
