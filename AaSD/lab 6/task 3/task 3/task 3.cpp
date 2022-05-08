#include <iostream>
#include <time.h>
using namespace std;

void main() {

	int n;
	cout << "enter seze array=====>";
	cin >> n;
	int* Arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {

		Arr[i] = 1 + rand() % 1000;

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