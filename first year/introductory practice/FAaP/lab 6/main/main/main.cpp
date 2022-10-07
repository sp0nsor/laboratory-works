#include <iostream>
#include <string>
using namespace std;


void main(int argc,char* argv[]) {

	setlocale(LC_ALL, "Ru");

	char Str1[100];
	char Str2[100];

	cout << "enter first line ====>";
	cin.getline(Str1, 100);
	cout << "enter second line ===>";
	cin.getline(Str2, 100);

	string S1(Str1);
	string S2(Str2);
	string S3 = " ";
	string S4 = "";
	unsigned int res;
	unsigned int zxc = 0;
	unsigned int i = 0;

	
	if (S1.size() > S2.size()) {

		for (unsigned a = S2.size(); a <= S1.size(); a++) {

			S4 += string{ S1[a] };

		}

	}
	if (S2.size() > S1.size()) {

		for (unsigned a = S1.size(); a < S2.size(); a++) {

			S4 += string{ S2[a] };

		}

	}

	res = (S1.size() + S2.size()) - S4.size();

	while (S3.size()<= res) {
		
		S3 += string{ S1[i] } + string{ S2[i] };
		i++;

	}

	cout << "new line: " << S3 + S4;

	system("pause>>void");
	
}