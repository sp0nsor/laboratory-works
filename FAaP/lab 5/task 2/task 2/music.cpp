#include "music.h"
#include <algorithm>

bool operator < (MUSIC Music1, MUSIC Music2) {

	bool result = Music1.Time < Music2.Time;
	return result;

}

void CATALOG::sort() {

	std::sort(this->Music.begin(), this->Music.end());

}