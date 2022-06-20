#include <iostream>
using namespace std;

void main() {

	setlocale(LC_ALL, "ru");

	int x1;
	int x2;
	int y1;
	int y2;
	int r;

	cout << "координаты прямой > ";
	cin >> x1 >> y1;
	cout << "координаты радиуса > ";
	cin >> x2 >> y2;
	cout << "радиус > ";
	cin >> r;

	if (((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) < r * r) {

		cout << "В окружности" << endl;

	}
	if (((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) == r * r) {

		cout << "На  окружности" << endl;

	}
	if (((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) > r * r) {

		cout << "За окружностью" << endl;

	}

	system("pause>>void");
}