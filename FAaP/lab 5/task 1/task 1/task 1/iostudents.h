#pragma once
#include "students.h"
// ���� ���������� � �������� �� ������
istream& operator >> (istream& in, STUDENT& Student);
// ����� ���������� � �������� � �������� �����
ostream& operator << (ostream& out, STUDENT Student);
// ���� ���������� � ������ �� �������� ������
istream& operator >> (istream& in, GROUP& Group);
// ����� ���������� � ������ � �������� �����
ostream& operator << (ostream& out, GROUP Group);