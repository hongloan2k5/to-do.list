#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "to-do.h"

void viewTask() {
    
    // DECLARING_VARIABLE
    FILE *file = fopen(FILE_PATH, "r");
    
    char *opening = 
    "IIIIIIII IIIIIIII      IIIIIIII IIIIIIII   IIII   IIII IIIIII IIIIII    \n"
    "   II    III  III      II  IIII III  III   IIII   IIII III      II      \n"
    "   II    III  III IIII II   III III  III   IIII   IIII  III     II      \n"
    "   II    III  III      II  IIII III  III   IIIIII IIII    III   II      \n"
    "   II    IIIIIIII      IIIIIIII IIIIIIII   IIIIII IIII IIIIII   II      \n";
    
    char task[MAX_LENGTH];
    // VARIABLE_DECLARED

    
    printf("%s", opening);
    printf("\n============================== TASKS ==============================\n");


    // PRINTING_OUT-LIST
    int number = 0;
    while(fgets(task, MAX_LENGTH, file) != NULL)
    {
        printf("%d. %s", ++number, task); 
    }
    if(number == 0)
    {
        printf("\t\t\tNo tasks available.");
    }
    // LIST-PRINTED


    printf("\nCommands:\n");
    printf("[a] - Add task\n");
    printf("[e] - Edit task\n");
    printf("[d] - Delete task\n");
    printf("[q] - Quit\n");
    printf("Command: ");


    fclose(file);
}

void addTask() {
    
    // DECLARING_VARIABLE
    char task[MAX_LENGTH];
    FILE *file = fopen(FILE_PATH, "a");
    // VARIABlE_DECLARED


    // USER_INPUT
    printf("Enter task description: ");
    scanf(" %[^\n]", task); // taking the whole line of input except '\n'
    getchar(); // clear input buffer '\n'
    // USER_INPUTED
    
    
    // CHECKING_EMPTY-TASK
    if (strlen(task) == 0) {
        fclose(file);
        return; // exit the function before writing to file
    }
    // EMPTY-TASK_CHECKED
    

    fprintf(file, "%s\n", task);
    
    fclose(file);
}

void editTask() {
    
    // DECLARING_VARIABLE
    int taskNumber;
    int currentTaskNumber = 1;
    char task[MAX_LENGTH];
    FILE *file = fopen(FILE_PATH, "r");
    FILE *tempFile = fopen(TEMP_PATH, "w");
    // VARIABLE_DECLARED

    
    printf("Enter the number of the task to edit: ");
    
    
    // CHECKING_NUMERICAL-INPUT 
    while (1) {
        if (scanf("%d", &taskNumber) != 1 || taskNumber <= 0) {
            printf("Invalid input. Please enter a valid task number: ");
            // Clear input buffer
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    // NUMERICAL-INPUT CHECKED

    getchar(); // clear input buffer '\n'


    int found = 0; // Flag to indicate if task number is found
    while(fgets(task, MAX_LENGTH, file) != NULL){
        if(currentTaskNumber == taskNumber){ // replacing current task with new task
            printf("Enter the new task description: ");
            scanf("%[^\n]", task);
            getchar(); // clear input buffer '\n'
            fprintf(tempFile, "%s\n", task);
            found = 1; // task number exist
        } else {
            fprintf(tempFile, "%s", task);
        }
        currentTaskNumber++;
    }
    if (!found) {
        printf("Task number %d does not exist.", taskNumber); 
        while(getchar() != '\n');
    }

    
    fclose(file);
    fclose(tempFile);
    remove(FILE_PATH);
    rename(TEMP_PATH, FILE_PATH);
}

void deleteTask() {
   
    // DECLARING_VARIABLE
    int taskNumber;
    int currentTaskNumber = 1;
    char task[MAX_LENGTH];
    FILE *file = fopen(FILE_PATH, "r");
    FILE *tempFile = fopen(TEMP_PATH, "w");
    // VARIABLE_DECLARED

    printf("Enter the number of the task to delete: ");

    // CHECKING_NUMERICAL-INPUT
    while (1) {
        if (scanf("%d", &taskNumber) != 1 || taskNumber <= 0) {
            printf("Invalid input. Please enter a valid task number: ");
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    // NUMERICAL-INPUT_CHECKED

    getchar(); // clear input buffer '\n'

    int found = 0; // Flag to indicate if task number is found
    while (fgets(task, MAX_LENGTH, file) != NULL) {
        if (currentTaskNumber != taskNumber) {
            fprintf(tempFile, "%s", task);
        } else {
            found = 1; // task number exist
        }
        currentTaskNumber++;
    }

    if (!found) {
        printf("Task number %d does not exist.", taskNumber); 
        while(getchar() != '\n');
    }


    fclose(file);
    fclose(tempFile);
    remove(FILE_PATH);
    rename(TEMP_PATH, FILE_PATH);
}

void execute(){
    while (1) {
        system("clear");
        viewTask();

        char choice; // USER_INPUT DECLARED
        char inputBuffer[MAX_LENGTH];
        
        // Read the input as a string
        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) {
            // Handle EOF (Ctrl+D)
            printf("\nExiting...\n");
            break;
        }


        // Check if input is longer than one character (excluding newline)
        if (strlen(inputBuffer) > 2 || (strlen(inputBuffer) == 2 && inputBuffer[1] != '\n')) {
            printf("Invalid command. Please enter a single character command.\n");
            printf("Press ENTER to continue...");
            while(getchar() != '\n');
            continue; // Restart the loop to prompt for input again
        }

        // Extract the first character from the input
        choice = inputBuffer[0];

        switch (choice) {
            case 'a':
                addTask();
                break;
            case 'e':
                editTask();
                break;
            case 'd':
                deleteTask();
                break;
            case 'q':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid character. Please enter the appropriate character command.\n");
                printf("Press ENTER to continue...");
                while(getchar() != '\n');
        }
    }
}
