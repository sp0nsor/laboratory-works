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
	
	unsigned N;
	unsigned quantity;

	cout << "введите количество конфет > ";
	enter_number(quantity);
	cout << "введите количество гостей > ";
	enter_number(N);

	unsigned tmp = quantity % N;
	unsigned zxc = quantity / N;

	if (quantity % N == 0) {

		cout << "все гости получили одинаковое количство конфет " << endl;
		cout << "Андрей не получил конфет." << endl;

	}
	else if (quantity < N) {

		cout << "не все гости получат конфеты " << endl;
		cout << N - quantity << " гостей не получат конфеты." << endl;
 
	}
	else if (quantity % N != 0  && quantity > N) {

		cout << "все гостии получили конфету" << endl;
		cout << "андрей съел " << tmp << " конфет" << endl;

	}

}