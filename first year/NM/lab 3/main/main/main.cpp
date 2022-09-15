#include <iostream> 
#include <math.h>

using namespace std;


long double function_value(long double x) {

	return pow(x, 2) / (2 * x + 3);

}

long double primitive_derivative(long double x) {

	return (2 * x * x - 6 * x + 9 * log(2 * x + 3)) / 8;

}

long double left_rectangle(long double start, long double end, int n) {

	cout << "===============================================================================" << endl;

	long double res = 0;
	long double eprox = (end - start) / n;

	for (long double i = start; i < end; i += eprox) {

		res += function_value(i) * eprox;

	}

	return res;
}

long double right_rectangle(long double start, long double end, int n) {

	cout << "===============================================================================" << endl;

	long double res = 0;
	long double eprox = (end - start) / n;

	for (long double i = end; i > start; i -= eprox) {

		res += function_value(i);

	}

	return res * eprox;

}

long double central_rectangle(long double start, long double end, int n) {

	cout << "===============================================================================" << endl;

	long double res = 0;
	long double eprox = (end - start) / n;

	for (long double i = start; i < end; i += eprox) {

		res += function_value(i + eprox / 2);

	}

	return res * eprox;

}

long double trapezoidal_method(long double start, long double end, int n) {

	cout << "===============================================================================" << endl;

	long double res = 0;
	long double eprox = (end - start) / n;

	for (long double i = start; i <= end; i += eprox) {

		res += (function_value(i) + function_value(i + eprox)) / 2 * eprox;

	}

	return res;

}

long double parabola_method(long double start, long double end, int n) {

	cout << "===============================================================================" << endl;

	long double res = 0;
	double h = (end - start) / n;
	
	for (double i = start + h; i < end; i += 2 * h) {
		res += h / 3 * (function_value(i - h) + 4 * function_value(i) + function_value(i + h));
	}
	

	return res;

}

long double gauss_method(long double start, long double end) {

	cout << "===============================================================================" << endl;
	
	long double res = 0;
	long double xk[] = { -0.9324700, -0.6612094, -0.2386142, 0.2386142, 0.6612094, 0.9324700 };
	long double cn[] = { 0.1713245, 0.3607616, 0.4679140, 0.4679140, 0.3607616, 0.1713245 };

	for (int i = 0; i < 6; i++) {

		res += cn[i] * function_value(((end - start) / 2) * xk[i] + ((end + start) / 2));

	}

	return res;
}

long double Newton_Leibniz_formula(long double start, long double end) {

	cout << "===============================================================================" << endl;

	return primitive_derivative(end) - primitive_derivative(start);

}

void main() {

	setlocale(LC_ALL, "ru");

	long double start;
	long double end;
	int n;

	cout << "начало интревала интегрирования =====>";
	cin >> start;
	cout << "конец интервала интегрирования ======>";
	cin >> end;
	cout << "количество отрезков разбиения =======>";
	cin >> n;

	cout << endl;

	cout << "===============================================================================" << endl;
	cout << "значение интеграла по формуле Ньютона-Лейбница: " << Newton_Leibniz_formula(start, end) << endl;
	cout << "значение интеграла по методу левых прямоугольников: " << left_rectangle(start, end, n) << endl;
	cout << "значение интеграла по методу правых прямоугольиков: " << right_rectangle(start, end, n) << endl;
	cout << "значение интеграла по методу центральных прямоугольников: " << central_rectangle(start, end, n) << endl;
	cout << "значение интеграла по методу тропеций: " << trapezoidal_method(start, end, n) << endl;
	cout << "значение интеграла по методу парабол: " << parabola_method(start, end, n) << endl;
	cout << "значение интеграла по методу Гасусса: " << gauss_method(start, end) << endl;
	cout << "===============================================================================" << endl;
	cout << "===============================================================================" << endl;

}