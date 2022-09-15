#include <iostream>
#include<windows.h>
using namespace std;

class Point {

private:
	double x;
	double y;

public:
	double get_x (){

		return x;

	}

	double get_y() {

		return y;

	}

	Point(double x, double y) {

		this->x = x;
		this->y = y;

	}

};

class Vector {

private:
	double x;
	double y;

public:
	Vector(Point A, Point B) {

		x = A.get_x() - B.get_x();
		y = A.get_y() - B.get_y();

	}

	Point get_end(Point A) {

		return Point(A.get_x() - x, A.get_y() - y);

	}

	Point get_end_2(Point A) {


		return Point(A.get_x() + x, A.get_y() + y);

	}

	Point get_end_3(Point A) {


		return Point(-1*(A.get_x() + x), A.get_y() - y);

	}

};

ostream& operator << (ostream& os, Point point) {

	os << point.get_x() << " " << point.get_y();
	return os;

}


void main(){
	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);

	double x1;
	double y1;
	double x2;
	double y2;
	double x3;
	double y3;

	cout << "Введите координаты первой точки ====>";
	cin >> x1 >> y1;
	cout << "Введите координат второй точки =====>";
	cin >> x2 >> y2;
	cout << "Введите координаты третьей точки ====>";
	cin >> x3 >> y3;

	Point A = Point(x2, y2);
	Point B = Point(x1, y1);
	Vector AB = Vector(A, B);
	Vector AE = Vector(A, B);
	Vector AF = Vector(A, B);
	Point D = AB.get_end(Point(x3, y3));
	Point E = AE.get_end_2(Point(x3, y3));
	Point F = AF.get_end_3(Point(x3, y3));

	cout << "Координаты четвертой точки (" << D.get_x() << "," << D.get_y() << ")" << endl;
	cout << "Координаты четвертой точки (" << E.get_x() << "," << E.get_y() << ")" << endl;
	cout << "Координаты четвертой точки (" << F.get_x() << "," << F.get_y() << ")" << endl;

}