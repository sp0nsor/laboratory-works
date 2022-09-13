#ifndef IOSTUDENT_H
#define IOSTUDENT_H

/* заголовочный файл, описывающий операторы для организации потокового ввода-вывода переменных объектных типов данных STUDENT (Студент) и GROUP (Группа) */

#include "students.h"

/* Ввод информации о студенте из потока */
istream& operator>>(istream& in, STUDENT& Student);

/* Вывод информации о студенте в выходной поток */
ostream& operator<<(ostream& out, STUDENT Student);

/* Ввод информации о группе из входного потока */
istream& operator>>(istream& in, GROUP& Group);

/* Вывод информации о группе в выходной поток */
ostream& operator<<(ostream& out, GROUP Group);

#endif

/* =============== конец заголовочного файла ================== */
