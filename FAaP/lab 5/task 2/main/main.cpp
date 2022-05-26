
#include <iostream>
#include <fstream>
#include <windows.h>

#include "music.h"
#include "iomusic.h"

using namespace std;



int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    char FileName[100];
    cout << "Из какого файла вводить данные?\n";
    cin.getline(FileName, sizeof(FileName));
    cout << endl;


    ALBUM Album;



    // создать поток для ввода данных из файла
    ifstream fin(FileName);




    if (fin.is_open()) {


        // прочитать группу из этого потока
        fin >> Album;


        // закрыть поток
        fin.close();


        // вывести группу в поток cout (на экран)
        cout << Album;


        //char* singer = new char;

        cout << endl << "Выберите, песни какого исполнителя найти: ";
        cin.getline(Album.usersinger, sizeof(Album.usersinger));
        Album.issetsinger = true;


        cout << endl;
        cout << "В какой файл выводить данные?\n";
        cin.getline(FileName, sizeof(FileName));




        // создать поток для вывода данных в файл
        ofstream fout(FileName);
        if (fout.is_open())
        {

            // записать группу в этот файл
            fout << Album;
            fout.close();
            cout << "Данные выведены в файл " << FileName << endl;

        }
        else
        {

            cout << "Ошибка записи в файл " << FileName << endl;

        }

    }
    else {

        cout << "Файл " << FileName << " не найден\n";

    }



    return 0;
}

