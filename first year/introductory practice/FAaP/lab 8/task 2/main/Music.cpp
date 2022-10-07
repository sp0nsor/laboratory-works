#include <algorithm>
#include "Music.h"
unsigned cnt;
bool operator < (MUSIC mus1, MUSIC mus2) {

	bool result = mus1.Time < mus2.Time;
	return result;

}

void CATALOG::sort() {

	std::sort(this->Music.begin(), this->Music.end());

}

void CATALOG::print_by_name(string name) {
	vector <MUSIC> v1;
	for (auto iter = (this->Music).begin(); iter != (this->Music).end(); iter++) {
		if ((*iter).get_Name() == name) {
			cnt += 1;

		}

	}

	for (auto iter = (this->Music).begin(); iter != (this->Music).end(); iter++) {

		if ((*iter).get_Name() == name) {

			int i = 0;
			while (i < cnt) {

				MUSIC mus;
				mus = *iter;
				v1.push_back(mus);
				i++;

			}

		}

	}

	vector<MUSIC> ::iterator it;
	it = v1.begin();
	while (it != v1.end()) {

		cout << *it << endl;
		it++;

	}

}