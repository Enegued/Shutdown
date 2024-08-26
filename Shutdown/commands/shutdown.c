#include "shutdown.h" // Header's library
#include "log.h" // Header's library
#include <stdlib.h> // Libs standards' library
#include <stdio.h> // Input & Output's library


// Executes the system command for shutdown, restart, or hibernate based on the user's choice.
// The choice is passed as an integer (1 = shutdown, 2 = restart, 3 = hibernate).
void executeShutdownFunc(int choice) { 

    switch(choice) { 

        case 1:

            system("shutdown /s /f /t 0"); // Shutdown immediately the computer.
            logActivityWriter("Shutdown command executed successfully.");
            break;

        case 2:

            system("shutdown /r /f /t 0"); // Restart immediately the computer.
            logActivityWriter("Restart command executed successfully.");
            break;

        case 3:

            system("shutdown /h"); // Hibernate the computer.
            logActivityWriter("Hibernated command executed successfully.");
            break;

    }
}


// Cancels the scheduled shutdown by invoking the appropriate system command.
// Also logs the cancellation to the log file.
void cancelShutdownFunc() {

    system("shutdown /a"); // Abort the scheduled shutdown
    printf("\nShutdown canceled.\n");
    logActivityWriter("Shutdown canceled."); // Log the cancellation

}