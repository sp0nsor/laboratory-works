#include <iostream>
#include "Header.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");
	int side1;
	int side2;
	int side3;

	cout << "введите первую сторону =====>";
	cin >> side1;
	cout << "введите вторую сторону =====>";
	cin >> side2;
	cout << "введите третью сторону =====>";
	cin >> side3;

	cube first = cube(side1);

	first.valume();

	parallelepiped first_two = parallelepiped(side1, side2, side3);
	first_two.valume();

	return 0;

}