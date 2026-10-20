#include <iostream>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int number;

	cout << "Введите целое число: ";
	// Проверяем, ввели целое число или нет

	if (!(std::cin >> number)) {
		std::cout << "Ошибка: введите целое число." << std::endl;

		return 1;  // Завершаем программу при некорректном вводе.
	}

	// Остаток от деления на 2 равен нулю у чётных чисел.
	if (number % 2 == 0) {
		std::cout << "Чётное" << std::endl;
	}

	else {
		// Эта ветвь выполняется для нечётного числа.
		std::cout << "Нечётное" << std::endl;
	}

	return 0;  // Успешное завершение программы.

}
