#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMax(int arr[], int n)
{
	int i, max = arr[0], cnt = 0;
	for (i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	while (max > 0)
	{
		cnt++;
		max = max / 10;
	}

	return cnt;
}

void bucket_sort(int arr[], int *zxc[], int n) {

	int i, int j[10], k, l, d = 1;
	int c;
	c = findMax(arr, n);

	for (int m = 0; m < c; m++) {

		for (i = 0; i < 10; i++)
			j[i] = 0;
		for (i = 0; i < n; i++) {
			k = (arr[i] / d) % 10;
			zxc[k][j[k]] = arr[i];
			j[k]++;
		}
		l = 0;
		for (i = 0; i < n; i++) {

			for (k = 0; k < j[k]; k++) {

				arr[l] = zxc[i][k];
				l++;

			}
			
		}
		d *= 10;
	}

}

int main() {

	int n;
	int* zxc[10];
	cout << "enter size array=====>";
	cin >> n;
	int* Arr = new int[n+1];

	for (int i = 0; i < n; i++)
		zxc[i] = new int[n];

	for (int i = 0; i < n; i++) {

		cout << "enter [" << i + 1 << "] element";
		cin >> Arr[i];

	}
	bucket_sort(Arr, zxc, n);
	cout << "result array: ";
	for (int i = 0; i < n; i++) {

		cout << Arr[i] << " ";

	}
	return 0;
}