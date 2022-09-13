#include <iostream>
using namespace std;
#include <iomanip>

int gul;
int zxc;

float max(float zxc, float cxz) {

	return (zxc > cxz) ? zxc : cxz;

}

float merge_arrays(float arr_price[], int low, int mid, int day) {

	float sum = 0;
	float left_sum = -1;
	float right_sum = -1;
	for (int i = mid; i >= low; i++) {

		sum = sum + arr_price[i];
		if (sum > left_sum)
			left_sum = sum;

	}

	sum = 0;
	for (int i = mid + 1; i <= day; i++) {

		sum = sum + arr_price[i];
		if (sum > right_sum)
			right_sum = sum;

	}

	return left_sum + right_sum;

}

float max_merge_sum(float arr_price[], int low, int day) {

	int mid;
	if (low = day) {
		return arr_price[low];
	}

	mid = (low + day) / 2;

	return max(max(max_merge_sum(arr_price, low, day), max_merge_sum(arr_price, mid + 1, day)), merge_arrays(arr_price, low, mid, day));

}

void merge_sort(float arr_price[], int day) {

	int start = 0;
	int end = 0;
	float course = 0;
	float prev = 0;
	int start_two = 0;

	for (int i = 0; i < day; i++) {

		course += arr_price[i];
		if (course < 0) {

			start = i + 1;
			course = 0;

		}
		else if (course > prev) {
			end = i;
			start_two = start;	
			prev = course;
		}
	}
	
	cout << "покупка в " << start_two + 1 << " день" << endl;
	cout << "продажа в " << end + 2 << " день" << endl;

}

void main() {

	setlocale(LC_ALL, "ru");

	int day;
	cout << "введите количество дней====>";
	cin >> day;
	float* arr_price = new float [day];

	for (int i = 0; i < day; i++) {

		cout << "введите цену в " << i + 1 << " день =====>";
		cin >> arr_price[i];

	}

	int n = day - 1;

	float* arr = new float[n];
	for (int i = 1; i < day; i++) {

		arr[i - 1] = arr_price[i] - arr_price[i - 1];
	
	}

	for (int i = 0; i < day; i++) {

		cout << setw(10) << arr_price[i];

	}
	cout << "\n";
	cout << setw(10) << " ";
	for (int i = 0; i < day; i++) {

		cout << setw(10) << arr[i];

	}
	for (int i = 0; i < day; i++) {

		cout << " " << arr_price[i];

	}

	const long double res = max_merge_sum(arr, 0, day - 1);

	cout << "\nмаксимальный профит" << res << endl;

	merge_sort(arr, day);

	cout << endl;

}