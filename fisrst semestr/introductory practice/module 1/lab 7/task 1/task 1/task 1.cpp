#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

void main() {

	setlocale(LC_ALL, "RU");
	try {
		bool test = false;
		int A;
		int M;
		int N;
		int** V;
		cout << "введите размерность массива (М) >> ";
		enter_number(M);
		cout << "введите размерность массива (N) >> ";
		enter_number(N);
		cout << "введите искомое число >> ";
		enter_number(A);

		V = new int* [N];

		for (int i = 0; i < N; ++i) {

			V[i] = new int[M];

		}

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < M; ++j) {

				V[i][j] = -10 + rand() / 10;

			}

		}
		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < M; ++j) {

				cout << V[i][j] << "  ";

			}
			cout << endl;
		}
		for (int i = 0; i < N; i++) {

			for (int j = 0; j < M; i++) {

				if (V[i][j] > -1) {
					test = true;
					cout << "в массиве есть положительный элемент " << endl;
					break;
				}

			}
			if (test == true) {
				break;
			}
		}

		for (int i = 0; i < N; i++) {
			
			for (int j = 0; j < M; j++) {
				if (V[i][j] % 10 == A) {

					cout << "элемент последняя цифра которого " << A << " равен " << V[i][j] << endl;

				}
			}
		}
	}
	catch (invalid_argument& error) {

		cout << error.what() << endl;

	}

	system("pause>>void");
}