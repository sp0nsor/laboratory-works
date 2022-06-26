#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class City{

private:

	string name;
	unsigned int square;
	unsigned int population;

	friend ostream& operator << (ostream& fout, City city);
	friend istream& operator >> (istream& fin, City& city);
	friend bool operator < (City city1, City city2);

public:

	unsigned int get_population() {

		return population;

	}

};

class Country {

private:

	string name;
	vector<City> city;

public:

	void print_by_population(unsigned int range1, unsigned int range2);
	void sort();

	friend ostream& operator << (ostream& fout, Country country);
	friend istream& operator >> (istream& fin, Country& country);

};