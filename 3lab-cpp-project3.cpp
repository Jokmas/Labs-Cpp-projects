#include <iostream>   // Ввод и вывод данных.
#include <string>     // Строки string и функция преобразования stoll().
#include <random>     // Генерация случайного числа.
#include <cctype>     // Проверка символов: isdigit() и isspace().
#include <stdexcept>  // Исключения invalid_argument и out_of_range.
#include <clocale>

using namespace std;

// Проверяет, что строка содержит целое число; знак +/- допустим, а пробелы разрешены только до и после числа.
bool isIntegerInput(const string& input) {

    size_t i = 0;

    // Пропускаем пробельные символы в начале строки.
    while (i < input.size() && isspace(static_cast<unsigned char>(input[i]))) {
        i++;
    }

    // Разрешаем один необязательный знак перед числом.
    if (i < input.size() && (input[i] == '+' || input[i] == '-')) {
        i++;
    }

    // Запоминаем место, с которого должны начинаться цифры.
    size_t digitStart = i;

    // Читаем подряд все цифры числа.
    while (i < input.size() &&
        isdigit(static_cast<unsigned char>(input[i]))) {
        i++;
    }

    // Если после возможного знака цифр нет, ввод некорректен.
    if (i == digitStart) {
        return false;
    }

    // После цифр пропускаем возможные пробелы в конце строки.
    while (i < input.size() && isspace(static_cast<unsigned char>(input[i]))) {
        i++;
    }
    // Вся строка должна быть разобрана; лишние символы запрещены.

    return i == input.size();
}

int main() {
    setlocale(LC_ALL, "ru");

    // Именованные константы задают допустимые границы игры.
    const int MIN_NUMBER = 1;

    const int MAX_NUMBER = 10;

    // Создаём генератор и равномерное распределение чисел.
    random_device rd;

    mt19937 generator(rd());

    uniform_int_distribution<int> distribution(

        MIN_NUMBER, MAX_NUMBER
    );

    // Загадываем случайное целое число от 1 до 10 включительно.
    const int secretNumber = distribution(generator);

    string input;

    cout << "=== Игра «Угадай число» ===" << endl;
    cout << "Я загадал число от " << MIN_NUMBER << " до " << MAX_NUMBER << "." << endl;
    cout << "Введите вашу догадку: ";

    // getline считывает всю строку, чтобы проверить и лишние символы.
    if (!getline(cin, input)) {
        cout << "Ошибка: не удалось прочитать ввод." << endl;

        return 1;
    }

    // Не разрешаем буквы, знаки и пробелы внутри числа.
    if (!isIntegerInput(input)) {
        cout << "Ошибка: введите одно целое число." << endl;

        return 1;
    }

    long long parsedNumber;
    size_t processed = 0;

    try {
        // Преобразуем строку в long long; processed хранит позицию,на которой закончилось преобразование.
        parsedNumber = stoll(input, &processed);

        // Пропускаем конечные пробелы после прочитанного числа.
        while (processed < input.size() && isspace(static_cast<unsigned char>(input[processed]))) {
            processed++;
        }

        // Дополнительная защита от непрочитанного остатка строки.
        if (processed != input.size()) {
            cout << "Ошибка: введены лишние символы." << endl;

            return 1;
        }
    }

    catch (const out_of_range&) {
        // stoll выбрасывает это исключение, если число слишком велико.
        cout << "Ошибка: введённое число слишком большое." << endl;

        return 1;
    }

    catch (const invalid_argument&) {
        // Защищаемся от строки, которую невозможно преобразовать в число.
        cout << "Ошибка: некорректный ввод." << endl;

        return 1;
    }

    // Проверяем границы до преобразования в int.
    if (parsedNumber < MIN_NUMBER || parsedNumber > MAX_NUMBER) {
        cout << "Ошибка: число должно быть от " << MIN_NUMBER << " до " << MAX_NUMBER << "." << endl;

        return 1;
    }

    // После проверки диапазона число безопасно помещается в int.
    int guess = static_cast<int>(parsedNumber);

    // Сравниваем догадку с загаданным числом и выбираем подсказку.
    if (guess == secretNumber) {

        cout << "Угадал!" << endl;
    }

    else if (guess < secretNumber) {
        // Загаданное число больше догадки: нужно назвать число больше.
        cout << "Больше" << endl;
    }

    else {
        // Загаданное число меньше догадки: нужно назвать число меньше.
        cout << "Меньше" << endl;
    }

    return 0;  // Успешное завершение.
}
