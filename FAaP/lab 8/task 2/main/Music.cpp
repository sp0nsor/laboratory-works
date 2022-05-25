#include <algorithm>
#include "Music.h"

bool operator < (MUSIC mus1, MUSIC mus2) {

	bool result = mus1.Time < mus2.Time;
	return result;

}

void CATALOG::sort() {

	std::sort(this->Music.begin(), this->Music.end());

}

void CATALOG::print_by_name(string name) {
	for (auto iter = (this->Music).begin(); iter != (this->Music).end(); iter++) {
		if ((*iter).get_Name() == name) {
			cout << *iter;
		}
	}
}