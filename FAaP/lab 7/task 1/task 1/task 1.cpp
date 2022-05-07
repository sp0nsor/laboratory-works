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

	iter = first.begin();// итератор на первый элемент контейнера
	iter_end = first.end();// итератор на последний элемент контейнера
	
	while (iter != first.end()) {

		if (*iter < 0) {

			while (*iter < 0) {

				iter++;

			}
			break;

		}
		else
			cout << "no negative element *_*" << endl;
		break;

	}

	int sum = 0;

	while (iter != iter_end) {

		if (*iter < 0)break;
		sum += *iter;
		iter++;

	}

	//cout << *iter << endl;

	iter = first.begin();
	while (iter != first.end()) {

		cout <<" "<< *iter;
		iter++;
	}

	cout << endl << "sum = " << sum << endl;

	system("pause>>void");
}