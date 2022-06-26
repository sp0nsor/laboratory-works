#include <iostream>

using namespace std;

void main() {

	setlocale(LC_ALL, "ru");

	char str[50];
	unsigned cnt = 0;
	cout << "введите предложение >> ";
	cin.getline(str, 50);

	for (unsigned i = 0; i < size(str); ++i) {

		if (str[i] == ',')
			break;

		if (str[i] == 'n') {

			cnt++;
			

		}

	}

	cout << "количество букв 'n' = " << cnt << endl;

}