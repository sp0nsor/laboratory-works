#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

void print_elements(unsigned i, unsigned size, vector<double>& v) {

	for (i; i < size; ++i) {

		cout << v[i] << " ";

	}

}

void negativ_print_elements(unsigned i, unsigned size, vector<double>& v) {

	for (unsigned i = size - 1; i > 0; i--) {

		cout << v[i] << " ";

	}

}

void main() {

	setlocale(LC_ALL, "ru");

	vector <double> V;
	fstream fin("data.txt");

	double tmp;
	while (fin >> tmp) {

		//enter_number(tmp);
		V.push_back(tmp);

	}
	fin.close();

	unsigned size = V.size();
	unsigned index = 0;
	unsigned negativ_index = 0;

	for (unsigned i = 0; i < size; i++) {

		if (V[i] < 0) {

			index = i;
			break;

		}

	}

	for (unsigned i = size - 1; i > 0; i--) {

		if (V[i] < 0) {

			negativ_index = i;
			break;

		}

	}

	cout << "номер первого отрицателььного " << index << endl;
	cout << "номер последнего отрицательного " << negativ_index << endl;
	cout << endl;
	cout << "начиная с первого отрицательного "; print_elements(index, size, V);
	cout << endl;
	cout << "начиная с последнего отрицательного "; negativ_print_elements(negativ_index, size, V);

}