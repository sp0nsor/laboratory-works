#include "students.h"
#include <algorithm>
// �������� ��� ��������� ���� ��������� ����� �����

bool operator < (STUDENT stud1, STUDENT stud2) {
	// ���������� �� ������ ������������� ������
	bool result = stud1.Number < stud2.Number;
	return result;
}

// =========== ����� ��� ������������ ������ ������
void GROUP::sort() {
	// ��������� ���������� ���������� Students � �������
  // ������������� ��������� sort
	std::sort(this->Students.begin(), this->Students.end());
	// �� ��������� ������� ���������� ���������� ������������
	  // ������������� ���������� <
}