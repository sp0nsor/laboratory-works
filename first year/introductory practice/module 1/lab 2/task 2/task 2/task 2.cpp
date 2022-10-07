#include <iostream>

using namespace std;

void main() {

	setlocale(LC_ALL, "ru");

	unsigned len1;
	unsigned len2;
	unsigned len3;

	cout << "введите рост первого человека > ";
	cin >> len1;
	cout << "введите рост второго человека >";
	cin >> len2;
	cout << "введите рост третьего человека > ";
	cin >> len3;

	if (len1 == len2 && len1 == len3 && len2 == len3) {

		cout << "рост одинаковый" << endl;

	}

	if (len1 == len2 && len1 > len3) {

		cout << "рост третьего человека меньше " << endl;

	}

	if (len1 == len2 && len1 < len3) {

		cout << "рост третьго человека больше " << endl;

	}

	if (len1 == len3 && len1 > len2){
		
		cout << "рост второго человека меньше " << endl;

	}

	if (len1 == len3 && len1 < len2) {

		cout << "рост втрого человека больше " << endl;

	}

	if (len2 == len3 && len1 > len2) {

		cout << "рост первого человека больше " << endl;

	}

	if (len2 == len3 && len1 < len2) {

		cout << "рост первого человека меньше " << endl;

	}

	if (len1 != len2 && len2 != len3 && len1 != len3) {

		cout << "рост у всех разный " << endl;

	}

	system("pause>>void");

}