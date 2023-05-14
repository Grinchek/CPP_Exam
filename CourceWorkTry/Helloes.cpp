#include"Helloes.h"
#include<iostream>
#include<Windows.h>

using namespace std;

void HELLO() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
	Sleep(65);
	cout << "TTTTTTTTTTTTTT        OO               DDDDDDDDD             OO                                    " << endl;
	SetConsoleTextAttribute(hConsole, 9);
	Sleep(65);
	cout << "      TT            OO  OO             DD       DD         OO  OO                                  " << endl;
	SetConsoleTextAttribute(hConsole, 9);
	Sleep(65);
	cout << "      TT          OO      OO           DD         DD     OO      OO                                " << endl;
	SetConsoleTextAttribute(hConsole, 9);
	Sleep(65);
	cout << "      TT        OO          OO         DD          DD  OO          OO           I                  " << endl;
	SetConsoleTextAttribute(hConsole, 9);
	Sleep(65);
	cout << "      TT        OO          OO  =====  DD          DD  OO          OO                              " << endl;
	SetConsoleTextAttribute(hConsole, 9);
	Sleep(65);
	cout << "      TT        OO          OO  =====  DD          DD  OO          OO  L        I    ss     TTTTTTT" << endl;
	SetConsoleTextAttribute(hConsole, 9);
	Sleep(65);
	cout << "      TT        OO          OO         DD          DD  OO          OO  L        I   S   S      T   " << endl;
	SetConsoleTextAttribute(hConsole, 6);
	Sleep(65);
	cout << "      TT        OO          OO         DD          DD  OO          OO  L        I  S           T   " << endl;
	SetConsoleTextAttribute(hConsole, 6);
	Sleep(65);
	cout << "      TT        OO          OO         DD          DD  OO          OO  L        I    ss        T   " << endl;
	SetConsoleTextAttribute(hConsole, 6);
	Sleep(65);
	cout << "      TT          OO      OO           DD         DD     OO      OO    L        I       S      T   " << endl;
	SetConsoleTextAttribute(hConsole, 6);
	Sleep(65);
	cout << "      TT            OO  OO             DD       DD         OO  OO      L        I   S    S     T   " << endl;
	SetConsoleTextAttribute(hConsole, 6);
	Sleep(65);
	cout << "      TT              OO               DDDDDDDDD             OO        LLLLLLL  I    ss        T   " << endl;
	SetConsoleTextAttribute(hConsole, 7);

}