#define _CRT_SECURE_NO_WARNINGS
#include "Disk.h"
#include <stdio.h>
#define MAX_STR    250
/*This Task manager program allows the user to create tasks assign a level of importance, a due date, and completion status. Users will have the ability to display certain tasks,
update tasks and search for them. They will also be given the option to display the time within the program as well as saving all of the tasks to disk.*/

//Dominic Szymanski and Muskan Nayankumar - PRG71985 - Group Project: Group 37 - 12/26/22

// save the to-do list to a file
void save_tasks(TodoList* todo_list) {
    if (todo_list->num_tasks == 0) {
        printf("Error: To-do list is empty.\n");
        return;
    }

    char filename[] = "tasks.txt";

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    // write the number of tasks to the file
    fprintf(file, "%d\n", todo_list->num_tasks);

    // write each task to the file
    for (int i = 0; i < todo_list->num_tasks; i++) {
        fprintf(file, "%s\n", todo_list->tasks[i].name);
        fprintf(file, "%s\n", todo_list->tasks[i].time);
        fprintf(file, "%d\n", todo_list->tasks[i].impo);
    }

    fclose(file);

    printf("Tasks saved successfully.\n");
}

// load tasks from a file
void load_tasks(TodoList* todo_list) {
    char filename[] = "tasks.txt";

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    // read the number of tasks from the file
    int num_tasks = 0;
    fscanf(file, "%d\n", &num_tasks);

    if (num_tasks > MAX_TASKS) {
        printf("Error: Too many tasks in file.\n");
        return;
    }

    // read each task from the file
    for (int i = 0; i < num_tasks; i++) {
        fgets(todo_list->tasks[i].name, MAX_LENGTH, file);
        todo_list->tasks[i].name[strlen(todo_list->tasks[i].name) - 1] = '\0';

        fgets(todo_list->tasks[i].time, MAX_LENGTH, file);
        todo_list->tasks[i].time[strlen(todo_list->tasks[i].time) - 1] = '\0';

        fscanf(file, "%d\n", &todo_list->tasks[i].impo);
    }

    todo_list->num_tasks = num_tasks;

    fclose(file);

    
}