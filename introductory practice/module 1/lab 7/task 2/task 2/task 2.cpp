#include <iostream>
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

void main(){

    setlocale(LC_ALL, "ru");

    try {
        srand((int)time(0));
        int n, m;
        cout << "количество колонок >> ";
        enter_number(n);
        cout << "количество строк >> ";
        enter_number(m);

        int** a = new int* [n];
        for (int i = 0; i < n; i++)
            a[i] = new int[m];

        int* b = new int[m];

        cout << "двумерный массив: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = rand() % 19 - 9;
                cout << setw(3) << a[i][j] << " ";
            }
            cout << endl;
        }

        cout << "однамерный массив " << endl;
        for (int j = 0; j < m; j++)
        {
            b[j] = 0;
            for (int i = 0; i < n; i++)
                if (a[i][j] % 2 == 0 && a[i][j] > 0) b[j] += a[i][j];
            cout << setw(3) << b[j] << " ";
        }
        cout << endl;

        for (int i = 0; i < n; i++)
            delete[]a[i];
        delete[]a;
        delete[]b;
       
    }

    catch (invalid_argument& error) {

        cout << error.what() << endl;

    }

    system("pause>>void");
}