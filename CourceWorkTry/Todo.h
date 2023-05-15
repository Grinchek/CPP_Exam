#pragma once

using namespace std;



struct Todo {
	string task;
	string description;
	string date_todo;
	string time_todo;
	string priority;
	void AddTodo(Todo*&, int&);
	void DeleteTodo(Todo*&, int&, int);
	int EditTodo(Todo*&, int&, int);
	void ShowInfo(Todo*& , int& size);

	
	void SortByDate(Todo*&, int&);
	void SortByPriority(Todo*&, int&);
	void SearchByDate(Todo*&, int&);
	void SearchByPriority(Todo*&, int&);
};
