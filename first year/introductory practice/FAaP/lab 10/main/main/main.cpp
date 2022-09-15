#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#include <locale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int q = 0;
    while (q != 3)
    {
        cout << "Выбирите ваше действие: \n" <<
            "1. Добавление слова/Выход из ввода \n" <<
            "2. Поиск слова для перевода/Выход из поиска" <<
            "3. Выход из программы" << endl;
        cin >> q;
        switch (q)
        {
        case 1:
        {
            int i;
            char rus[300];
            char eng[300];
            std::ofstream cout("slovar.txt", std::ios::app);
            do
            {
                std::cout << "Для нового ввода нажмите 1, для выхода 0:\n> ", std::cin >> i;
                fflush(stdin);
                if (!i)
                    break;
                std::cout << "Введите слово на русском:\n> ", std::cin.getline(rus, 300);
                std::cout << "Введите слово на английском:\n> ", std::cin.getline(eng, 300);
                cout << '\n' << eng << ' ' << rus;
            } while (i);
            break;
        }

        case 2:
        {
            ifstream in("slovar.txt");
            string s1, s2;
            map<string, string> slovar;
            while (in >> s1 >> s2)
            {
                transform(s1.begin(), s1.end(), s1.begin(), tolower); //перевод в нижний регистр
                transform(s2.begin(), s2.end(), s2.begin(), tolower);
                slovar[s1] = s2;
                slovar[s2] = s1;
            }
            in.close();
            while (1)
            {
                cout << "Введите слово на английском или на русском которое хотите перевести, или exit чтобы выйти: ";
                cin >> s1;
                transform(s1.begin(), s1.end(), s1.begin(), tolower);
                if (s1 == "exit") break;
                if (slovar.find(s1) != slovar.end())
                    cout << "Перевод слова: " << slovar[s1] << endl;
                else cout << "В словаре этого слова не найдено" << endl;
            }
        }
        }
    }
}