#include <iostream> 
#include <algorithm>
#include <iterator>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void selection_sort(int* arr, unsigned int size) {
	
	long long int comparison = 0;// количество сравнений 
	long long int exchanges = 0; // количество обменов
	unsigned int start_time = clock();// начальное время 

	for (unsigned int i = 0; i < size - 1; i++) {
		unsigned int minz = i;
		for (unsigned int j = i + 1; j < size; j++) {
			comparison++;
			if (arr[j] < arr[minz]) {
				minz = j;
			}
		}
		exchanges += 3;
		swap(arr[i], arr[minz]);
	}

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	cout << "время выполнение сортиовки: " << search_time << endl;
	cout << "количество сравнений: " << comparison << endl;
	cout << "количество обменов: " << exchanges << endl;

}

void insert_sort(int* arr,unsigned int size) {

	long long int comparison = 0;// количество сравнений 
	long long int exchanges = 0; // количество обменов
	unsigned int start_time = clock();// начальное время 

	for (unsigned int i = 1; i < size; i++) {
		comparison++;
		for (unsigned int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			exchanges += 3;
			swap(arr[j - 1], arr[j]);
		}
	}

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	cout << "время выполнение сортиовки: " << search_time << endl;
	cout << "количество сравнений: " << comparison << endl;
	cout << "количество обменов: " << exchanges << endl;

}

void buble_sort(int* arr, unsigned long int size) {

	long long int comparison = 0;// количество сравнений 
	long long int exchanges = 0; // количество обменов
	unsigned int start_time = clock();// начальное время 
	
	for (unsigned int i = 0; i < size -1; i++) {
		for (unsigned int j = 0; j < size - 1; j++) {
			comparison++;
			if (arr[j] > arr[j + 1]) {
				exchanges += 3;
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	cout << "время выполнение сортиовки: " << search_time << endl;
	cout << "количество сравнений: " << comparison << endl;
	cout << "количество обменов: " << exchanges << endl;

}

void bucket_sort(int* arr, unsigned int size) {

	unsigned int start_time = clock();// начальное время 

	std::vector<int>* v = new std::vector<int>[size];
	int i = 0;
	int basis;
	int concat_index = 0;


	for (; i < size; i++) {
		basis = size * arr[i];
		v[basis].push_back(arr[i]);
	}

	for (i = 0; i < size; i++) {
		std::sort(v[i].begin(), v[i].end());
	}

	for (i = 0; i < size; i++) {
		for (size_t j = 0; j < v[i].size(); j++) {
			arr[concat_index] = v[i][j];
			concat_index += 1;
		}
	}

	delete[] v;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	cout << "время выполнение сортиовки: " << search_time << endl;
}

void main() {

	setlocale(LC_ALL, "ru");

	cout << "Типы сортировок:" << endl << endl;
	cout << "\t1. Сортировка выбором" << endl;
	cout << "\t2. Сортировка вставками" << endl;
	cout << "\t3. Пузырьковая сортировка" << endl;
	cout << "\t4. Карманная сортировка" << endl;

	unsigned zxc;
	cout << "Тип сортировки > ";
	cin >> zxc;

	string file;
	int typeEl;
	unsigned long int size;
	cout << endl;
	cout << "1.элементы уже упорядочены(1000)" << endl;
	cout << "2.элементы уже упорядочены(10000)" << endl;
	cout << "3.элементы уже упорядочены(1000000)" << endl;
	cout << "4.элементы упорядочены в обратном порядке(1000)" << endl;
	cout << "5.элементы упорядочены в обратном порядке(10000)" << endl;
	cout << "6.элементы упорядочены в обратном порядке(1000000)" << endl;
	cout << "7.расстановка элементов случайна(1000)" << endl;
	cout << "8.расстановка элементов случайна(10000)" << endl;
	cout << "9.расстановка элементов случайна(1000000)" << endl;

	cout << "тип элементов > ";
	cin >> typeEl;

	if (typeEl == 1) {

		file = "sort1000.txt";
		size = 1000;

	}
	if (typeEl == 2) {

		file = "sort10000.txt";
		size = 10000;

	}
	if (typeEl == 3) {

		file = "sort1000000.txt";
		size = 1000000;

	}
	if (typeEl == 4) {

		file = "sort1000negative.txt";
		size = 1000;

	}
	if (typeEl == 5) {

		file = "sort10000negative.txt";
		size = 10000;

	}
	if (typeEl == 6) {

		file = "sort1000000negative.txt";
		size = 1000000;

	}
	if (typeEl == 7) {

		file = "rand1000.txt";
		size = 1000;

	}
	if (typeEl == 8) {

		file = "rand10000.txt";
		size = 10000;

	}
	if (typeEl == 9) {

		file = "rand1000000.txt";
		size = 1000000;

	}
	
	int* array = new int[size];


	ifstream in(file);
	if (in.is_open()) {

		for (unsigned i = 0; i < size; i++) {

			in >> array[i];

		}
		in.close();

	}
	if (zxc == 1) {

		cout << endl;
		cout << "Сортировка выбором \n";
		selection_sort(array, size);
		cout << "Результат выведен в файл > " << "out.txt" << endl;
		

		ofstream out("out.txt");
		for (unsigned i = 0; i < size; i++) {

			out << array[i] << " ";

		}
		out.close();

	}
	if (zxc == 2) {

		cout << endl;
		cout << "Сортировка вставками:" << endl;
		insert_sort(array, size);
		cout << "Результат выведен в файл > " << "out.txt" << endl;

		ofstream out("out.txt");
		for (unsigned i = 0; i < size; i++) {

			out << array[i] << " ";

		}
		out.close();

	}
	if (zxc == 3) {

		cout << endl;
		cout << "Пузырьковая сортировка: " << endl;
		buble_sort(array, size);
		cout << "Результат выведен в файл > " << "out.txt" << endl;


		ofstream out("out.txt");
		for (unsigned i = 0; i < size; i++) {

			out << array[i] << " ";

		}
		out.close();

	}
	if (zxc == 4) {

		cout << endl;
		cout << "Карманная сортировка: " << endl;
		bucket_sort(array, size);
		cout << "Результат выведен в файл > " << "out.txt" << endl;

		ofstream out("out.txt");
		for (unsigned i = 0; i < size; i++) {

			out << array[i] << " ";

		}
		out.close();

	}
	

}