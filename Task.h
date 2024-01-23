#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 100
#define MAX_LENGTH 100
/*This Task manager program allows the user to create tasks assign a level of importance, a due date, and completion status. Users will have the ability to display certain tasks,
update tasks and search for them. They will also be given the option to display the time within the program as well as saving all of the tasks to disk.*/
//Dominic Szymanski and Muskan Nayankumar - PRG71985 - Group Project: Group 37 - 12/26/22

// define a struct to represent a task
typedef struct Task {
	char name[MAX_LENGTH];
	char time[MAX_LENGTH];
	int impo;
} Task;

// define a struct to represent the to-do list
typedef struct TodoList {
	Task tasks[MAX_TASKS];
	int num_tasks;
} TodoList;



// Function prototypes
Task* create_task();
void add_task(TodoList* todo_list);
void delete_task(TodoList* todo_list);
void update_task(TodoList* todo_list);
void display_task(TodoList* todo_list);
void display_range(TodoList* todo_list);
void display_all(TodoList* todo_list);
void search_tasks(TodoList* todo_list);
void free_tasks(TodoList* todo_list);
struct tm currentTime();
