#include <iostream>
#include <string>
#include <ctime>
using namespace std;

template <typename T1>
void enter_number(T1& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "error!!! repit the input: " << endl;
	}
}

template <typename T>
class Array {
private:

	T* Arr;
	int n;

public:

	int operator&(const int i) {

		return this->Arr[i];

	}

	friend ostream& operator << (ostream& os, const Array &mas) {

		for (int i = 0; i < mas.n ; i++) {

			os << " " << mas.Arr[i];

		}
		return os;
	}


	int get_n() {

		return n;

	}

	Array() {

		n = 1;
		Arr = new int[n];
		for (int i = 0; i < n; i++) {
			Arr[i] = 0;
		}

	}

	Array(int n) {

		this->n = n;
		Arr = new int[n];
		init();

	}

	Array(const Array& tmp) {

		n = tmp.n;
		Arr = new int[n];
		for (int i = 0; i < n; i++) {

			Arr[i] = tmp.Arr[i];

		}

	}

	~Array() {

		delete[] Arr;

	}

	void init() {

		for (int i = 0; i < n; i++) {

			Arr[i] = rand() % 200;

		}

	}

	void first_out_put() {
		//cout << endl;
		for (int i = 0; i < n; i++) {

			cout << Arr[i] << " ";

		}
		//cout << endl;
	}

	void second_out_put() {
		//cout << endl;
		for (int i = n - 1; i >= 0; i--) {

			cout << Arr[i] << " ";

		}

		//cout << endl;

	}

	void sort_array() {

		int zxc;

		for (int i = 0; i < n; i++) {

			zxc = Arr[i];
			for (int j = i; j < n; j++) {

				if (zxc > Arr[j]) {

					zxc = Arr[j];
					Arr[j] = Arr[i];
					Arr[i] = zxc;

				}

			}

		}

	}

};


void main() {

	int n;
	cout << "enter size array ====>";
	enter_number(n);
	Array<int> Array(n);
	cout << "first_sort [ ";
	Array.sort_array();
	Array.first_out_put();
	cout << "]" << endl;
	cout << "second_sort [ ";
	Array.second_out_put();
	cout << "]" << endl;
	int Arr[] = { 5, 1,3,7 };
	cout << Array << endl;
}