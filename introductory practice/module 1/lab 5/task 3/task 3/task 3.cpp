#include <iostream>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

int number_of_digits(unsigned qwe) {

	unsigned cnt = 0;

	while (qwe > 0) {

		qwe /= 10;
		cnt++;

	}

	return cnt;

}

void main() {

	setlocale(LC_ALL, "ru");

	unsigned tmp;
	unsigned zxc;

	cout << "введите первое число >> ";
	enter_number(tmp);
	cout << "введите второе число >> ";
	enter_number(zxc);

	if (number_of_digits(tmp) > number_of_digits(zxc)) {

		cout << "в первом числе цифр больше " << endl;

	}
	else if (number_of_digits(tmp) < number_of_digits(zxc)) {

		cout << "в первом числе цифр меньше " << endl;

	}
	else if (number_of_digits(tmp) == number_of_digits(zxc)) {

		cout << "количество цифр одинаковое " << endl;

	}

}