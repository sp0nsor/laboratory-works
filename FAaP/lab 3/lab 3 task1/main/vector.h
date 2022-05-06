#pragma once

class Point {

private:

	int x;
	int y;
	int z;

public:

	int get_x();
	int get_y();
	int get_z();
	Point(int x, int y, int z);

};

class Vector {

private:

	int x;
	int y;
	int z;

public:

	Vector();
	int get_x();
	int get_y();
	int get_z();
	Vector(Point p1, Point p2);
	int scalar_product(Vector v1);
	
};