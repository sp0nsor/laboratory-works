#include <iterator>
#include "ioCountry.h"

using namespace std;

istream& operator >> (istream& fin, City& city) {

	fin >> city.name;
	fin >> city.population;
	fin >> city.square;

	return fin;

}

ostream& operator << (ostream& fout, City city) {

	fout << "город: " << city.name << " \nнаселение: " << city.population << " \nплощадь " << city.square << endl;
	return fout;

}

istream& operator >> (istream& fin, Country& city) {

	fin >> city.name;
	city.city.clear();
	istream_iterator<City> in_iter(fin);
	istream_iterator<City> in_end;
	while (in_iter != in_end) {

		City cit = *in_iter;
		city.city.push_back(cit);
		in_iter++;

	}

	return fin;
}

ostream& operator << (ostream& fout, Country country) {

	fout << "список городов " << country.name << endl;
	vector <City> ::iterator iter;
	iter = country.city.begin();
	while (iter != country.city.end()) {

		fout << *iter << endl;
		iter++;

	}

	return fout;

}