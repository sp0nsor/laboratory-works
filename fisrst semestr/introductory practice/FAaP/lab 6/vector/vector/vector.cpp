#include <iostream>
#include <vector>
using namespace std;

void main() {

	int n;
	int count = 0;
	int cnt = 0;
	cout << "enter quantity of elements=====>";
	cin >> n;
	
	vector<int>first;
	vector<int>zero;

	for (int i = 0; i < n; i++) {

		int zxc;
		cout << "enter [" << i + 1 << "] element ";
		cin >> zxc;
		first.push_back(zxc);// добавление элементов 

	}
	for (int i = 0; i < first.size(); i++) {

		if (first[i] == 0) {

			count++;

		}
		if (first[i] != 0) {

			cnt++;

		}

	}
	for (int i = 0; i < count; i++) {

		int zxc = 0;
		zero.push_back(zxc);

	}
	for (int i = 0; i < first.size();i++) {

		if (first[i] != 0) {

			int zxc = first[i];
			zero.emplace_back(zxc);// добавление в конец

		}

	}
	cout << "the entered sequence: ";
	for (int i = 0; i < first.size(); i++) {

		cout << " " << first[i];

	}
	cout << "\n";
	cout << "new sequence: ";
	for (int i = 0; i < zero.size(); i++) {

		cout << " " << zero[i];

	}

	system("pause>>void");
}