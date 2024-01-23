#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Task.h"
#include "Display.h"
#include "Disk.h"
/*This Task manager program allows the user to create tasks assign a level of importance, a due date, and completion status. Users will have the ability to display certain tasks, 
update tasks and search for them. They will also be given the option to display the time within the program as well as saving all of the tasks to disk.*/

//Dominic Szymanski and Muskan Nayankumar - PRG71985 - Group Project: Group 37 - 12/26/22

int main(void) {
   TodoList todo_list = { 0 };
    load_tasks(&todo_list);
    struct tm t = currentTime(); //For displayng time 
     welcomeBanner();
    while (1) {
        // show the menu
       
        display_menu();

       // get the user's choice
            int choice = 0;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // execute the user's choice
        switch (choice) {
        case 1:
            add_task(&todo_list);
            break;
        case 2:
            delete_task(&todo_list);
            break;
        case 3:
            update_task(&todo_list);
            break;
        case 4:
            display_task(&todo_list);
            break;
        case 5:
            display_range(&todo_list);
            break;
        case 6:
            display_all(&todo_list);
            break;
        case 7:
            search_tasks(&todo_list);
            break;
        case 8:
            printf("Current Hour: %d Current Minute: %d\n", t.tm_hour, t.tm_min); //displaying current time to user.
            break;
        case 9:
            save_tasks(&todo_list);
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
    free_tasks(&todo_list);
    return 0;
}