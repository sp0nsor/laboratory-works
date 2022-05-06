#include <iostream>
using namespace std;

void main() {

	int n;
	cout << "enter seze array=====>";
	cin >> n;
	int* Arr = new int[n];
	for (int i = 0; i < n; i++) {

		cout << "enter [" << i + 1 << "] element:";
		cin >> Arr[i];

	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {

			if (Arr[i] > Arr[j]) {

				swap(Arr[j], Arr[i]);

			}

		}

	}
	cout << "result array";
	for (int i = 0; i < n; i++) {

		cout << " " << Arr[i];

	}

	system("pause>>void");
}