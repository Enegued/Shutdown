#include "log.h" // Header's library
#include <stdio.h> // Input & Output's library
#include <time.h> // Time's library

void logActivityWriter(const char *action) { // No values returned tho you use a void function to call

    FILE *logFile = fopen("shutdown_log.txt", "a"); // Open file in append mode

    if (logFile == NULL) { // Condition if the log file cannot be opened

        printf("Unable to open the log file.\n"); // Error returned if the log file cannot be opened
        
        return; // End of condition

    }

    // Get the current time
    time_t now;
    time(&now);

    fprintf(logFile, "Action: %s, Scheduled at: %s", action, ctime(&now)); // Write the action and the time it was scheduled to the log file
    
    fclose(logFile); // Close the file after writing

}