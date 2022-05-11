﻿/***************************************************************
 *                                                             *
 * Файл     : geometry.cpp                                     *
 *                                                             *
 * Описание : модуль, содержащий реализацию методов классов    *
 *            для решения геометрических задач                 *
 *                                                             *
 ***************************************************************/

#include <math.h>
#include "geometry.h"

// -------------------------------------------------------------
//       Методы класса "Точка" 
// -------------------------------------------------------------

// конструктор: точка задается своими координатами
Point::Point(double X, double Y) {
  x=X; y=Y;
  }

// прочитать координату Х
double Point::getX() {
  return x;
  }

// прочитать координату У
double Point::getY() {
  return y;
  }

// -------------------------------------------------------------
//       Методы класса "Окружность" 
// -------------------------------------------------------------

// конструктор: окружность задается центром и радиусом
Circle::Circle(Point Center, double R):center(Center) {
  r=R;
  }

// прочитать центр окружности
Point Circle::getCenter() {
  return center;
  }

// прочитать радиус окружности
double Circle::getR() {
  return r;
  }

// -------------------------------------------------------------
//       Методы класса "Прямая" 
// -------------------------------------------------------------

// конструктор: прямая задается своими коэффициентами
Line::Line(double a,double b,double c) {
  A=a; B=b; C=c;
  }

// конструктор: прямая, которая проходит через две заданные точки
Line::Line(Point p1,Point p2) {
  A=p2.getY()-p1.getY();
  B=p1.getX()-p2.getX();
  C=-A*p1.getX()-B*p1.getY();
  }

// найти точку пересечения с заданной прямой
Point Line::getIntersect(Line line) {
  double d =A*line.B-B*line.A,
         d1=-(C*line.B-B*line.C),
         d2=-(A*line.C-C*line.A);
  return Point(d1/d,d2/d);
  }

// построить перпендикулярную прямую, проходящую через заданную точку
Line Line::getPerpendicular(Point p) {
  return Line(B,-A,-B*p.getX()+A*p.getY());
  }

// -------------------------------------------------------------
//       Методы класса "Отрезок" 
// -------------------------------------------------------------

// конструктор: отрезок задается двумя точками
Segment::Segment(Point p1,Point p2) {
  x1=p1.getX(); y1=p1.getY();
  x2=p2.getX(); y2=p2.getY();
  }

// найти середину отрезка
Point Segment::getMidpoint() {
  return Point( (x1+x2)/2,(y1+y2)/2 );
  }

// найти длину отрезка
double Segment::getLength() {
  return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
  }

// ============== конец модуля =================================
