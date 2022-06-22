#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename n>
void enter_number(n& x) {
    while (!(cin >> x) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
    }
}

void generate(int N) {

    ofstream out("data.txt");
    long double* A = new long double[N];
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++) {
        int A2 = rand() % 100 - 50;
        if (i >= N / 2) {
            A[i] = 1.0 + (double)A2 / 100;
        }
        else {
            A[i] = (double)A2 / 100;
        }
        out << setw(8) << A[i];
    }
    cout << endl;
    out.close();

}

void main() {

	setlocale(LC_ALL, "ru");

	try {

        const long double tmp = 50.55;
        int zxc;
        int N;
        cout << "введите количество чисел  > ";
        enter_number(N);
        //generate(N);
        fstream fin("data.txt");
        vector <long double> V;
        long double ff;
        if (fin.is_open()) {

            while (fin >> ff) {

                V.push_back(ff);

            }
            fin.close();

        }
        else {

            throw "ошибка открытия файла !";

        }
        for (auto iter = V.begin(); iter != V.end(); iter++) {

            if (*iter < tmp) {

                zxc += 1;

            }
            
        }

        if (zxc % 4 == 0) {

            cout << "количество элементов которые меньше 50.55 кратно 4" << endl;

        }
        else {

            throw "количество элементов не кратно 4";

        }

	}
	catch (invalid_argument& error) {

		cout << error.what() << endl;

	}

	system("pause>>void");

}