#include <iostream>
#include <clocale>
using namespace std;

int main() {
    // Настройка кодировки для корректного отображения русского языка в консоли Windows
    setlocale(LC_ALL, "ru");

    // Объявляем и инициализируем переменные. 
    // Выбран тип double, так как длина ребра может быть дробным числом (например: 1.3)
    double edge;
    double volume;

    // Просим пользователя ввести значение для переменной edge
    cout << "Введите длину ребра куба: ";
    cin >> edge;

    // Корректное выполнение арифметических операций
    volume = edge * edge * edge;

    // Вывод результата
    cout << "Объем куба равен: " << volume << endl;

    return 0;
}
