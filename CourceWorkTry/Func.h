#pragma once

struct Todo {
	string task;
	string description;
	string date_todo;
	string time_todo;
	string priority;
};
Todo* todolist = nullptr;
fstream file;

void AddTodo(Todo*& , int& );
void DeleteTodo(Todo*& , int& , int );
int EditTodo(Todo*& , int&, int);
void GetInfo(Todo*& , int& );
void WriteInfo(Todo*, int& );
void ShowInfo(Todo* , int& );
void SortByDate(Todo*, int&);
void SortByPriority(Todo*, int&);
void SearchByDate(Todo*, int&);
void SearchByPriority(Todo*, int&);