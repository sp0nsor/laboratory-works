#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void main() {

	setlocale(LC_ALL, "ru");

	unsigned cnt(0);
	unsigned i(0);
	unsigned index(0);
	bool buf = false;
	string tmp;
	string str;
	fstream fin("words.txt");
	fstream in("words.txt");

	while (fin >> str) {

		if (str[0] == 'м') {

			cnt++;

		}
		
	}
	while (in >> tmp) {

		if (tmp[0] == 'к') {

			buf = true;
			index = i;
			break;


		}
		++i;

	}
	
	fin.close();
	in.close();

	if (cnt == 0 && buf == false) {

		cout << "слов на букву 'м' не обнаружено!!" << endl;
		cout << "слов на букву 'к' не обнаружено!!" << endl;
	}
	else if (cnt != 0 && buf == false) {

		cout << "количество слов на букву 'м' = " << endl;
		cout << "слов на букву 'к' не обнаружено!!" << endl;

	}
	else if (cnt == 0 && buf == true) {

		cout << "слов на букву 'м' не обнаружено!!" << endl;
		cout << "порядковый номер первого слова на букву 'к' = " << index + 1 << endl;

	}
	else {

		cout << "количество слов на букву 'м' = "<< cnt + 1 << endl;
		cout << "порядковый номер первого слова на букву 'к' = " << index + 1 << endl;

	}

	system("pause>>void");

}