#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

struct State {

	string name;
	int square;
	int population;

};

fstream& operator >> (fstream& fin, State& St) {

	fin >> St.name;
	fin >> St.square;
	fin >> St.population;

	return fin;

}

void main() {

	setlocale(LC_ALL, "RU");

	State St;
	vector <State> States;
	fstream fin("State.txt");

	while (fin >> St) {

		States.push_back(St);

	}
	fin.close();

	if (States.size() == 15) {

		vector<State>::iterator min = States.begin();
		vector<State>::iterator iter = States.begin();

		for (iter; iter != States.end(); ++iter) {

			if ((*iter).population < (*min).population) {

				min = iter;

			}

		}

		cout << "государством с минимальной численностью населения является '" << (*min).name<<"'" << endl;
		cout << "с численностью населения " << (*min).population<< " мл.ч" << endl;
		cout << "и населением " << (*min).square<< " тыс.кв.км" << endl;

	}
	else {

		cout << "ошибка записи в контейнер!!" << endl;

	}

	system("pause>>void");

}