#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

template <typename n>
void enter_number(n& x) {
    while (!(cin >> x) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
    }
}

void inserts_sort(vector <int>& v) {

    for (auto i = v.begin() + 1; i != v.end(); i++) {

        for (auto j = i; j != v.begin() && *j < *(j - 1); j--) {

            iter_swap(j - 1, j);

        }

    }
}

int search_for_minimum(vector <int>& v) {

    vector<int>::iterator iter = v.begin();
    int min = *iter;

    for (auto i = v.begin(); i != v.end(); i++) {

        if (*i < min) {

            min = *i;

        }

    }

    return min;

}

void merging_containers(vector <int>& v1, vector <int>& v2, vector <int>& v3, vector <int>& v4, vector <int>& v5, vector <int>& v) {

    for (auto i = v1.begin(); i != v1.end(); i++) {

        v.push_back(*i);

    }
    for (auto i = v2.begin(); i != v2.end(); i++) {

        v.push_back(*i);

    }
    for (auto i = v3.begin(); i != v3.end(); i++) {

        v.push_back(*i);

    }
    for (auto i = v4.begin(); i != v4.end(); i++) {

        v.push_back(*i);

    }
    for (auto i = v5.begin(); i != v5.end(); i++) {

        v.push_back(*i);

    }

}

void main() {

    setlocale(LC_ALL, "ru");

    try {

        int min;

        vector<int> V;
        vector<int> V1;
        vector<int> V2;
        vector<int> V3;
        vector<int> V4;
        vector<int> V5;

        fstream fin1("klass1.txt");
        fstream fin2("klass2.txt");
        fstream fin3("klass3.txt");
        fstream fin4("klass4.txt");
        fstream fin5("klass5.txt");

        if (fin1.is_open() && fin2.is_open() && fin3.is_open() && fin4.is_open() && fin5.is_open()) {

            int fin;
            while (fin1 >> fin) {

                V1.push_back(fin);

            }
            fin1.close();

            while (fin2 >> fin) {

                V2.push_back(fin);

            }
            fin2.close();
            
            while (fin3 >> fin) {

                V3.push_back(fin);

            }
            fin3.close();

            while (fin4 >> fin) {

                V4.push_back(fin);

            }
            fin4.close();

            while (fin5 >> fin) {

                V5.push_back(fin);

            }
            fin5.close();
        }
        else {

            throw "ошибка открытия файлов !";

        }

        cout << "минимальное количество учеников среди первых классов =  " << search_for_minimum(V1) << endl;
        cout << "минимальное количество учеников среди вторых классов = " << search_for_minimum(V2) << endl;
        cout << "минимальное количество учеников среди третьих классов = " << search_for_minimum(V3) << endl;
        cout << "минимальное количество учеников среди четвертых классов = " << search_for_minimum(V4) << endl;
        cout << "минимальное количество учеников среди пятых классов =  " << search_for_minimum(V5) << endl;

        merging_containers(V1, V2, V3, V4, V5, V);
        inserts_sort(V);
        vector<int>::iterator iter = V.begin();

        cout << endl;
        cout << "минимальное количество учеников во всех классах = " << *iter << endl;

    }
    catch (invalid_argument& error) {

        cout << error.what() << endl;

    }

    system("pause>>void");

}