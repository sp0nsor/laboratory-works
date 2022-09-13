
#ifndef STUDENTS_H
#define STUDENTS_H


struct TIME {

	int minutes;
	char doubledot;
	int secundes;

};

// ------- �������� ������������ ���� ������ ������� -----------
struct SONG {
	char Name[15];      // �������� �����
	char Singer[15];    // ��� �����������
	char Style[15];     // ����� �����
	TIME Long;        // �����������������
};



// ------- �������� ������������ ���� ������ ������ ------------
struct ALBUM {
	char Name[10];          // �������� ������
	int N;                 // ���������� ���������
	SONG* Song;     // ������ ���������
	char usersinger[15];
	bool issetsinger = false;
};



#endif
