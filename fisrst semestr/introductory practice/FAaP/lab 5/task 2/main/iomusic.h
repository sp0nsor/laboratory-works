
#ifndef IOSTUDENT_H
#define IOSTUDENT_H

#include <iostream>
#include "music.h"

using namespace std;


// ���� ���������� � �������� �� ������
istream& operator >> (istream& in, SONG& Student);



// ����� ���������� � �������� � �������� �����
ostream& operator << (ostream& out, SONG Student);



// ���� ���������� � ������ �� �������� ������
istream& operator >> (istream& in, ALBUM& Group);



// ����� ���������� � ������ � �������� �����
ostream& operator << (ostream& out, ALBUM Group);




#endif
