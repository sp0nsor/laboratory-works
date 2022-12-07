#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "BinaryTree.h"

using namespace std;

HANDLE hConsoleHandle = GetStdHandle(-11);

void purple() {
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void lime() {
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void red() {
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void grey() {
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_INTENSITY);
}
void white() {
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void BST::SpecialPrint() {
    SpecialPrintPrivate(root, 0, 0);
}

int rec[100] = { 0 };
int key = 0;
void BST::SpecialPrintPrivate(node* Ptr, int depth, int side) {
    int i;
    if (Ptr == nullptr) {
        if (side == 0)
            return;
        else {
            for (i = -1; i < depth; i++) {
                if (i == depth - 1) {
                    wprintf(L"%s\u2014\u2014\u2014", rec[depth - 1] ? 1, L"\u251C" : L"\u2514");
                }
                else {
                    wprintf(L"%s    ", (rec[i] && i >= 0) ? L"\u2502" : L"    ");
                }
            }
            if (side == -1) {
                purple();
                wprintf(L"L:");
                red();
                wprintf(L"-\n");
                white();
            }
            if (side == 1) {
                lime();
                wprintf(L"R:");
                red();
                wprintf(L"-\n");
                white();
            }
            return;
        }
    }
    if (Ptr->key != root->key) wcout << "\t";
    else (wcout << "   ");

    for (i = 0; i < depth; i++) {
        if (i == depth - 1) {
            wprintf(L"%s\u2014\u2014\u2014", rec[depth - 1] ? key = 1, L"\u251C" : L"\u2514");
        }
        else {
            wprintf(L"%s    ", rec[i] ? L"\u2502" : L"    ");
        }
    }
    if (root->key == Ptr->key) {
        red();
        wcout << L"Root:";
    }
    else if (key == 0) {
        lime();
        wcout << L"R:";
    }
    else {
        purple();
        wcout << L"L:";
    }
    white();
    wcout << Ptr->key << "\n";
    key = 0;
    if (Ptr->left != nullptr || Ptr->right != nullptr) {
        rec[depth] = 1;
        SpecialPrintPrivate(Ptr->left, depth + 1, -1);
        rec[depth] = 0;
        SpecialPrintPrivate(Ptr->right, depth + 1, 1);
    }
}
