#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void inserts_sort(vector <int>& v) {

	for (auto i = v.begin() + 1; i != v.end(); i++) {

		for (auto j = i; j != v.begin() && *j < *(j - 1); j--) {

			iter_swap(j - 1, j);

		}

	}

}

void inserts_sort_negative(vector<int>& v) {

	for (auto i = v.begin() + 1; i != v.end(); i++) {

		for (auto j = i; j != v.begin() && *j > *(j - 1); j--) {

			iter_swap(j - 1, j);

		}

	}

}

void input(vector <int>&v) {

	unsigned n;
	cout << "введите количество элементов ===>";
	cin >> n;

	for (unsigned i = 0; i < n; i++) {

		int zxc;
		cout << "введите [" << i + 1 << "] элемент ===>";
		cin >> zxc;
		v.push_back(zxc);

	}

}

void print(vector<int>&v) {

	vector<int> ::iterator iter = v.begin();

	cout << "последовательность: " << endl;
	while (iter != v.end()) {

		cout << *iter << " ";
		iter++;

	}

}

void main() {

	setlocale(LC_ALL, "ru");

	vector <int> v;
	input(v);

	cout << endl;
	cout << "сортировка по возрастанию: " << endl;
	inserts_sort(v);
	print(v);

	cout << endl;

	cout << endl;
	cout << "сортировка по убыванию: " << endl;
	inserts_sort_negative(v);
	print(v);

	cout << endl;

	system("pause>>void");
}