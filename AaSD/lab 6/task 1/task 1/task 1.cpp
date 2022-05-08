// сортировка выбором
#include <iostream>
#include <time.h>
using namespace std;

void main(){

	int n;
	int zxc;
	int temp;
	cout << "enter size array=====>";
	cin >> n;
	int *Arr = new int [n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {

		Arr[i] = 1 + rand() % 900000;

	}
	//sort
	for (int i = 0; i < n - 1; i++) {

		temp = Arr[i];
		zxc = i;
		for (int j = i + 1; j < n; j++) {

			if (Arr[j] < Arr[zxc]) {
				zxc = j;
			}
		}
		if (zxc != i) {
			Arr[i] = Arr[zxc];
			Arr[zxc] = temp;
		}

	}
	cout << "result array:";
	for (int i = 0; i < n; i++) {
		cout << " " << Arr[i];
	}
	system("pause>>void");

}