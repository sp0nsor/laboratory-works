#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void main() {

	setlocale(LC_ALL, "ru");

	string word;
	string str;
	cout << "введите слово >> ";
	getline(cin, str);
	istringstream in(str);
	size_t min = str.size();

	while (in >> word) {

		if (word.size() < min) {

			min = word.size();

		}

	}

	cout << " длинна миниимального слова = " << min << endl;

	system("pause>>void");

}