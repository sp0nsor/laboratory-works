#include<iostream>
#include <string>
using namespace std;

int factorial_product(int n) {

	int res = 1;
	for (int i = 1; i <= n; i++) {

		res *=i;

	}
	return res;
}

void main() {

	setlocale(LC_ALL, "ru");
	int N;
	int K;
	int del;
	int result;
	string line;
	cout << "строка =================>";
	cin >> line;
	cout << "длинна новых строк =====>";
	cin >> K;
	N = line.length();
	del = N - K;
	
	result = (factorial_product(N)) / (factorial_product(K) * factorial_product(del));

	cout << "количество строк длинны К из букв N = " << result;

}