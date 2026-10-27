#include <iostream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "ru");

    char operation;
    double firstNumber;
    double secondNumber;

    std::cout << "===== КАЛЬКУЛЯТОР С ВЫБОРОМ ОПЕРАЦИИ =====\n";
    std::cout << "Доступные операции: +, -, *, /\n";
    std::cout << "Для умножения также можно использовать x или X.\n";
    std::cout << "Для деления также можно использовать :\n";
    std::cout << "Введите знак операции: ";

    if (!(std::cin >> operation)) {
        std::cout << "Ошибка: необходимо ввести знак операции.\n";
        return 1;
    }

    std::cout << "Введите два числа: ";

    if (!(std::cin >> firstNumber >> secondNumber)) {
        std::cout << "Ошибка: введите два корректных числа.\n";
        return 1;
    }

    // Тип char используется, поскольку операция обозначается одним символом.
    switch (operation) {
    case '+': // Сложение двух чисел.
        std::cout << "Результат: "
            << firstNumber + secondNumber << '\n';
        break;

    case '-': // Вычитание второго числа из первого.
        std::cout << "Результат: "
            << firstNumber - secondNumber << '\n';
        break;

        // Несколько вариантов обозначают умножение.
    case '*':
    case 'x':
    case 'X':
        std::cout << "Результат: "
            << firstNumber * secondNumber << '\n';
        break;

        // Несколько вариантов обозначают деление.
    case '/':
    case ':':
        if (secondNumber == 0.0) {
            std::cout << "Ошибка: деление на ноль невозможно.\n";
        }
        else {
            std::cout << "Результат: "
                << firstNumber / secondNumber << '\n';
        }
        break;

    default: // Обработка неподдерживаемого знака операции.
        std::cout << "Ошибка: неизвестный знак операции.\n";
        break;
    }

    return 0;
}
