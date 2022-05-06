#include <iostream>
#include <string>
using namespace std;

// алитплтиплимлмьалдиьплилмалмьад

void main(int argc,char* argv[]) {

	setlocale(LC_ALL, "Ru");

	char Str1[100];
	char Str2[100];
	cin.getline(Str1, 100);
	cin.getline(Str2, 100);

	string S1(Str1);
	string S2(Str2);
	string S3 = " ";
	string S4 = "";
	unsigned int res;
	unsigned int cnt;
	unsigned int i = 0;
	
	res = (S1.size() + S2.size());

	while (S3.size()<= res) {

		S3 += string{ S1[i] } + string{ S2[i] };
		i++;
		
	}


	cout << S3;
	
}