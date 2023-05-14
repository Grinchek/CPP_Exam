#include"Clock.h"
#include"Helloes.h"
#include"Func.h"
#include <Windows.h>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	HELLO();
	system("pause");
	system("cls");
	Todo* todolist = nullptr;
	int size = 0;
	int index = 0;
	GetInfo(todolist, size);
	bool exit = false;
	while (!exit) {
		system("cls");
		cout << "Choose an option:" << endl;
		SetConsoleTextAttribute(hConsole, 9);
		cout << "1 - Create/Add a new task" << endl;
		cout << "2 - Show tasks" << endl;
		cout << "3 - Redurkt tasks" << endl;
		SetConsoleTextAttribute(hConsole, 6);
		cout << "4 - Show date and time" << endl;
		cout << "5 - Delete todo" << endl;
		cout << "0 - Exit" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		int choice;
		cin >> choice;
		system("cls");
		cin.ignore();
		switch (choice) {
		case 1: {
			AddTodo(todolist, size);
			break;
		}
		case 2: {
			if (size == 0) {
				cout << "There are no todo yet" << endl;
				system("pause");
			}
			else {
				cout << "By wich parameter wold you like to show info? " << endl;
				SetConsoleTextAttribute(hConsole, 9);
				cout << "1 - By date and time " << endl;
				cout << "2 - By priority " << endl;
				SetConsoleTextAttribute(hConsole, 6);
				cout << "3 - Show all tasks " << endl;
				cout << "0 - Exit " << endl;
				SetConsoleTextAttribute(hConsole, 7);
				int showChoice;
				cin >> showChoice;
				cin.ignore();
				switch (showChoice) {
				case 1: {
					SearchByDate(todolist, size);
				}
					  break;
				case 2: {
					SortByDate(todolist, size);
					SearchByPriority(todolist, size);
				}
					  break;
				case 3: {
					SortByPriority(todolist, size);
					ShowInfo(todolist, size);
				}
					  break;
				case 0: {
					break;
				}
				default: {
					cout << "Wrong choise" << endl;
				}
					   break;
				}
			}
			break;
		}
		case 3: {
			if (size == 0) {
				cout << "There are no todo yet" << endl;
				system("pause");
			}
			else {
				cout << "Enter task to reduct: ";
				string redTask;
				getline(cin, redTask);
				for (int i = 0; i < size; i++) {
					if (redTask == todolist[i].task) {
						index = i;
						EditTodo(todolist, size, index);
					}
					else {
						cout << "Wrong task entered" << endl;
					}
				}
			}
			break;
		}
		case 4: {
			Time();
			break;
		}
		case 5: {
			if (size == 0) {
				cout << "There are no todo yet" << endl;
				system("pause");
			}
			else if (size == 1) {
				DeleteTodo(todolist, size, 0);
				file.open("Todolist", std::ofstream::out);
				file.close();
			}
			else {
				cout << "Enter task to delete: ";
				string delTask;
				cin >> delTask;
				cin.ignore();
				for (int i = 0; i < size; i++) {
					if (delTask == todolist[i].task) {
						index = i;
						DeleteTodo(todolist, size, index);
						file.open("Todolist", std::ofstream::out);
						file.close();
						WriteInfo(todolist, size);
					}
					else {
						cout << "Wrong task entered." << endl;
					}
				}
			}
			WriteInfo(todolist, size);
			break;
		}
		case 0: {
			system("cls");
			HELLO();
			exit = true;
			break;
		}
		default:
			cout << "Invalid choice. Try again." << endl;
			break;
		}
	}
	delete[] todolist;

}