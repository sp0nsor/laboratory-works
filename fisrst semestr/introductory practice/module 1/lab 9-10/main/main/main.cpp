#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

#include "County.h";
#include "ioCountry.h"

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

	unsigned int range1;
	unsigned int range2;
	static const string file_name = "data.txt";

	cout << "введите минимальный диопазон >> ";
	enter_number(range1);
	cout << "введите максимальный диопазон >> ";
	enter_number(range2);

	Country country;

	ifstream fin(file_name);
	fin >> country;
	fin.close();

	country.print_by_population(range1, range2);
	country.sort();


}