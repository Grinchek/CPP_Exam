#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include"Func.h"

using namespace std;


//Function for create/add task
void AddTodo(Todo*& todoli, int& size) {
	Todo todo;
	system("cls");
	cout << "Enter a name of your to-do: ";
	getline(cin, todo.task);
	file.open("Todolist", ios_base::app);
	file << todo.task << "\n";
	cout << "Discribe your todo: ";
	getline(cin, todo.description);
	file << todo.description << "\n";
	cout << "Enter a date(YY:MM:DD): ";
	getline(cin, todo.date_todo);
	file << todo.date_todo << "\n";
	cout << "Enter a time(HH:MM): ";
	getline(cin, todo.time_todo);
	file << todo.date_todo << "\n";
	cout << "Enter a priority(1-Highiest priority,4-Lowest:) ";
	getline(cin, todo.priority);
	file << todo.priority << "\n";
	file.close();
	system("pause");
	size++;
	Todo* temp = new Todo[size];
	for (int i = 0; i < size - 1; i++) {
		temp[i] = todolist[i];
	}
	temp[size - 1] = todo;
	delete[] todolist;
	todolist = temp;
}
//Function for delete wanted task
void DeleteTodo(Todo*& todolist, int& size, int index) {
	if (index < 0 || index >= size) {
		cout << "Index is out of range." << endl;
	}
	size--;
	Todo* temp = new Todo[size];
	for (int i = 0, j = 0; i < size + 1; i++) {
		if (i != index) {
			temp[j] = todolist[i];
			j++;
		}
	}
	delete[] todolist;
	todolist = temp;

}

//Function gives the ability to reduct wanted task
int EditTodo(Todo*& todolist, int& size, int index) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "What field do you waant to edit?" << endl;
	SetConsoleTextAttribute(hConsole, 9);
	cout << "1 - Name of task\n2 - Description\n3 - Date of task" << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "4 - Time of task\n5 - priority\n0 - Exit" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	int editchoise;
	cin >> editchoise;
	cin.ignore();
	switch (editchoise) {
	case 1: {
		cout << "Enter task's new name: " << endl;
		getline(cin, todolist[index].task);
		break;
	}
	case 2: {
		cout << "Enter task's new description: " << endl;
		getline(cin, todolist[index].description);
		break;
	}
	case 3: {
		cout << "Enter task's new daate: " << endl;
		getline(cin, todolist[index].date_todo);
		break;
	}
	case 4: {
		cout << "Enter task's new time: " << endl;
		getline(cin, todolist[index].time_todo);
		break;
	}
	case 5: {
		cout << "Enter task's new prority: " << endl;
		getline(cin, todolist[index].priority);
		break;
	}
	case 0: {
		break;
	}
	}

	file.open("Todolist", std::ofstream::out);
	file.close();
	WriteInfo(todolist, size);
	return 0;

}

//Function for geting info from fil and put it on dynamic array
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
		Todo* todolist = new Todo[size];
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
void WriteInfo(Todo* todolist, int& size) {
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

//Function shows info from array
void ShowInfo(Todo* todolist, int& size) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	for (int i = 0; i < size; i++) {
		SetConsoleTextAttribute(hConsole, 9);
		cout << "Task: " << todolist[i].task << endl;
		cout << "Description: " << todolist[i].description << endl;
		cout << "Date: " << todolist[i].date_todo << endl;
		SetConsoleTextAttribute(hConsole, 6);
		cout << "Time: " << todolist[i].time_todo << endl;
		cout << "Priority: " << todolist[i].priority << endl;
	}
	system("pause");
	SetConsoleTextAttribute(hConsole, 7);
}

//Function helps to sort array by date 
void SortByDate(Todo* todolist, int& size) {
	system("cls");
	for (int i = 0; i < size; i++) {
		Todo temp;
		for (int j = 0; j < size; j++) {
			if (todolist[i].date_todo < todolist[j].date_todo) {
				temp = todolist[j];
				todolist[j] = todolist[i];
				todolist[i] = temp;
			}
		}
	}
}

//Function helps to sort array by priority
void SortByPriority(Todo* todolist, int& size) {
	system("cls");
	for (int i = 0; i < size; i++) {
		Todo temp;
		for (int j = 0; j < size; j++) {
			if (todolist[i].priority < todolist[j].priority) {
				temp = todolist[j];
				todolist[j] = todolist[i];
				todolist[i] = temp;
			}
		}
	}
}

//Function helps to search todo by it name
void SearchByDate(Todo* todolist, int& size) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Enter the date of searching task:";
	string search;
	getline(cin, search);
	for (int i = 0; i < size; i++) {
		if (todolist[i].date_todo == search) {
			SetConsoleTextAttribute(hConsole, 9);
			cout << "Task: " << todolist[i].task << endl;
			cout << "Description: " << todolist[i].description << endl;
			cout << "Date: " << todolist[i].date_todo << endl;
			SetConsoleTextAttribute(hConsole, 6);
			cout << "Time: " << todolist[i].time_todo << endl;
			cout << "Priority: " << todolist[i].priority << endl;
		}
	}
	system("pause");
	SetConsoleTextAttribute(hConsole, 7);
}

//Function helps to search todo by it priority
void SearchByPriority(Todo* todolist, int& size) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Enter the priority of searching task:";
	string search;
	getline(cin, search);
	for (int i = 0; i < size; i++) {
		if (todolist[i].priority == search) {
			SetConsoleTextAttribute(hConsole, 9);
			cout << "Task: " << todolist[i].task << endl;
			cout << "Description: " << todolist[i].description << endl;
			cout << "Date: " << todolist[i].date_todo << endl;
			SetConsoleTextAttribute(hConsole, 6);
			cout << "Time: " << todolist[i].time_todo << endl;
			cout << "Priority: " << todolist[i].priority << endl;
		}
	}
	system("pause");
	SetConsoleTextAttribute(hConsole, 7);
}
