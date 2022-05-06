// сортировка выбором
#include <iostream>
using namespace std;

void main(){

	int n;
	int zxc;
	int temp;
	cout << "enter size array=====>";
	cin >> n;
	int *Arr = new int [n];
	for (int i = 0; i < n; i++) {

		cout << "enter " << "[" << i + 1 << "] element ";
		cin >> Arr[i];

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