#define _CRT_SECURE_NO_WARNINGS
#include "Task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*This Task manager program allows the user to create tasks assign a level of importance, and a due date,. Users will have the ability to display certain tasks,
update tasks and search for them. They will also be given the option to display the time within the program as well as saving all of the tasks to disk.*/

//Dominic Szymanski and and Muskan Nayankumar - PRG71985 - Group Project: Group 37 - 12/26/22

Task* create_task() {
    Task* task = malloc(sizeof(Task));
    if (task == NULL) {
        printf("Error: Failed to allocate memory for new task.\n");              //memory allocation when new task is created
        return NULL;
    }
    return task;
}


// add a new task to the to-do list
void add_task(TodoList* todo_list) {
    // check if the to-do list is full
    if (todo_list->num_tasks >= MAX_TASKS) {
        printf("Error: To-do list is full.\n");
        return;
    }

    // create a new task
    Task* task = create_task();
    if (task == NULL) {
        // return if the task creation failed
        return;
    }

    // get task details from the user
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter the name of the task: ");
    fgets(task->name, MAX_LENGTH, stdin);
    task->name[strlen(task->name) - 1] = '\0';

    printf("Enter the time the task is due at: ");
    fgets(task->time, MAX_LENGTH, stdin);
    task->time[strlen(task->time) - 1] = '\0';

    printf("Enter the importance of the task (1-3)(1 Being Most Important): ");
    scanf("%d", &task->impo);

    // add the task to the to-do list
    todo_list->tasks[todo_list->num_tasks] = *task;
    todo_list->num_tasks++;

    printf("Task added successfully.\n");
}

// delete a task from the to-do list
void delete_task(TodoList* todo_list) {
    if (todo_list->num_tasks == 0) {
        printf("Error: To-do list is empty.\n");
        return;
    }
   
    int index = 0;
    printf("Enter the index of the task to delete(First Task at 0):");
    scanf("%d", &index);

    if (index < 0 || index >= todo_list->num_tasks) {
        printf("Error: Invalid index.\n");
        return;
    }

    // shift all tasks after the deleted task one position to the left
    for (int i = index; i < todo_list->num_tasks - 1; i++) {
        todo_list->tasks[i] = todo_list->tasks[i + 1];
    }

    // decrease the number of tasks
    todo_list->num_tasks--;
  
    printf("Task deleted successfully.\n");
}


// update an existing task
void update_task(TodoList* todo_list) {
    if (todo_list->num_tasks == 0) {
        printf("Error: To-do list is empty.\n");
        return;
    }

    // create a new task
    Task* task = create_task();
    if (task == NULL) {
        // return if the task creation failed
        return;
    }

    int index = 0;
    printf("Enter the index of the task to update (First Task at 0): ");
    scanf("%d", &index);

    if (index < 0 || index >= todo_list->num_tasks) {
        printf("Error: Invalid index.\n");
        return;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);    //swallow newline
    printf("Enter the new name of the task: ");
    fgets(todo_list->tasks[index].name, MAX_LENGTH, stdin);                                    
    todo_list->tasks[index].name[strlen(todo_list->tasks[index].name) - 1] = '\0';

    printf("Enter the new time the task is due at : ");
    fgets(todo_list->tasks[index].time, MAX_LENGTH, stdin);
    todo_list->tasks[index].time[strlen(todo_list->tasks[index].time) - 1] = '\0';               //getting info from user 

    printf("Enter the new importance of the task (1-3)(1 Being Most Important): ");
    scanf("%d", &todo_list->tasks[index].impo);

    printf("Task updated successfully.\n");

    // free the memory allocated by create_task()
    free(task);
}
    
// display a single task
void display_task(TodoList* todo_list) {
    if (todo_list->num_tasks == 0) {
        printf("Error: To-do list is empty.\n");
        return;
    }

    int index = 0;
    printf("Enter the index of the task to display (First Task at 0): ");
    scanf("%d", &index);

    if (index < 0 || index >= todo_list->num_tasks) {
        printf("Error: Invalid index.\n");                         //checking for appropaite index input
        return;
    }

    printf("\nTask: %s\n", todo_list->tasks[index].name);
    printf("Time: %s\n", todo_list->tasks[index].time);           //and pringting single task
    printf("Importance: %d\n", todo_list->tasks[index].impo);
}

// display a range of tasks
void display_range(TodoList* todo_list) {
    if (todo_list->num_tasks == 0) {
        printf("Error: To-do list is empty.\n");
        return;
    }

    int start = 0, end = 0;
    printf("Enter the start and end indices of the tasks to display (First Task at 0): ");
    scanf("%d %d", &start, &end); //getting start and end on range

    if (start < 0 || start >= todo_list->num_tasks || end < 0 || end >= todo_list->num_tasks || start > end) {          // checking for valid input 
        printf("Error: Invalid indices.\n");
        return;
    }

    for (int i = start; i <= end; i++) {
        printf("\nTask: %s\n", todo_list->tasks[i].name);
        printf("Time: %s\n", todo_list->tasks[i].time);          //display range of tasks
        printf("Importance: %d\n", todo_list->tasks[i].impo);
    }
}

// display all tasks
void display_all(TodoList* todo_list) {
    if (todo_list->num_tasks == 0) {
        printf("Error: To-do list is empty.\n");
        return;
    }

    for (int i = 0; i < todo_list->num_tasks; i++) {                                  //displaying all tasks by iterating through loop
        printf("\nTask: %s\n", todo_list->tasks[i].name);
        printf("Time: %s\n", todo_list->tasks[i].time);
        printf("Importance: %d\n", todo_list->tasks[i].impo);
    }
}

void search_tasks(TodoList* todo_list) {
    if (todo_list->num_tasks == 0) {
        printf("Error: To-do list is empty.\n");
        return;
    }

    int choice = 0;
    printf("1. Search by name\n");
    printf("2. Search by time\n");
    printf("3. Search by importance\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    char query[MAX_LENGTH] = { 0 };
    int result_count = 0;
    switch (choice) {
    case 1:
        printf("Enter the name to search for: ");
        fgets(query, MAX_LENGTH, stdin);
        query[strlen(query) - 1] = '\0';
        printf("Searching for tasks with name '%s'...\n", query);
        for (int i = 0; i < todo_list->num_tasks; i++) {
            if (strstr(todo_list->tasks[i].name, query) != NULL) {
                // Create a new task and copy the task data from the to-do list
                Task* task = create_task();
                if (task == NULL) {
                    printf("Error: Failed to allocate memory for new task.\n");
                    return;
                }
                strcpy(task->name, todo_list->tasks[i].name);
                strcpy(task->time, todo_list->tasks[i].time);
                task->impo = todo_list->tasks[i].impo;

                printf("\nTask: %s\n", task->name);
                printf("Time: %s\n", task->time);
                printf("Importance: %d\n", task->impo);
                result_count++;
            }
        }
        break;
    case 2:
        printf("Enter the time to search for: ");
        fgets(query, MAX_LENGTH, stdin);
        query[strlen(query) - 1] = '\0';
        printf("Searching for tasks with time '%s'...\n", query);
        for (int i = 0; i < todo_list->num_tasks; i++) {
            if (strstr(todo_list->tasks[i].time, query) != NULL) {
                // Create a new task and copy the task data from the to-do list
                Task* task = create_task();
                if (task == NULL) {
                    printf("Error: Failed to allocate memory for new task.\n");
                    return;
                }
                strcpy(task->name, todo_list->tasks[i].name);
                strcpy(task->time, todo_list->tasks[i].time);
                task->impo = todo_list->tasks[i].impo;

                    printf("\nTask: %s\n", task->name);
                printf("Time: %s\n", task->time);
                printf("Importance: %d\n", task->impo);
                result_count++;
            }
        }
        break;
    case 3:
        printf("Enter the importance to search for: ");
        scanf("%d", &choice);
        printf("Searching for tasks with importance '%d'...\n", choice);
        for (int i = 0; i < todo_list->num_tasks; i++) {
            if (todo_list->tasks[i].impo == choice) {
                // Create a new task and copy the task data from the to-do list
                Task* task = create_task();
                if (task == NULL) {
                    printf("Error: Failed to allocate memory for new task.\n");
                    return;
                }
                strcpy(task->name, todo_list->tasks[i].name);
                strcpy(task->time, todo_list->tasks[i].time);
                task->impo = todo_list->tasks[i].impo;

                printf("\nTask: %s\n", task->name);
                printf("Time: %s\n", task->time);
                printf("Importance: %d\n", task->impo);
                result_count++;
            }
        }
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        return;
    }

    if (result_count == 0) {
        printf("No tasks found.\n");
    }
    else {
        printf("%d task(s) found.\n", result_count);
    }
}

void free_tasks(TodoList* todo_list) {
    for (int i = 0; i < todo_list->num_tasks; i++) {
        free(&todo_list->tasks[i]);                      //I believe is wrong but did not know how to approach any other way.
    }
}

struct tm currentTime() {
    time_t timer = time(NULL);            //This is a function to display the time
    struct tm time = *localtime(&timer);
    return time;
}
