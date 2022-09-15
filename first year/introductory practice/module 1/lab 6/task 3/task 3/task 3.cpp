#include <iostream>
#include <vector>
#include <iterator>
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

void main() {

	setlocale(LC_ALL, "RU");

	unsigned Sqr;
	long double tmp;
	vector<long double> Population;
	vector<long double> Square;

	fstream in("population.txt");
	fstream fin("square.txt");

	while (in >> tmp) {

		Population.push_back(tmp);

	}
	in.close();
	while (fin >> tmp) {

		Square.push_back(tmp);

	}
	fin.close();

	//cout << Population.size() << " " << Square.size();

	cout << "введите площадь >> ";
	enter_number(Sqr);

	long double sum = 0;

	for (unsigned i = 0; i < Square.size(); i++) {

		if (Square[i] < Sqr) {

			sum += Population[i];

		}

	}

	cout << "общая численность населения = " << sum << " млн.ж" << endl;

	system("pause>>void");

}