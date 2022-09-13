#include <iterator>
#include "ioMusic.h"
using namespace std;

istream& operator >> (istream& in, MUSIC& Music) {

	in >> Music.Name;
	in >> Music.NameComp;
	in >> Music.Style;
	in >> Music.Time;
	return in;

}

ostream& operator << (ostream& out, MUSIC Music) {

	out.width(8);
	out.fill('0');
	out << Music.Time << " " << Music.NameComp << " " << Music.Name << " " << Music.Style << ".";
	return out;

}

istream& operator >> (istream& in, CATALOG& Catalog) {

	in >> Catalog.Name;
	Catalog.Music.clear();
	istream_iterator<MUSIC> in_iter(in);
	istream_iterator<MUSIC> in_end;
	while (in_iter != in_end) {

		MUSIC mus = *in_iter;
		Catalog.Music.push_back(mus);
		in_iter++;

	}

	return in;

}

ostream& operator << (ostream& out, CATALOG Catalog) {

	out << "список произведений " << Catalog.Name << endl;
	vector <MUSIC> ::iterator iter;
	iter = Catalog.Music.begin();
	while (iter != Catalog.Music.end()) {

		out << *iter << endl;
		iter++;

	}

	return out;

}

