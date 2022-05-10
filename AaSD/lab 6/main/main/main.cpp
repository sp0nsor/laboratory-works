#include <iostream> 
#include <algorithm>
#include <iterator>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void selection_sort(int* arr, unsigned long int size) {
	
	long long int comparison = 0;// количество сравнений 
	long long int exchanges = 0; // количество обменов
	unsigned int start_time = clock();// начальное время 

	for (unsigned long int i = 0; i < size - 1; i++) {
		unsigned long int minz = i;
		for (unsigned long int j = i + 1; j < size; j++) {
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

void insert_sort(int* arr,unsigned long int size) {

	long long int comparison = 0;// количество сравнений 
	long long int exchanges = 0; // количество обменов
	unsigned int start_time = clock();// начальное время 

	for (unsigned long int i = 1; i < size; i++) {
		comparison++;
		for (unsigned long int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
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
	
	for (unsigned long int i = 0; i < size -1; i++) {
		for (unsigned long int j = 0; j < size - 1; j++) {
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

void bucket_sort(int* arr, const unsigned n) {

	unsigned int start_time = clock();// начальное время 

	vector<int> b[100];

	for (unsigned long int i = 0; i < n; i++) {
		int bi = n * arr[i];
		b[bi].push_back(arr[i]);
	}

	for (unsigned long int i = 0; i < n; i++) {
		sort(b[i].begin(), b[i].end());
	}
	unsigned index = 0;
	for (unsigned i = 0; i < n; i++) {
		for (unsigned j = 0; j < b[i].size(); j++) {
			arr[index++] = b[i][j];
		}
	}

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
	cout << "из какого файла брать данные? > ";
	cin >> file;


	unsigned long int size;
	cout << "выберите размерность массива (1000,10000,1000000) > ";
	cin >> size;
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
		cout << "Результат выведен в файл > " << "out.txt" << endl;
		
		selection_sort(array, size);

		ofstream out("out.txt");
		for (unsigned i = 0; i < size; i++) {

			out << array[i] << " ";

		}
		out.close();

	}
	if (zxc == 2) {

		cout << endl;
		cout << "Сортировка вставками:" << endl;
		cout << "Результат выведен в файл > " << "out.txt" << endl;

		insert_sort(array, size);

		ofstream out("out.txt");
		for (unsigned i = 0; i < size; i++) {

			out << array[i] << " ";

		}
		out.close();

	}
	if (zxc == 3) {

		cout << endl;
		cout << "Пузырьковая сортировка: " << endl;
		cout << "Результат выведен в файл > " << "out.txt" << endl;

		buble_sort(array, size);

		ofstream out("out.txt");
		for (unsigned i = 0; i < size; i++) {

			out << array[i] << " ";

		}
		out.close();

	}
	if (zxc == 4) {

		cout << endl;
		cout << "Карманная сортировка: " << endl;
		cout << "Результат выведен в файл > " << "out.txt" << endl;

		const unsigned n = sizeof(array) / sizeof(array[0]);

		bucket_sort(array, n);

		ofstream out("out.txt");
		for (unsigned i = 0; i < size; i++) {

			out << array[i] << " ";

		}
		out.close();

	}

}