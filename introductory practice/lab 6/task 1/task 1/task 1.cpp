#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

void main() {

	setlocale(LC_ALL, "RU");

	try {

		vector<int> V;

		fstream fin("data.txt");
		if (fin.is_open()) {

			int ff;
			while (fin >> ff) {

				V.push_back(ff);

			}
			fin.close();

		}
		else {

			throw "ошибка открытия файла !";

		}

		vector<int>::iterator iter = V.begin();

		long int sum = 0;

		for (iter; iter != V.end(); ++iter) {

			sum += *iter;

		}

		if (sum > 0) {

			cout << endl;
			cout << "сумма элементов положительная. она равна " << sum << endl;

		}
		else {

			cout << endl;
			cout << "сумма элементов отрицательная. она равна " << sum << endl;

		}

	}
	catch (invalid_argument& error) {

		cout << error.what() << endl;

	}

	system("pause>>void");

}