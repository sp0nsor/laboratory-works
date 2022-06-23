#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ifstream in("file.txt"); // Открыли файл
    ofstream out("new_sorted_file.txt");
    string buf; // переменная, в которую будем считывать данные
    while (!in.eof()) {
        getline(in, buf); // Считали
        if (buf.size() > 30)
            out << buf << endl;
    }
    in.close();
    out.close();
    return 0;
}


