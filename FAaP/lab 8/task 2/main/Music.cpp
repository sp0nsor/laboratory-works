#include <algorithm>
#include "Music.h"

bool operator < (MUSIC mus1, MUSIC mus2) {

	bool result = mus1.Time < mus2.Time;
	return result;

}

void CATALOG::sort() {

	std::sort(this->Music.begin(), this->Music.end());

}