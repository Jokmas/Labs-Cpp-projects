#include <iostream>
#include <clocale>
#include <iomanip> // Для форматирования точности вывода (setprecision)

int main() {
    setlocale(LC_ALL, "ru");

    long long totalSeconds;

    std::cout << " Конвертер времени " << std::endl;
    std::cout << "Введите количество секунд (целое положительное число): ";
    std::cin >> totalSeconds;

    // 1. ОБРАБОТКА ОШИБОК ВВОДА БЕЗ <limits>
    if (std::cin.fail() || totalSeconds < 0) {
        std::cin.clear();            // Сбрасываем флаг ошибки потока
        std::cin.ignore(10000, '\n'); // Очищаем буфер (удаляем до 10 000 символов до Enter)
        std::cout << "Ошибка: введено некорректное значение или отрицательное число!" << std::endl;
        return 1;
    }

    // 2. ИМЕНОВАННЫЕ КОНСТАНТЫ 
    const int SECONDS_IN_DAY = 86400; // 24 * 60 * 60
    const int SECONDS_IN_HOUR = 3600; // 60 * 60
    const int SECONDS_IN_MINUTE = 60;

    // 3. ЦЕЛОЧИСЛЕННАЯ АРИФМЕТИКА 
    int days = static_cast<int>(totalSeconds / SECONDS_IN_DAY);
    long long remainder = totalSeconds % SECONDS_IN_DAY;

    int hours = static_cast<int>(remainder / SECONDS_IN_HOUR);
    remainder = remainder % SECONDS_IN_HOUR;

    int minutes = static_cast<int>(remainder / SECONDS_IN_MINUTE);
    int seconds = static_cast<int>(remainder % SECONDS_IN_MINUTE);

    // Вывод результата
    std::cout << "\nРезультат перевода:" << std::endl;
    std::cout << days << " дней : "
        << hours << " часов : "
        << minutes << " минут : "
        << seconds << " секунд." << std::endl;

    // 4. АНАЛИЗ ПОТЕРИ ТОЧНОСТИ (float vs double)
    float floatDays = static_cast<float>(totalSeconds) / SECONDS_IN_DAY;
    double doubleDays = static_cast<double>(totalSeconds) / SECONDS_IN_DAY;

    std::cout << "\n Анализ точности " << std::endl;
    std::cout << "Дни (float):  " << std::fixed << std::setprecision(8) << floatDays << std::endl;
    std::cout << "Дни (double): " << std::fixed << std::setprecision(8) << doubleDays << std::endl;

    return 0;
}
