#include <algorithm>
#include "County.h"

bool operator < (City cyti1, City cyti2) {

	bool result = cyti1.population < cyti2.population;

	return result;

}

void Country::sort() {

	std::sort(this->city.begin(), this->city.end());

}

void Country :: print_by_population(unsigned int range1, unsigned int range2) {

	vector <City> V;

	for (auto iter = (this->city).begin(); iter != (this->city).end(); ++iter) {

		if ((*iter).get_population() >= range1 && (*iter).get_population() <= range2) {

			V.push_back(*iter);

		}

	}

	for (auto iter = V.begin(); iter != V.end(); ++iter) {

		cout << *iter << " ";

	}

}