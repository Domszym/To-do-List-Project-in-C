#pragma once
#include "Task.h"
/*This Task manager program allows the user to create tasks assign a level of importance, a due date, and completion status. Users will have the ability to display certain tasks,
update tasks and search for them. They will also be given the option to display the time within the program as well as saving all of the tasks to disk.*/

//Dominic Szymanski and Muskan Nayankumar - PRG71985 - Group Project: Group 37 - 12/26/22

void save_tasks(TodoList* todo_list);
void load_tasks(TodoList* todo_list);
