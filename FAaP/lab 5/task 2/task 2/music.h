#pragma once
#include <string>
#include<vector>
#include <iostream>
using namespace std;

class MUSIC {

private:

	string Name;
	string Composition;
	string Style;
	int Time;

	friend ostream& operator << (ostream& out, MUSIC Music);
	friend istream& operator >> (istream& in, MUSIC& Music);
	friend bool operator < (MUSIC Music1, MUSIC Music2);

public:

	string get_name() {

		return Name;

	}

};


class CATALOG {

private:
	string name;
	vector<MUSIC>Music;

public:

	void sort();
	friend ostream& operator << (ostream& out, CATALOG Catalog);
	friend istream& operator >> (istream& in, CATALOG& Catalog);

};