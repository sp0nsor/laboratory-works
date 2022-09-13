
#ifndef IOSTUDENT_H
#define IOSTUDENT_H

#include <iostream>
#include "music.h"

using namespace std;


// Ввод информации о студенте из потока
istream& operator >> (istream& in, SONG& Student);



// Вывод информации о студенте в выходной поток
ostream& operator << (ostream& out, SONG Student);



// Ввод информации о группе из входного потока
istream& operator >> (istream& in, ALBUM& Group);



// Вывод информации о группе в выходной поток
ostream& operator << (ostream& out, ALBUM Group);




#endif
