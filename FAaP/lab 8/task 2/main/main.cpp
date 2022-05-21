#include <iostream>
#include <fstream>

#include "ioMusic.h"
#include "Music.h"

using namespace std;

void main(int argc, char*argv[]) {

	setlocale(LC_ALL, "ru");

	char file_name[20];
	cout << "из кaкого файла вводить данные? " << endl;
	cin.getline(file_name, sizeof(file_name));

	CATALOG Catalog;
	ifstream fin(file_name);
	if (fin.is_open()) {

		fin >> Catalog;
		fin.close();

		Catalog.sort();
		cout << Catalog;

		cout << "в какой файл выводить данные? " << endl;
		cin.getline(file_name, sizeof(file_name));

		ofstream fout(file_name);
		if (fout.is_open()) {

			fout << Catalog;
			fout.close();

			cout << "данные выведены в файл " << file_name << endl;

		}
		else {
			cout << "ошибка записи в файл!" << endl;
		}
		
	}
	else {
	
		cout << "файл " << file_name << " не найден" << endl;

	}
	system("pause>>void");

}