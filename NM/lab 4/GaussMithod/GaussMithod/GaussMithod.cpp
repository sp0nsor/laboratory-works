#include <iostream>
using namespace std;

void print_array(double** a, double* y, unsigned n) {

	for (unsigned i = 0; i < n; ++i) {

		for (unsigned j = 0; j < n; ++j) {

			cout << a[i][j] << " ";
			cout << " = " << y[i] << endl;

		}

	}
	return;
}

double *gauss_method(double** a, double* y, unsigned n) {

	double* x;
	double max;
	unsigned k;
	unsigned index;
	const double eps = 0.0001;

	x = new double[n];
	k = 0;
	while (k < n) {

		// поиск строки с максимальным элементом
		max = abs(a[k][k]);
		index = k;

		for (unsigned i = k + 1; i < n; ++i) {

			if (abs(a[i][k] > max)) {

				max = abs(a[i][k]);
				index = i;

			}

		}

		// перестановка строк
		if (max < eps) {

			// нет нулевых диоганальных элементов 
			cout << "решить систему невозможно!из-за нулевого столбца ";
			cout << index << " матрицы А ";
			return 0;

		}

		for (unsigned j = 0; j < n; ++j) {

			double zxc = a[k][j];
			a[k][j] = a[index][j];
			a[index][j] = zxc;

		}

		double zxc = y[k];
		y[k] = y[index];
		y[index] = zxc;

		// нормализация уравнений
		for (unsigned i = k; i < n; ++i) {

			double zxc = a[i][k];
			// для нулевого коэффициента пропустить
			if (abs(zxc) < eps) {

				continue;

			}
			for (unsigned j = 0; j < n; ++j) {

				a[i][j] /= zxc;

			}
			y[i] /= zxc;
			//print_array(a, y, n);
			// для того чтобы не вычитать уравнение само из себя 
			if (i == k) {

				continue;

			}

			for (unsigned j = 0; j < n; ++j) {

				a[i][j] -= a[k][k];

			}
			y[i] -= y[k];
			//print_array(a, y, n);

		}

		k++;

	}

	for (k = n - 1; k >= 0; --k) {

		x[k] = y[k];
		for (unsigned i = 0; i < n; ++i) {

			y[i] = y[i] - a[i][k] * x[k];

		}
		//print_array(a, y, n);
	}

	return x;

}

int main() {

	setlocale(LC_ALL, "ru");

	double** a;
	double* y;
	double* x;
	unsigned n;
	unsigned m;

flag:
	cout << "введите количество строк матрицы N > ";
	cin >> n;
	cout << "введите количесво столбцов матрицы M > ";
	cin >> m;

	if (n < m - 1) {

		cout << "количество уравнений меньше чем неизвестных! повторите ввод.";
		goto flag;

	}

	a = new double* [n];
	y = new double[n];

	for (unsigned i = 0; i < n; ++i) {

		a[i] = new double[m];
		for (unsigned j = 0; j < m; ++j) {

			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];

		}

	}

	for (unsigned i = 0; i < n; ++i) {

		cout << "y[" << i << "] = ";
		cin >> y[i];

	}

	x = gauss_method(a, y, n);
	for (unsigned i = 0; i < n; i++) {

		cout << "x" << i << " = " << x[i] << endl;

	}
	cin.get(); cin.get();

	return 0;
}