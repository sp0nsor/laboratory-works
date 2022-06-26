#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

void main() {

	setlocale(LC_ALL, "ru");

	try {

		const int size = 20;
		int* arr = new int[size];
		ifstream fin("data.txt");
		if (fin.is_open()) {

			for (unsigned int i = 0; i < size; i++) {

				fin >> arr[i];

			}
			fin.close();

			for (unsigned int i = 0; i < size; i++) {

				if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0) {

					cout << "нормера лементов " << i << " и " << i + 1 << endl;
					break;

				}

			}

		}
		else {

			cout << "ошибка открытия файла!!!" << endl;

		}


	}
	catch (invalid_argument& error) {

		cout << error.what() << endl;

	}

	system("pause>>void");
	
}