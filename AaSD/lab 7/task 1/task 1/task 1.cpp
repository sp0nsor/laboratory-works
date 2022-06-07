#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
#include <chrono>

using namespace std;

const vector<string> F = { "F1.txt", "F2.txt", "F3.txt" };
const int MAX_NUMBER = 15000;

int compareCount = 0;
int toFileCount = 0;

typedef vector<int> series;

const vector<int> fib = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
						  1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393,
						  196418, 317811 };

ostream& operator<<(ostream& out, const series& data) {
	out << data.size() << " ";
	for (const auto& val : data) {
		out << val << " ";
	}
	return out;
}

vector<ofstream> fout(3);
vector<ifstream> fin(3);


void generate(ostream& out, const int size) {
	srand(time(0));
	for (int i = 0; i < size; ++i) {
		out << rand() % MAX_NUMBER << " ";
	}
}

void generate1(ostream& out, const int size) {
	srand(time(0));
	int t = 1;
	for (int i = 0; i < size; ++i) {
		out << t << " ";
		t++;
	}
}

void generate2(ostream& out, const int size) {
	srand(time(0));
	int t = size;
	for (int i = 0; i < size; ++i) {
		out << t << " ";
		t--;
	}
}

void _merge(int source1, int source2, int cnt1, int cnt2) {


	int destination = 3 - source1 - source2; // опять считайм файл с которым работаем

	int series_size1 = 0;
	int series_size2 = 0;
	int series_size3 = 0;

	int val_1;
	int val_2;

	for (int i = 0; i < cnt2; ++i) {
		fin[source1] >> series_size1; //серии 1 файла
		fin[source2] >> series_size2; //серии 2 файла
		toFileCount += 2;

		series_size3 = series_size1 + series_size2; //серии 3 файла
		fout[destination] << series_size3 << " ";
		toFileCount++;

		int pos1 = 0;
		int pos2 = 0;

		fin[source1] >> val_1;
		fin[source2] >> val_2;
		toFileCount += 2;

		while (pos1 < series_size1 && pos2 < series_size2) {

			compareCount++;
			if (val_1 <= val_2) {
				fout[destination] << val_1 << " ";
				pos1++;
				if (pos1 >= series_size1) {
					break;
				}
				fin[source1] >> val_1;

			}
			else {
				fout[destination] << val_2 << " ";
				pos2++;
				if (pos2 >= series_size2) {
					break;
				}
				fin[source2] >> val_2;
			}
		}

		while (pos1 < series_size1) {
			fout[destination] << val_1 << " ";
			pos1++;
			if (pos1 >= series_size1) {
				break;
			}
			fin[source1] >> val_1;
		}

		while (pos2 < series_size2) {
			fout[destination] << val_2 << " ";
			pos2++;
			if (pos2 >= series_size2) {
				break;
			}
			fin[source2] >> val_2;
		}
	}
}

void _sort(ifstream& f, int size) {

	fout[0].open(F[0]);
	fout[1].open(F[1]);
	fout[2].open(F[2]);

	int file_source_1 = 0;
	int file_source_2 = 1;

	int fib_pos = 0;
	while (fib[fib_pos] < size) { //считаем нужное нам число фибоначи
		fib_pos++;
	}
	fib_pos--;

	int diff = (fib[fib_pos] + fib[fib_pos - 1]) - size; //считаем сколько пустых символов
	int x;

	for (int i = 0; i < fib[fib_pos] - diff; ++i) { //заполнение файлов
		f >> x;
		fout[0] << series{ x };
		toFileCount++;
	}

	for (int i = 0; i < diff; ++i) {
		f >> x;
		fout[2] << series{ x };
		toFileCount++;
	}

	for (int i = 0; i < size - fib[fib_pos]; ++i) {
		f >> x;
		fout[1] << series{ x };
		toFileCount++;
	}

	fout[0].close();
	fout[1].close();
	fout[2].close();


	fin[0].open(F[0]);
	fin[1].open(F[1]);

	int destination = 3 - file_source_1 - file_source_2;

	fout[destination].open(F[destination], std::ios_base::app);

	_merge(file_source_1, file_source_2, fib[fib_pos] - diff, fib[fib_pos - 1] - diff);

	fout[destination] << flush;
	fout[destination].close();
	fin[file_source_2].close();

	fib_pos--; //уменьшение числа фибоначи для дальнейших проходов

	while (fib[fib_pos] + fib[fib_pos - 1] > 1) {			// пока есть больше 1 серии 

		swap(file_source_1, file_source_2);                                         //всё то что выше, но разница в размерах серий и  кол-ву элементов в файле
		file_source_1 = destination;

		destination = 3 - file_source_1 - file_source_2;

		fout[destination].open(F[destination]);
		fin[file_source_1].open(F[file_source_1]);


		_merge(file_source_1, file_source_2, fib[fib_pos], fib[fib_pos - 1]);
		fout[destination] << flush;
		fin[file_source_2].close();
		fout[destination].close();

		fib_pos--;
	}
	fin[file_source_1].close();
	fin[file_source_2].close();
	fout[file_source_1].open(F[file_source_1]);
	fout[file_source_2].open(F[file_source_2]);

}

// 1 vozrast, 0 random, 2 ubiv
int main() {
	setlocale(0, "ru");
	int SIZE;
	int x;
	cout << "Введите размер последовательности: ";
	cin >> SIZE;
	ofstream _fout("test.txt");
	cout << "Введите способ задания последовательности: " << endl << "1)Рандом" << endl << "2)Отсортированный" << endl << "3)Отсортированный в обратном порядке" << endl;
	cin >> x;
	if (x > 3 || x < 1) {
		cout << "Введено некорректное значение!";
		return 0;
	}
	switch (x) {
	case 1:
		generate(_fout, SIZE);
	case 2:
		generate1(_fout, SIZE);
	case 3:
		generate2(_fout, SIZE);
	}
	_fout.close();
	ifstream _fin("out.txt");
	auto begin = chrono::steady_clock::now();
	_sort(_fin, SIZE);
	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
	cout << "Время выполнения " << "T: " << elapsed_ms.count() << " ms\n";
	cout << "Количество обращений к файлам " << "F: " << toFileCount << endl;
	cout << "Количество сравнений " << "C: " << compareCount << endl;
	fout[0].close();
	fout[1].close();
	fout[2].close();
	fin[0].close();
	fin[1].close();
	fin[2].close();
	return 0;

}
