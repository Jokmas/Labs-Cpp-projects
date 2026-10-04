#include <iostream>
#include <clocale>
#include <iomanip> // Для форматирования вывода
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Использование const для констант (у куба 6 граней)
    const int f_count = 6;

    // Инициализация переменных
    double dedge;
    cout << "Введите длину ребра куба (вещественное число, например 5.77): ";
    cin >> dedge;

    // 1. Вычисления в типе double (без потери данных)
    double dvolume = dedge * dedge * dedge;
    double darea = f_count * dedge * dedge;

    // 2. Демонстрация ЯВНОГО приведения типов (static_cast) и вычисления в int
    // Происходит усечение дробной части (например, 5.7 превратится в 5)
    int iedge = static_cast<int>(dedge);
    int ivolume = iedge * iedge * iedge;
    int iarea = f_count * iedge * iedge;

    // Форматирование вывода: фиксированная точка, 2 знака после запятой
    cout << fixed << setprecision(2);

    cout << "Результаты вычислений (double) " << endl;
    cout << "Ребро: " << dedge << endl;
    cout << "Объем: " << dvolume << endl;
    cout << "Площадь поверхности: " << darea << endl;

    cout << "Результаты вычислений (int - после static_cast) " << endl;
    cout << "Ребро: " << iedge << endl;
    cout << "Объем: " << ivolume << endl;
    cout << "Площадь поверхности: " << iarea << endl;

    return 0;
}
