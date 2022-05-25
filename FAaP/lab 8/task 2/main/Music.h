#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class MUSIC {

private:

	string Name;
	string NameComp;
	string Style;
	unsigned Time;

	friend ostream& operator << (ostream& out, MUSIC Music);
	friend istream& operator >> (istream& in, MUSIC& Music);
	friend bool operator < (MUSIC mus1, MUSIC mus2);

public:

	string get_Name() {
		return Name;
	}

};

class CATALOG {

private:

	string Name;
	vector<MUSIC> Music;

public:

	void print_by_name(string name);
	void sort();
	friend ostream& operator<< (ostream& out, CATALOG Catalog);
	friend istream& operator >> (istream& in, CATALOG& Catalog);

};