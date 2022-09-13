#pragma once 
#include "AMMUNITION.h"
#include <iostream>
#include <vector>
#include <fstream>


class KNIGHT : AMMUNITION {

private:
 
	vector <AMMUNITION*> knight;

public:

	KNIGHT(string name, unsigned weight, unsigned price) :AMMUNITION(){

		this->name = name;
		this->weight = weight;
		this->price = price;

	}

	KNIGHT(const char* data) {

		fstream fin(data);
		while (!fin.eof()) {

			string name;
			unsigned weight;
			unsigned price;

			fin >> name;
			fin >> weight;
			fin >> price;

			if (name == "armor") {

				ARMOR* armor = new ARMOR(name, weight, price);
				armor->print_by_ammunition();
				knight.push_back(armor);

			}
			if (name == "weapon") {

				WEAPON* weapon = new WEAPON(name, weight, price);
				weapon->print_by_ammunition();
				knight.push_back(weapon);

			}
			if (name == "knight") {

				KNIGHT* Knight = new KNIGHT (name, price, weight);
				knight.push_back(Knight);
				Knight->print_by_ammunition();

			}
		}

	}

	void sum_by_price() {

		unsigned sum_by_price = 0;
		for (unsigned i = 0; i < knight.size(); i++) {

			sum_by_price += knight[i]->get_price();

		}

		cout << "стоимость амуниции рыцаря = " << sum_by_price << endl;
 
	}

	void print_by_ammunition() {

		for (unsigned i = 0; i < knight.size(); i++) {

			cout << knight[i]->get_name() << endl << "weight: " << knight[i]->get_weight() <<
				endl << "price: " << knight[i]->get_price() << endl << endl;

		}

	}

	void sort_by_weight() {

		for (unsigned i = 1; i < knight.size(); i++) {

			for (unsigned j = i; j > 0; j--) {

				if (knight[j]->get_weight() < knight[j - 1]->get_weight()) {

					swap(knight[j], knight[j - 1]);

				}

			}

		}

	}

	void search_for_ammunition() {

		unsigned min;
		unsigned max;

		cout << "введите минимальную цену > ";
		cin >> min;
		cout << "введите максимальную цену > ";
		cin >> max;

		cout << "амунация в данном диопазоне :" << endl;
		for (unsigned i = 0; i < knight.size(); i++) {

			if (knight[i]->get_price() >= min && knight[i]->get_price() <= max) {

				knight[i]->print_by_ammunition();

			}

		}

	}
};