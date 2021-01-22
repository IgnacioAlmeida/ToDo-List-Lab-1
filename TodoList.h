#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include "TodoListInterface.h"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class TodoList: public TodoListInterface {
public:
	vector <string> tasks;
	TodoList() {
		//cout << "In Constructor" << endl;
		ifstream infile ("TodoList.txt");
		string line;
		if (infile.is_open()){
			while (getline (infile, line)){
				//cout << line << endl;
				tasks.push_back(line);
			}
			infile.close();
		}
	}
	virtual ~TodoList() {
		//cout << "In Destructor" << endl;
		ofstream outfile;
		outfile.open("TodoList.txt", ofstream::out | ofstream::trunc);
		for (int i = 0; i < tasks.size(); i++){
			//cout << tasks[i] << endl;
			outfile << tasks[i] << endl;
		}
		outfile.close();
	}

	virtual void add(string _duedate, string _task) {
		//cout << "In add" << endl;
		cout << endl << endl;
		tasks.push_back(_duedate);
		tasks.push_back(_task);
	}

	/*
	*   Removes an item from the todo list with the specified task name
	*
	*   Returns 1 if it removes an item, 0 otherwise
	*/
	virtual int remove(string _task){
		//cout << "In remove" << endl;
		cout << endl << endl;
		vector<string>::iterator i;
		i = find(tasks.begin(), tasks.end(), _task);
		if (i != tasks.end()){
			tasks.erase(i);
			tasks.erase(i - 1);
		}
		else
			cout << "That task doesn't exist" << endl;
		// for (int i = 0; i < tasks.size(); i++){
		// 	cout << tasks.at(i) << endl;
		// }
	}

	/*
	*   Prints out the full todo list to the console
	*/
	virtual void printTodoList(){
		//cout << "In list" << endl;
		cout << endl << "Your full agenda: " << endl << endl;
		for (int i = 0; i < tasks.size(); i++){
			cout << tasks.at(i) << endl;
		}
		cout << endl << endl;
	}
	
	/*
	*   Prints out all items of a todo list with a particular due date (specified by _duedate)
	*/
	virtual void printDaysTasks(string _date){
		//cout << "In daystasks" << endl;
		cout << endl << "Your agenda for " << _date << ":" << endl << endl;
		vector<string>::iterator index;
		index = find(tasks.begin(), tasks.end(), _date);
		for (int i = 0; i < tasks.size(); i++){
			if(tasks.at(i) == *index)
				cout << tasks.at(i + 1) << endl;
		}
	}
};

#endif