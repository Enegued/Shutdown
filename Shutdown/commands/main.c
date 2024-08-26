#include <stdio.h> // Input & Output's library
#include <stdlib.h> // Libs Standards's library
#include <windows.h> // For Sleep function library
#include <ctype.h> // For tolower function library
#include <conio.h> // For non-blocking keyboard input (_kbhit() & _getch()) functions library

#include "utility.h" // Header's library
#include "log.h" // Header's library
#include "shutdown.h" // Header's library


// Main function that executes and makes action for the others files
int main() { 

    int i, time, ms, cancel = 0; // Int declarations
    char unit, choice, Description[25]; // Char declarations

    // Display menu for selecting the actions wanted (shutdown, restart or hibernate)
    printf("Choose the action:\n");
    printf("1. Shutdown.\n");
    printf("2. Restart.\n");
    printf("3. Hibernate.\n");
    printf("Enter your choice (1-3): ");

    choice = getchar(); // Fetching the character typed
    clearInputBuffer(); // Clears the input buffer

    // Validate the user's choice
    if (choice < '1' || choice > '3') {

        printf("Invalid choice.\n");
        
        return 1;

    }

    // Prompt user to enter the time after which the action should occur
    printf("Enter the time after which the action should occur: ");
    scanf("%d", &time); // Fetch the decimal time typed
    clearInputBuffer(); // Clears the input buffer

    // Checking if time typed is positive
    if (time <= 0) {

        printf("Please enter a positive number.\n");
        
        return 1;
    }

    // Ask the user to specify the time unit (secs, mins or hours)
    printf("Is this time in (s)econds, (m)inutes, or (h)ours ? ");

    unit = getchar(); // Assign the character fetched to unit
    unit = tolower(unit); // Decapitalise the character if needed and assignating it to unit

    // Convert the entered time to ms based on the specified unit
    switch (unit) {

        case 's':
            ms = time * 1000;
            break;
        
        case 'm':
            ms = time * 60 * 1000;
            break;

        case 'h':
            ms = time * 60 * 60 * 1000;
            break;

        default:
            printf("Invalid time unit, please enter 's', 'm' or 'h'.\n");
            
            return 1;

    }

    // Determine the action description based on the user's action choice
    switch(choice) {

        case '1':
            strcpy(Description, "Shutdown");
            break;

        case '2':
            strcpy(Description, "Restart");
            break;

        case '3':
            strcpy(Description, "Hibernate");
            break;

    }

    logActivityWriter(Description); // Log the scheduled action

    // Start the countdown with an option to cancel if needed by the user
    printf("Your computer will %s in %d %c. Press 'c' to cancel this action.\n", Description, time, unit);

    for (i = ms/1000; i > 0; i--) {

        printf("Time remaining before %s: %d seconds\r", Description, i);
        fflush(stdout);

        Sleep(1000);

        // Check if the user pressed 'c' to cancel
        if (_kbhit() && _getch() == 'c') {

            cancelShutdownFunc();
            cancel = 1;
            break;

        }
    }

    // Execute the action (shutdown, restart or hibernate) if not canceled
    if (!cancel) {

        executeShutdownFunc(choice - '0');

    }

    return 0;

}