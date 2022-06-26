#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

int print_by_max(int a, int b, int c) {

	if (a > b && a > c) {
		cout << "максибальное число жильцов в доме 1 оно состовляет  ";
		return a;
	}
	if (b > a && b > c) {
		cout << "максибальное число жильцов в доме 2 оно состовляет  ";
		return b;
	}
	if (c > a && c > b) {
		cout << "максибальное число жильцов в доме 3 оно состовляет  ";
		return c;
	}

}

void main() {

	setlocale(LC_ALL, "ru");

	try {

		ifstream fin("home1.txt");
		vector<int> V1;
		int ff;
		if (fin.is_open()) {

			while (fin >> ff) {

				V1.push_back(ff);

			}
			fin.close();
		}
		else {
			throw "ошибка открытия файла !";
		}
		ifstream qin("home2.txt");
		vector <int> V2;
		int tt;
		if (qin.is_open()) {

			while (qin >> tt) {

				V2.push_back(tt);

			}
			qin.close();

		}
		else {
			throw "ошибка открытия файла !";
		}
		ifstream win("home3.txt");
		vector<int> V3;
		int vv;
		if (win.is_open()) {

			while (win >> vv) {

				V3.push_back(vv);

			}
			win.close();

		}
		else {
			throw "ошибка открытия файла !";
		}

		int a = V1.size();
		int b = V2.size();
		int c = V3.size();

		cout << print_by_max(a, b, c) << endl;

	}

	catch (invalid_argument& error) {

		cout << error.what() << endl;

	}

	system("pause>>void");

}