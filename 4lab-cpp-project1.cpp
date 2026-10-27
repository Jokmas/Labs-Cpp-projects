#include <iostream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "ru");

    int operationCode;
    double firstNumber;
    double secondNumber;

    std::cout << "== АРИФМЕТИЧЕСКИЙ КАЛЬКУЛЯТОР ==\n";
    std::cout << "1. Сложение\n";
    std::cout << "2. Вычитание\n";
    std::cout << "3. Умножение\n";
    std::cout << "4. Деление\n";
    std::cout << "Выберите операцию от 1 до 4: ";

    if (!(std::cin >> operationCode)) {
        std::cout << "Ошибка: введите целочисленный код операции.\n";
        return 1;
    }

    // Запрашиваем числа только для операций, указанных в меню.
    // Любой другой код операции обрабатывается веткой default.
    if (operationCode >= 1 && operationCode <= 4) {
        std::cout << "Введите два числа: ";

        if (!(std::cin >> firstNumber >> secondNumber)) {
            std::cout << "Ошибка: введите два корректных числа.\n";
            return 1;
        }
    }

    // Оператор switch выбирает действие по целочисленному коду операции.
    switch (operationCode) {
    case 1: // Сложение двух чисел.
        std::cout << "Результат: "
            << firstNumber + secondNumber << '\n';
        break;

    case 2: // Вычитание второго числа из первого.
        std::cout << "Результат: "
            << firstNumber - secondNumber << '\n';
        break;

    case 3: // Умножение двух чисел.
        std::cout << "Результат: "
            << firstNumber * secondNumber << '\n';
        break;

    case 4: // Деление с проверкой делителя.
        if (secondNumber == 0.0) {
            std::cout << "Ошибка: деление на ноль невозможно.\n";
        }
        else {
            std::cout << "Результат: "
                << firstNumber / secondNumber << '\n';
        }
        break;

    default: // Обработка неизвестной операции.
        std::cout << "Ошибка: неизвестная операция.\n";
        break;
    }

    return 0;
}
