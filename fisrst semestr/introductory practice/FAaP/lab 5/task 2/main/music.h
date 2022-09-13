
#ifndef STUDENTS_H
#define STUDENTS_H


struct TIME {

	int minutes;
	char doubledot;
	int secundes;

};

// ------- описание структурного типа данных СТУДЕНТ -----------
struct SONG {
	char Name[15];      // Название песни
	char Singer[15];    // Имя исполнителя
	char Style[15];     // Стиль песни
	TIME Long;        // Продолжительность
};



// ------- описание структурного типа данных ГРУППА ------------
struct ALBUM {
	char Name[10];          // Название группы
	int N;                 // Количество студентов
	SONG* Song;     // Массив студентов
	char usersinger[15];
	bool issetsinger = false;
};



#endif
