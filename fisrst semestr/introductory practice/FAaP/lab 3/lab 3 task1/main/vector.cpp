#include "vector.h"
#include <math.h>

Vector::Vector() {

	x = 0;
	y = 0;
	z = 0;

}

int Point::get_x() {

	return x;

}

int Point::get_y() {

	return y;

}

int Point::get_z() {

	return z;

}

Point::Point(int x, int y, int z) {

	this->x = x;
	this->y = y;
	this->z = z;
}

int Vector::get_x() {

	return x;

}

int Vector::get_y() {

	return y;

}

int Vector::get_z() {

	return z;

}


Vector::Vector(Point p1, Point p2) {

	this->x = p2.get_x() - p1.get_x();
	this->y = p2.get_y() - p1.get_y();
	this->z = p2.get_z() - p1.get_z();

}

int Vector::scalar_product(Vector v) {

	return ((this->x * v.get_x()) + (this->y * v.get_y()) + (this->z * v.get_z()));

}

