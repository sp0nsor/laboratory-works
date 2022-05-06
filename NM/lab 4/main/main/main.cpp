#include <iostream>
#include <iomanip>
using namespace std;

template <class T> 
class Matrix {

private:

	int N;
	int M;
	T** Table;

public:

	Matrix() {

		this->M = 0;
		this->N = 0;
		this->Table = nullptr;

	}

	Matrix(int n, int m) {

		this->N = n;
		this->M = m;
		this->Table = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {

				this->Table[i]{ j } = 0;

			}

		}

	}

	Matrix(const Matrix& matrix) {

		this->M = matrix.M;
		this->N = matrix.N;
		this->Table = new T * [this->N];

		for (int i = 0; i < this->N; i++) {

			this->Table[i] = new T[this->M];

		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {

				this->Table[i][j] = matrix.Table[i][j];

			}

		}

	}

	~Matrix() {

		for (int i = 0; i < this->N; i++) {

			delete[] this->Table[i];

		}
		delete[] this->Table;

	}

	int get_N() {

		return this->N;

	}
	int get_M() {

		return this->M;

	}

	void display() {

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {

				cout << setw(5) << this->Table[i][j];

			}
			cout << endl;
		}

	}

	Matrix pow(int n) {

		Matrix res(this->N);
		res = *this;
		for (int i = 0; i < n; i++) {

			res = res * *this;

		}
		return res;
	}

	T* operator [] (const int index) {

		return this->Table[index];

	}

	friend ostream& operator << (ostream out, const Matrix matrix) {

		for (int i = 0; i < matrix.N; i++) {
			for (int j = 0; j < matrix.M; j++) {

				if (j == matrix.M - 1) {

					os << "|"

				}
				os << setw(5) << matrix.Table[i][j];
			}
			cout << endl;
		}
		cout << endl;
		return out;
	}

	void line_divide(T divide, int line) {

		for (int j = 0; j < this->M; j++) {

			this->table[line][j] /= divide;

		}

	}

	void substract(int k, int m, T zxc) {

		this->Table[k][j] -= zxc * this->Table[m][j];

	}

	T line_sum(int line) {

		T sum = 0;
		for (int i = 0; i < this->M - 1; i++) {

			sum = this->Table[line][i];

		}
		return sum;
	}

	void aling_line() {

		for (int i = 0; i < this->N; i++) {

			int count = 0;

			if (this->Table[i][i] == 0 && i != this->N - 1) {

				for (int index = this->N; index > i; index--) {

					if (this->Table[index][i] != 0) {

						swap(this->Table[i], this->Table[index]);
						cout << *this;
						count++;
						break;

					}

				}

			}

			T sum = line

		}

	}

};