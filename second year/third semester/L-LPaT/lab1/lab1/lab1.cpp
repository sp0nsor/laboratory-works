#include <iostream>
#include <iostream>
#include <regex>

using namespace std;

void main() {

	setlocale(LC_ALL, "ru");

	string str;
	cout << "введите строку >> ";
	cin >> str;

	regex reg("((a*|b)c)*de*");

	cout << "базовая строка: " << str << endl;

	if (regex_match(str, reg)) {

		cout << "совпадает " << endl;

	}
	else {

		cout << "не совпадает " << endl;

	}

	system("pause>>void");

}

// aaacdeeeee