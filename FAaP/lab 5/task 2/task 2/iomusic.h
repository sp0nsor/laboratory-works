#pragma once
#include "music.h"

istream& operator >> (istream& in, MUSIC& Music);
ostream& operator << (ostream& out, MUSIC Music);
istream& operator >> (istream& in, CATALOG& Catalog);
ostream& operator << (ostream& out, CATALOG Catalog);