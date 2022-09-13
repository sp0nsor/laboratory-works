
#include "iomusic.h"
#include<vector>



istream& operator >> (istream& in, TIME& Long)
{
    in >> Long.minutes;
    in >> Long.doubledot;
    in >> Long.secundes;
    return in;
}



ostream& operator << (ostream& out, TIME Long)
{
    out.width(2);
    out.fill('0');
    out << Long.minutes
        << Long.doubledot;
    if (Long.secundes == 0) out << "00 ";
    if (Long.secundes > 0) out << Long.secundes;

    return out;
}










// ======= Ввод информации о студенте из входного потока =======
istream& operator >> (istream& in, SONG& Song)
{
    in >> Song.Name;
    in >> Song.Singer;
    in >> Song.Style;
    in >> Song.Long;
    return in;
}



// ======= Вывод информации о студенте в выходной поток ========
ostream& operator << (ostream& out, SONG Song)
{
    out.width(2);
    out.fill('0');
    out << Song.Name << " "
        << Song.Singer << " "
        << Song.Style << " "
        << Song.Long << "\n";
    return out;
}



// ======= Ввод информации о группе из входного потока =========
istream& operator >> (istream& in, ALBUM& Album)
{
    in >> Album.Name;
    in >> Album.N;
    Album.Song = new SONG[Album.N];
    for (int i = 0; i < Album.N; i++)
    {
        in >> Album.Song[i];
    }
    return in;
}





// ====== Вывод информации о группе в выходной поток ========== =
ostream& operator << (ostream& out, ALBUM Album)
{
    out << "Список песен, отсортированный по продолжительности песен: " << endl << Album.Name << endl;


    // Осталось только сортировку сюда запихнуть и всё ок будет (ну и вывод песен указанного исполнителя нужно сделать)

    int songlong, minlong = 999999, imin = -1;
    vector<int> veci;
    bool iswas = false;

    for (int i = 0; i < 5; ++i) {

        if (!Album.issetsinger) {

            for (int j = 0; j < 5; ++j) {

                songlong = Album.Song[j].Long.minutes * 60 + Album.Song[j].Long.secundes;

                //if ((songlong < minlong) && (!iswas)) {
                if (songlong < minlong) {

                    for (int k = 0; k < veci.size(); ++k) {

                        if (j == veci[k]) iswas = true;

                    }

                    if (!iswas) {

                        minlong = songlong;
                        imin = j;


                    }

                    iswas = false;

                }



            }


            out << Album.Song[imin];
            veci.push_back(imin);
            imin = -1;
            minlong = 999999;

        }







        // Сортировка в наличии, остался фильтр. Тут оказалось сложнее, но ничего, справимся (справлюсь)





        if (Album.issetsinger) {
            /*
            for (int j = 0; j < 5; ++j) {

                //for (int j = 0; j < 5; ++j) {

                //    songlong = Album.Song[j].Long.minutes * 60 + Album.Song[j].Long.secundes;

                //    //if ((songlong < minlong) && (!iswas)) {
                //    if (songlong < minlong) {

                //        for (int k = 0; k < veci.size(); ++k) {

                //            if (j == veci[k]) iswas = true;

                //        }

                //        if (!iswas) {

                //            minlong = songlong;
                //            imin = j;


                //        }

                //        iswas = false;

                //    }



                //}


                if (Album.Song[j].Singer == Album.usersinger) {

                    out << Album.Song[j];

                    //veci.push_back(imin);
                    //imin = -1;
                    //minlong = 999999;

                }

            }
            */


            bool odinak = true;

            for (int j = 0; j < strlen(Album.usersinger); ++j) {

                if (Album.Song[i].Singer[j] != Album.usersinger[j]) {

                    odinak = false;
                    break;

                }

            }

            if (odinak) out << Album.Song[i];





            //if (Album.Song[i].Singer == Album.usersinger) out << Album.Song[i];
            //veci.push_back(imin);
            //iswas = false;

        }




        //out << Album.Song[imin];
        //thisalbum.Song[imin].Long.minutes = 9999999;
        //minlong = 999999;



    }



    //for (int i = 0; i < Album.N; i++) out << Album.Song[i];

    //
    return out;
    //
}