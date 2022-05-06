#include <iostream>
#include <string>

using namespace std;

string buf;            
int len1[10];                     
int len2[10];                  
int countt1 = 0;                     
int countt2 = 1;                          
string s;                           
int arr[40][40];


void input_array(string s, int n)
{
    arr[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            arr[i][i] = 1;
            int k = i;
            while (s[k] != s[j])
                k--;
            if (s[i] == s[k]) {
                arr[i][j] = arr[i - 1][j + 1] + 2;
            }
            else arr[i][j] = max(arr[i - 1][j], arr[i][j + 1]);
        }
    }
}

void main() {
    int cs = 1;
    int n = 0;

    setlocale(LC_ALL, "ru");

    cout << "введите палиндром =====>";
    cin >> buf;
    string tmp;     
    int fl = 1;
    while (fl == 1)
    {
        if (string(buf) != tmp)
        {
            s = s + string(buf);
            countt1++;
            tmp = string(buf);
        }
        else
            fl = 0;
    }
    int co = size(buf);
    input_array(buf, co);
    cout <<"длинна наибольшего палиндрома равна " << (arr[co - 1][0])<< " символов" << endl;

    system("pause");
}