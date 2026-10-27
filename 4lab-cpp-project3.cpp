#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <clocale>

constexpr double ABS_ZERO_C = -273.15;
constexpr double ABS_ZERO_F = -459.67;
constexpr double F_OFFSET = 32.0;

// Названия единиц измерения для каждой категории.
const char* units[4][4] = {
    {"метр (м)", "сантиметр (см)", "километр (км)", "миллиметр (мм)"},
    {"килограмм (кг)", "грамм (г)", "тонна (т)", "миллиграмм (мг)"},
    {"секунда (с)", "минута (мин)", "час (ч)", "сутки (сут)"},
    {"градус Цельсия (°C)", "градус Фаренгейта (°F)", "кельвин (К)", ""}
};

// Возвращает число единиц в категории.
int unitCount(int category) {
    return category == 4 ? 3 : 4;
}

// Проверяет корректность целочисленного ввода.
int readInt(const std::string& prompt, int min, int max) {
    while (true) {
        int value;
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cout << "Ошибка: введите целое число.\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );
            continue;
        }

        std::string rest;
        std::getline(std::cin, rest);

        if (rest.find_first_not_of(" \t\r") != std::string::npos) {
            std::cout << "Ошибка: лишние символы после числа.\n";
            continue;
        }

        if (value < min || value > max) {
            std::cout << "Введите число от " << min
                << " до " << max << ".\n";
            continue;
        }

        return value;
    }
}

// Проверяет ввод единицы: 0 — выход, 9 — назад.
int readUnitChoice(const std::string& prompt, int maxUnit) {
    while (true) {
        int choice = readInt(prompt, 0, 9);

        if (choice == 0 || choice == 9 ||
            (choice >= 1 && choice <= maxUnit)) {
            return choice;
        }

        std::cout << "Такой единицы нет в меню. Повторите ввод.\n";
    }
}

// Считывает корректное конечное число.
double readDouble() {
    while (true) {
        double value;
        std::cout << "Введите значение: ";
        std::cin >> value;

        if (std::cin.fail()) {
            std::cout << "Ошибка: введите число.\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );
            continue;
        }

        std::string rest;
        std::getline(std::cin, rest);

        if (rest.find_first_not_of(" \t\r") != std::string::npos ||
            !std::isfinite(value)) {
            std::cout << "Ошибка: некорректное значение.\n";
            continue;
        }

        return value;
    }
}

// Выводит меню единиц измерения.
void showUnits(int category) {
    std::cout << "\nЕдиницы измерения:\n";

    for (int i = 0; i < unitCount(category); ++i) {
        std::cout << i + 1 << " — "
            << units[category - 1][i] << '\n';
    }
}

// Переводит исходное значение в базовую единицу.
bool toBase(int category, int unit, double value, double& base) {
    // switch выбирает вариант по целочисленному коду.
    // Для double и string в качестве выражения switch не подходит.
    switch (category) {
    case 1:
        switch (unit) {
        case 1: base = value; break;
        case 2: base = value / 100.0; break;
        case 3: base = value * 1000.0; break;
        case 4: base = value / 1000.0; break;
        default: return false;
        }
        break;

    case 2:
        switch (unit) {
        case 1: base = value; break;
        case 2: base = value / 1000.0; break;
        case 3: base = value * 1000.0; break;
        case 4: base = value / 1000000.0; break;
        default: return false;
        }
        break;

    case 3:
        switch (unit) {
        case 1: base = value; break;
        case 2: base = value * 60.0; break;
        case 3: base = value * 3600.0; break;
        case 4: base = value * 86400.0; break;
        default: return false;
        }
        break;

    case 4:
        switch (unit) {
        case 1: base = value; break;
        case 2: base = (value - F_OFFSET) * 5.0 / 9.0; break;
        case 3: base = value + ABS_ZERO_C; break;
        default: return false;
        }
        break;

    default:
        return false;
    }

    return true;
}

// Переводит базовую единицу в целевую.
bool fromBase(int category, int unit, double base, double& result) {
    switch (category) {
    case 1:
        switch (unit) {
        case 1: result = base; break;
        case 2: result = base * 100.0; break;
        case 3: result = base / 1000.0; break;
        case 4: result = base * 1000.0; break;
        default: return false;
        }
        break;

    case 2:
        switch (unit) {
        case 1: result = base; break;
        case 2: result = base * 1000.0; break;
        case 3: result = base / 1000.0; break;
        case 4: result = base * 1000000.0; break;
        default: return false;
        }
        break;

    case 3:
        switch (unit) {
        case 1: result = base; break;
        case 2: result = base / 60.0; break;
        case 3: result = base / 3600.0; break;
        case 4: result = base / 86400.0; break;
        default: return false;
        }
        break;

    case 4:
        switch (unit) {
        case 1: result = base; break;
        case 2: result = base * 9.0 / 5.0 + F_OFFSET; break;
        case 3: result = base - ABS_ZERO_C; break;
        default: return false;
        }
        break;

    default:
        return false;
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "ru");

    std::cout << "===== КОНВЕРТЕР ЕДИНИЦ ИЗМЕРЕНИЯ =====\n";

    while (true) {
        std::cout << "\nГлавное меню:\n"
            << "1 — Длина\n"
            << "2 — Масса\n"
            << "3 — Время\n"
            << "4 — Температура\n"
            << "0 — Выход из программы\n";

        int category = readInt("Выберите категорию: ", 0, 4);

        if (category == 0) {
            std::cout << "Программа завершена.\n";
            return 0;
        }

        bool backToMain = false;

        while (!backToMain) {
            showUnits(category);

            int from = readUnitChoice(
                "Исходная единица (0 — выход, 9 — главное меню): ",
                unitCount(category)
            );

            if (from == 0) {
                std::cout << "Программа завершена.\n";
                return 0;
            }

            if (from == 9) {
                break;
            }

            while (true) {
                showUnits(category);

                int to = readUnitChoice(
                    "Целевая единица (0 — выход, 9 — назад): ",
                    unitCount(category)
                );

                if (to == 0) {
                    std::cout << "Программа завершена.\n";
                    return 0;
                }

                if (to == 9) {
                    break;
                }
                // Получаем значение и проверяем его допустимость.
                double value = readDouble();
                bool valid = true;
                // if-else удобен для составных условий и диапазонов.
                if (category != 4 && value < 0.0) {
                    valid = false;
                }
                else if (category == 4) {
                    if (from == 1 && value < ABS_ZERO_C)
                        valid = false;
                    else if (from == 2 && value < ABS_ZERO_F)
                        valid = false;
                    else if (from == 3 && value < 0.0)
                        valid = false;
                }

                if (!valid) {
                    std::cout << "Недопустимое значение. Попробуйте снова.\n";
                    continue;
                }
                double base = 0.0;
                double result = 0.0;

                if (!toBase(category, from, value, base) ||
                    !fromBase(category, to, base, result)) {
                    std::cout << "Ошибка преобразования.\n";
                    continue;
                }
                std::cout << std::fixed << std::setprecision(4)
                    << value << " "
                    << units[category - 1][from - 1]
                    << " = " << result << " "
                    << units[category - 1][to - 1] << '\n';
                std::cout << "\nЧто делать дальше?\n"
                    << "1 — Новая конвертация\n"
                    << "2 — Главное меню\n"
                    << "0 — Завершить программу\n";

                int action = readInt("Ваш выбор: ", 0, 2);
                if (action == 0) {
                    std::cout << "Программа завершена.\n";
                    return 0;
                }
                if (action == 1) {
                    // Выходим к выбору исходной единицы.
                    break;
                }
                if (action == 2) {
                    backToMain = true;
                    break;
                }
            }
        }
    }
}
