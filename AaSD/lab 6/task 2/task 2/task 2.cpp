// сортировка вставками
// сложность n^2
#include <iostream>
	
using namespace std;

void main() {

	int n;
	cout << "enter seze array=====>";
	cin >> n;
	int* Arr = new int[n];

	for (int i = 0; i < n; i++) {

		cout << "enter [" << i + 1 << "] element";
		cin >> Arr[i];

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