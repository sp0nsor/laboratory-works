#include <iostream>
#include "music.h"
#include "iomusic.h"
#include <fstream>
#include <Windows.h>\
#include <string>
using namespace std;

void main(int argc, char* argv[]) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char FileName[100];
	string author;

	cout << "из какого файла вводить данные:\n";
	cin.getline(FileName, sizeof(FileName));
	CATALOG Catalog;
	ifstream fin(FileName);
	if (fin.is_open()) {

		fin >> Catalog;
		fin.close();
		Catalog.sort();
		cout << Catalog;
		cout << "в какой файл выводить данные? ";
		cin.getline(FileName, sizeof(FileName));
		ofstream fout(FileName);
		if (fout.is_open()) {

			fout << Catalog;
			fout.close();
			cout << "данные выведены в файл " << FileName << endl;

		}
		else
			cout << "ошибка записи в файл!!!" << FileName << endl;

	}
	else
		cout << "файл " << FileName << "не найден!!!\n ";

}