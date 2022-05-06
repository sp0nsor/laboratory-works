
/***************************************************************
 *                                                             *
 * ����     : geometry.cpp                                     *
 *                                                             *
 * �������� : ������, ���������� ���������� ������� �������    *
 *            ��� ������� �������������� �����                 *
 *                                                             *
 ***************************************************************/

#include <math.h>
#include "geometry.h"
#include <iostream>

    using namespace std;

// -------------------------------------------------------------
//       ������ ������ "�����" 
// -------------------------------------------------------------

// �����������: ����� �������� ������ ������������
Point::Point(double X, double Y) {
    x = X; y = Y;
}

// ��������� ���������� �
double Point::getX() {
    return x;
}

// ��������� ���������� �
double Point::getY() {
    return y;
}

// -------------------------------------------------------------
//       ������ ������ "����������" 
// -------------------------------------------------------------

// �����������: ���������� �������� ������� � ��������
Circle::Circle(Point Center, double R) :center(Center) {
    r = R;
}

// ��������� ����� ����������
Point Circle::getCenter() {
    return center;
}

// ��������� ������ ����������
double Circle::getR() {
    return r;
}

void Circle::info() {
    cout << "����� ���������� ���������� � ����� ("
        << this->getCenter().getX() << ',' << this->getCenter().getY()
        << "), ������ = " << this->getR() << endl;
}


// -------------------------------------------------------------
//       ������ ������ "������" 
// -------------------------------------------------------------

// �����������: ������ �������� ������ ��������������
Line::Line(double a, double b, double c) {
    A = a; B = b; C = c;
}

// �����������: ������, ������� �������� ����� ��� �������� �����
Line::Line(Point p1, Point p2) {
    A = p2.getY() - p1.getY();
    B = p1.getX() - p2.getX();
    C = -A * p1.getX() - B * p1.getY();
}

// ����� ����� ����������� � �������� ������
Point Line::getIntersect(Line line) {
    double d = A * line.B - B * line.A,
        d1 = -(C * line.B - B * line.C),
        d2 = -(A * line.C - C * line.A);
    return Point(d1 / d, d2 / d);
}

// ��������� ���������������� ������, ���������� ����� �������� �����
Line Line::getPerpendicular(Point p) {
    return Line(B, -A, -B * p.getX() + A * p.getY());
}

// -------------------------------------------------------------
//       ������ ������ "�������" 
// -------------------------------------------------------------

// �����������: ������� �������� ����� �������
Segment::Segment(Point p1, Point p2) {
    x1 = p1.getX(); y1 = p1.getY();
    x2 = p2.getX(); y2 = p2.getY();
}

// ����� �������� �������
Point Segment::getMidpoint() {
    return Point((x1 + x2) / 2, (y1 + y2) / 2);
}

// ����� ����� �������
double Segment::getLength() {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// -------------------------------------------------------------
//       ������ ������ "������" 
// -------------------------------------------------------------

Vector::Vector(Point p1, Point p2) {
    this->x = p2.getX() - p1.getX();
    this->y = p2.getY() - p1.getY();
}

long double Vector::scalar_product(Vector v2) {
    return this->x * v2.x + this->y * v2.y;
}

Vector Vector::vector_sum(Vector v1, Vector v2) {
    return Vector(Point(-v1.x, -v1.x), Point(v2.x, v2.y));
}

void Vector::multiply_by_scalar(long double scalar) {
    this->x *= scalar;
    this->y *= scalar;
}

long double Vector::get_x() {
    return this->x;
}

long double Vector::get_y() {
    return this->y;
}

void Vector::info() {

    ostream& operator << (ostream & stream, Vector obj) {

        stream << obj.x << ", ";
        stream << obj.y << "\n";
        return stream;

    }

}

/*void Vector::info() {
    cout << "\n\n" <<
        "���������� x: " << this->x << "\n"
        "���������� y: " << this->y << endl;
}

// ============== ����� ������ =================================*/
