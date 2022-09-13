#include <iostream>

using namespace std;


class Class {

private:

	long double element;
	long double sum;
	
	long double Element(long double  x, long double i) {

		return pow(x, 2 * i + 1) / (2 * i + 1);

	}

public:

	Class(long double x, long double n) {

		this->element = x;
		this->sum = element;
		for (int i = 1; i < n; ++i) {

			this->element = Element(x, i);
			this->sum += this->element;
			
		}

	}

	void result() {

		cout << "значение из класса: " << this->sum << endl;

	}

};

int main() {

	setlocale(LC_ALL, "ru");

	long double x;
	x = 0.001;
	long double n;
	n = 1000;
	long double temp = x;
	long double sum = temp;

	
	long double i = -1;

	while (i < n) {

		temp *= static_cast<__int64>( x * x / ((2 * i) + 1));
		sum += temp;
		++i;

	}

	cout << "наше значение: " << sum << endl;


	const long double def = log(sqrt((1 + x) / (1 - x)));
	cout << "значение по формуле: " << def << endl;


	Class* a_log_1 = new Class(x, n);
	a_log_1->result();
	[[gsl::suppress(i.11)]]
	delete a_log_1;

	return 0;
}