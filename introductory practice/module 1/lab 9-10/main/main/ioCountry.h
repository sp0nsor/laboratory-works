#pragma once
#include "County.h"

ostream& operator << (ostream& fout, City city);
istream& operator >> (istream& fin, City& city);
ostream& operator << (ostream& fout, Country country);
istream& operator >> (istream& fin, Country& country);