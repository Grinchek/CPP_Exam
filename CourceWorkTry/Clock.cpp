#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include<Windows.h>
#include"Clock.h"

using namespace std;

void Time() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    time_t now = time(0);

    for (int i = 1; i < 6; i++) {
        SetConsoleTextAttribute(hConsole, 6);
        cout << ctime(&now);
        Sleep(1);
        now = time(0);
        Sleep(1000);
        system("cls");
    }
    SetConsoleTextAttribute(hConsole, 7);
}