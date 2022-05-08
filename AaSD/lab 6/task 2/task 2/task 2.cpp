// сортировка вставками
// сложность n^2
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

		Arr[i] = 1 + rand() % 100;

	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0 && Arr[j - 1] > Arr[j]; j--) {

			swap(Arr[j - 1], Arr[j]);

		}

	}
	cout << "result array:";
	for (int i = 0; i < n; i++) {
		cout << " " << Arr[i];
	} 

	system("pause>>void");

}