#include <iostream>
#include <vector>
#include <iterator>
#include <Windows.h>
using namespace std;

void main() {

	vector <int>first;
	unsigned n;

	cout << "enter number of elemets ===> ";
	cin >> n;

	for (unsigned i = 0; i < n; ++i) {

		int zxc;
		cout << "element [" << i + 1 << "]====>";
		cin >> zxc;
		first.push_back(zxc);

	}

	vector <int> ::iterator iter;
	vector <int> ::iterator iter_end;
	vector <int> ::iterator ii;

	iter = first.begin();// итератор на первый элемент контейнера
	iter_end = first.end();// итератор на последний элемент контейнера

	if (*iter < 0) {
		while (*iter < 0) {
			iter++;
			if (*iter > 0)
				break;
		}
	}

	if (*(iter_end - 1) < 0) {
		while (*(iter_end - 1) < 0) {
			iter_end--;
			if (*(iter_end - 1) > 0) {
				break;
			}
		}
	}

	unsigned sum = 0;
	while (iter != iter_end) {

		sum += *iter;
		iter++;
		
	}

	cout << endl << "sum = " << sum << endl;

	system("pause>>void");
}