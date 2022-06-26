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

void main() {

	setlocale(LC_ALL, "ru");

	unsigned price;

flag:

	cout << "введите стоимость товара в копейках > ";
	enter_number(price);

	if (price >= 1 && price <= 9999) {

		double res;

		res = price / 100;

		double res2;

		res2 = price % 100;

		cout << "стоимость товара " << res << "руб. " << res2 << "коп." << endl;


	}
	else {

		cout << "введена некоректная стоимость. повторите ввод!" << endl;
		goto flag;

	}

	system("pause>>void");
	
}