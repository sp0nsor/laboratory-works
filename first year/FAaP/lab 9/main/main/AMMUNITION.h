#pragma once
#include <iostream>
#include <string>
using namespace std;

class AMMUNITION {

protected:

	string name;
	unsigned weight;
	unsigned price;

public: 

	virtual void print_by_ammunition() = 0;

	AMMUNITION() {

		name = "";
		weight = 0;
		price = 0;

	}

	string get_name() {

		return name;

	}

	unsigned get_weight() {

		return weight;

	}

	unsigned get_price() {

		return price;

	}

};

class ARMOR : public AMMUNITION {

private:

public: 

	ARMOR(string name, unsigned weight, unsigned price) : AMMUNITION() {

		this->name = name;
		this->weight = weight;
		this->price = price;

	}

	void print_by_ammunition() {

		cout << name << ":\n\t\t " << weight << "\n\t" << price << "\n";

	}

};

class WEAPON : public AMMUNITION {

private:

public:

	WEAPON(string name, unsigned weight, unsigned price) : AMMUNITION() {

		this->name = name;
		this->price = price;
		this->weight = weight;

	}

	void print_by_ammunition() {

		cout << name << ":\n\t\t " << weight << "\n\t" << price << "\n";

	}

};
