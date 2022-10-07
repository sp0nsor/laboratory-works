#include "Header.h"
#include <iostream>
using namespace std;

using namespace std;

cube::cube() {

	a = 0;

}

cube::cube(int a) {
	
	this->a = a;

}

int cube::valume() {

	cout << "объём куба = " <<  (a * a * a) << endl;
	return 0;
}


parallelepiped ::parallelepiped(int a, int b, int h) {

	this->a = a;
	this->b = b;
	this->h = h;

}

int parallelepiped::valume() {

	cout << "обём паралелепида = " << (a * b * h);

	return 0;

}