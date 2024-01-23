#define _CRT_SECURE_NO_WARNINGS
#include "Display.h"
#include "Task.h"
#include "Disk.h"
/*This Task manager program allows the user to create tasks assign a level of importance, a due date, and completion status. Users will have the ability to display certain tasks,
update tasks and search for them. They will also be given the option to display the time within the program as well as saving all of the tasks to disk.*/

//Dominic Szymanski and Muskan Nayankumar - PRG71985 - Group Project: Group 37 - 12/26/22

void display_menu(void) {
    
    printf("\n=== To-Do List Manager ===\n");
    printf("1. Add a new task\n");
    printf("2. Delete a task\n");
    printf("3. Update a task\n");
    printf("4. Display a single task\n");              //function to print options to user.
    printf("5. Display a range of tasks\n");
    printf("6. Display all tasks\n");
    printf("7. Search for tasks\n");
    printf("8. Display Current Time\n");
    printf("9. Exit\n");
    printf("=========================\n");
}

void welcomeBanner(void) 
{
    printf("\n\n************************************************\n");
    printf("*                                              *\n");
    printf("*            Task/To-Do List Manager           *\n");                     //function to print welcome banner
    printf("*                                              *\n");
    printf("************************************************\n\n\n");

    
}