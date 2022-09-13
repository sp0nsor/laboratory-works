#include <iostream>
#include "KNIGHT.h"
using namespace std;

void main() {

	setlocale(LC_ALL, "ru");
	KNIGHT Knight("data.txt");
	Knight.sum_by_price();
	Knight.sort_by_weight();
	Knight.print_by_ammunition();
	Knight.search_for_ammunition();
	
}