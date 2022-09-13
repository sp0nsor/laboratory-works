/***************************************************************
**
* Файл     : triangle.cpp*
**
* Описание : главный файл проекта для демонстрации*
* использования объектов для решения*
* геометрических задач*
**
***************************************************************
**
* Дано     : Координаты вершин треугольника.*
* Найти : Описанную около этого треугольника окружность.*
**
*************************************************************** */

#include <windows.h>
#include "geometry.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    SetConsoleOutputCP(1251);

    // ----- ввод исходных данных -----
    double x1, y1, x2, y2, x3, y3;
    cout << "Введите координаты первой точки ===> ";
    cin >> x1 >> y1;
    cout << "Введите координаты второй точки ===> ";
    cin >> x2 >> y2;
    cout << "Введите координаты третьей точки ==> ";
    cin >> x3 >> y3;

    // ----- создание точек - вершин треугольника -----
    Point A = Point(x1, y1),
        B = Point(x2, y2),
        D = Point(x3, y3);
        


    // ----- создание отрезка - радиуса -----
    Segment first_radius = Segment(A, D);

    // ----- создание окружности с заданным центром и радиусом -----
    Circle first_circle = Circle(B, first_radius.getLength());

    Segment second_radius = Segment(A, B);
    Circle second_circle = Circle(D, second_radius.getLength());

    Segment distance = Segment(B,D);




    // ----- вывод результата ----
    first_circle.info();
    second_circle.info();

    Sleep(9999);
    return 0;
}

// ================= конец программы ===========================