#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

void main() {

	setlocale(LC_ALL, "ru");

	bool buf;
	string tmp;
	vector<string> words;
	fstream fin("words.txt");
	fstream out("outwords.txt");

	while (fin >> tmp) {

		if (tmp[0] == 'а' || tmp[0] == 'о') {

			buf = true;
			words.push_back(tmp);

		}

	}
	fin.close();

	if (buf == true) {

		vector <string> ::iterator iter = words.begin();

		for (iter; iter != words.end(); ++iter) {

			out << *iter << " ";

		}
		out.close();

	}
	else {

		cout << "слов на букву 'o' или 'a' не обнаружено " << endl;

	}

}