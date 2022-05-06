#include <iostream>

using namespace std;

long double delta;

void init() {

	cout << "Введите шаг разбиения: ";
	cin >> delta;

}

long double function_value(long double x) {

	return x * pow(2, x) - 1;

}

long double funtion_fi_value(long double x) {

	return 1 / pow(2, x);

}

long double sinple_iteration_method(long double a, long double eps) {

	cout << "\n\n";
	long double epproximation = a;
	long double xi = funtion_fi_value(epproximation);

	int i = 0;
	while (true) {

		xi = funtion_fi_value(epproximation);
		i++;
		if (fabs(xi - epproximation) < eps) {

			break;

		}

		epproximation = xi;

	}

	cout << "колчество итераций по методу простой иетрации: " << i << endl;

	return xi;

}

void out_put() {

	long double start = 0;
	long double end = 0;

	for (long double i = -1.0; i <= 1; i += delta) {

		if (function_value(i) * function_value(i + delta) < 0) {
			start = i;
			end = i + delta;
			cout << "Корень находится в промежутке от " << start << " до " << end << endl;

		}

	}

	cout << "Корень по методу простой итерации: " << sinple_iteration_method(start, 0.001) << endl;

}

void main() {

	setlocale(LC_ALL, "ru");
	init();
	out_put();
}