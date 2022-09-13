#include <iostream>
#include "vector.h"

using namespace std;

ostream& operator << (ostream& os, Vector vector) {

	os << vector.get_x() << " " << vector.get_y()<< " " << vector.get_z();
	return os;

}

int operator - ( Vector v1, Vector v2) {

	return (v1.get_x() - v2.get_x(), v1.get_y() - v2.get_y(), v1.get_z() - v2.get_z());

}




int main() {

	setlocale(LC_ALL, "ru");
	int x1;
	int x2;
	int y1;
	int y2;
	int z1;
	int z2;
	int x3;
	int y3;
	int z3;
	int x4;
	int y4;
	int z4;

	cout << "введите координаты первой точки =====>"; cin >> x1 >> y1 >> z1;

	cout << "введите координаты второй точки =====>"; cin >> x2 >> y2 >> z2;

	cout << "введите координаты третей точки =====>"; cin >> x3 >> y3 >> z3;

	cout << "введите координаты четвертой точки =====>"; cin >> x4 >> y4 >> z4;

	cout << "\n\n";

	Point A = Point(x1, y1, z1);
	Point B = Point(x2, y2, z2);
	Point C = Point(x3, y3, z3);
	Point D = Point(x4, y4, z4);

	Vector AB = Vector(A, B);
	Vector CD = Vector(C, D);

	int vector_scalar = AB.scalar_product(CD);

	cout << "разность векторов = (" << AB.get_x() - CD.get_x() << ","
		<< AB.get_y() - CD.get_y() << "," << AB.get_z() - CD.get_z() << ")" << endl;

	cout << "скалярное произведение = " << vector_scalar;

	cout << "\n\n";

	return 0;

}