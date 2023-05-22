#include<iostream>
#include <Windows.h>
#include<string>
#include<fstream>
#include "Todo.h"
#include"Helloes.h"
#include"Clock.h"

using namespace std;

void GetInfo(Todo*&, int&);
void WriteInfo(Todo*&, int&);
//int Unic(Todo*&, int&);

int main() {

	Todo todo;
	fstream file;
	int size = 0;
	Todo* todolist = nullptr;
	GetInfo(todolist, size);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	HELLO();
	system("pause");
	system("cls");
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
			todo.AddTodo(todolist, size);
			//WriteInfo(todolist, size);
			break;
		}
		case 2: {
			if (size == 0) {
				SetConsoleTextAttribute(hConsole, 9);
				cout << "There are no todo yet" << endl;
				SetConsoleTextAttribute(hConsole, 6);
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
					todo.SearchByDate(todolist, size);
				}
					  break;
				case 2: {
					todo.SortByDate(todolist, size);
					todo.SearchByPriority(todolist, size);
				}
					  break;
				case 3: {
					todo.SortByPriority(todolist, size);
					todo.ShowInfo(todolist, size);
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
						todo.EditTodo(todolist, size, index);
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
				todo.DeleteTodo(todolist, size, 0);
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
						todo.DeleteTodo(todolist, size, index);
						file.open("Todolist", std::ofstream::out);
						file.close();
						WriteInfo(todolist, size);
					}
					else {
						cout << "Wrong task entered." << endl;
					}
				}
			}
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

//Function for geting info from file and put it on dynamic array
void GetInfo(Todo*& todolist, int& size) {
	fstream file;
	file.open("Todolist", ios_base::in);
	if (file.is_open()) {
		string line;
		int count = 0;
		while (getline(file, line)) {
			count++;
		}
		size = count / 5;
		file.clear();
		file.seekg(0, ios::beg);
		todolist = new Todo[size];
		int i = 0;
		while (i < size) {
			getline(file, todolist[i].task);
			getline(file, todolist[i].description);
			getline(file, todolist[i].date_todo);
			getline(file, todolist[i].time_todo);
			getline(file, todolist[i].priority);
			i++;
		}
	}
	file.close();
}
//Function for writing info into file
void WriteInfo(Todo*& todolist, int& size) {
	fstream file;
	file.open("Todolist", ios_base::trunc);
	file.close();
	file.open("Todolist", ios_base::app);
	if (file.is_open()) {
		for (int i = 0; i < size; i++) {
			file << todolist[i].task << "\n";
			file << todolist[i].description << "\n";
			file << todolist[i].date_todo << "\n";
			file << todolist[i].time_todo << "\n";
			file << todolist[i].priority << "\n";
		}
	}
	file.close();
}
//function for checking tasks by unic name;
//int Unic(Todo*& todolist, int& size) {
//	for (int i = 0; i < size-1;i++) {
//		if (todolist[i].task == todolist[i + 1].task) {
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}
//
//
//
//}