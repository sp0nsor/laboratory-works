#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

void main() {

	setlocale(LC_ALL, "ru");
	
	bool buf = false;
	bool buf2 = false;
	string tmp;
	string str;
	unsigned cnt(0);
	vector<string> words;
	fstream fin("words.txt");
	fstream in("words.txt");

	while (fin >> tmp) {

		if (tmp[0] == 'а' || tmp[0] == 'А') {

			buf = true;
			cnt++;

		}

	}
	while (in >> str) {

		if (str == "иииии") {

			buf2 = true;
			words.push_back(str);

		}

	}
	in.close();
	fin.close();

	if (buf == true) {

		cout << "количество слов на букву 'а' или 'А' = " << cnt << endl;

	}
	else {

		cout << "слов на букву 'а' или 'А' не найдено. повторите ввод ;)" << endl;

	}
	if (buf2 == true) {

		cout << "слова в кторых имеется ровно 5 букв 'u' " << endl;
		for (auto iter = words.begin(); iter != words.end(); ++iter) {

			cout << *iter << " ";

		}

	}
	else {

		cout << "слов в которых ровно 5 букв 'u' не найдено. повторите ввод ;) " << endl;

	}

}