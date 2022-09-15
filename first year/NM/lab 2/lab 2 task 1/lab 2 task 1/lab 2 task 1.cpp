#include <iostream>
#include<windows.h>
#include <iomanip>
#include <math.h>

using namespace std;


long double function_value(long double x) {

	return sin(2 * x) + 3 * x;

}

long double function_fi_value(long double x) {

	return 2 * cos(2 * x) + 3;

}

long double second_function_fi_value(long double x) {

	return -4 * sin(2 * x);

}


void simple_eteration_mathod(long double start, long double end, long double delta) {// функция 

	cout << "=========================================================================" << endl<< endl;
	cout << "function: " << endl;
	for (long double i = start; i <= end; i += delta) {

		cout << setw(10) << function_value(i);

	}

	cout << "\n\n";

}

void simple_fi1_eteration_method(long double start, long double end, long double delta) {// точная первая 

	cout << "========================================================================="<< endl << endl;
	cout << "first_derivative: " << endl;

	for (long double i = start; i <= end; i += delta) {

		cout << setw(10) << function_fi_value(i);

	}

	cout << "\n\n";

}

void simple_fi2_eteration_method(long double start, long double end, long double delta) {// точная вторая 

	cout << "========================================================================="<< endl << endl;
	cout << "second_derivative: " << endl;

	for (long double i = start; i <= end; i += delta) {

		cout << setw(10) << second_function_fi_value(i);

	}

	cout << "\n\n";

}

void right_function_value(long double start, long double end, long double delta) {// правая производная 

	cout << "=========================================================================" << endl;
	cout << "right: " << endl;

	for (long double i = start; i <= end-delta; i += delta) {

		cout << setw(10) << (function_value(i + delta) - function_value(i)) / delta;

	}

	cout << "\n\n";

}

void left_function_value(long double start, long double end, long double delta) {// левая производная 

	cout << "=========================================================================" << endl;
	cout << "left: " << endl;


	for (long double i = start +delta; i <= end; i += delta) {

		cout << setw(10) << (function_value(i) - function_value(i - delta)) / delta;

	}

	cout << "\n\n";

}

void central_function_value(long double start, long double end, long double delta) {// центральная

	cout << "=========================================================================" << endl;
	cout << "central: " << endl;

	for (long double i = start + delta; i <= end - delta; i += delta) {

		cout << setw(10) << (function_value(i + delta) - function_value(i - delta)) / (2 * delta);

	}

	cout << "\n\n";

}


void second_function_value(long double start, long double end, long double delta){// приближенная вторая 

	cout << "=========================================================================" << endl;
	cout << "second_approximate: " << endl;

	for (long double i = start; i <= end; i += delta) {

		cout << setw(10) << (function_value(i + delta) - 2 * function_value(i) + function_value(i - delta)) / (delta * delta);

	}

	cout << "\n\n";

}

void main() {

	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);

	long double start;
	long double end;
	long double delta;

	cout << "введите начало промежутка====> ";
	cin >> start;
		
	cout << "введите конец промежутка=====> ";
	cin >> end;

	cout << "введите шаг разбиения========> ";
	cin >> delta;


	simple_eteration_mathod(start, end, delta);
	simple_fi1_eteration_method(start, end, delta);
	simple_fi2_eteration_method(start, end, delta);
	right_function_value(start, end, delta);
	left_function_value(start, end, delta);
	central_function_value(start, end, delta);
	second_function_value(start, end, delta);


}