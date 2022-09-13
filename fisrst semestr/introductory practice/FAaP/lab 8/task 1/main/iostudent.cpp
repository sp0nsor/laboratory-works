/* ���������� ���������� ��� ����������� ���������� �����-������ ���������� ��������� ����� ������ STUDENT (�������) � GROUP (������) */

#include <iterator>

using namespace std;

#include "iostudent.h"

/* ======= ���� ���������� � �������� �� �������� ������ ======= */
istream& operator>>(istream& in, STUDENT& Student) {
	in >> Student.LastName;
	in >> Student.FirstName;
	in >> Student.MiddleName;
	in >> Student.Number;
	return in;
}

/* ======= ����� ���������� � �������� � �������� ����� ======== */
ostream& operator<<(ostream& out, STUDENT Student) {
	/* ��������������� ����� ����� ������� */
	out.width(8);
	out.fill('0');
	out << Student.Number << " "
		<< Student.LastName << " "
		<< Student.FirstName[0] << ". "
		<< Student.MiddleName[0] << ".";
	return out;
}

/* ======= ���� ���������� � ������ �� �������� ������ ========= */
istream& operator>>(istream& in, GROUP& Group) {
	in >> Group.Name;
	Group.Students.clear();
	/* ���� ������ ��������� � �������������� ���������� */
	istream_iterator<STUDENT> in_iter(in);
	istream_iterator<STUDENT> in_end;
	while (in_iter != in_end) {
		STUDENT stud = *in_iter;
		Group.Students.push_back(stud);
		in_iter++;
	}
	return in;
}

/* ====== ����� ���������� � ������ � �������� ����� =========== */
ostream& operator<<(ostream& out, GROUP Group) {
	out << "������ ������ " << Group.Name << endl;
	/* ����� ������ ��������� � �������������� ���������� */
	vector<STUDENT>::iterator iter;
	iter = Group.Students.begin();
	while (iter != Group.Students.end()) {
		out << *iter << endl;
		iter++;
	}
	return out;
}

/* ====================== ����� ������ ========================= */
