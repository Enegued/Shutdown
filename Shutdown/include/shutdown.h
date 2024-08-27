#ifndef SHUTDOWN_H // If SHUTDOWN_H not defined,
#define SHUTDOWN_H // define it to prevent further inclusion

void cancelShutdown(); // Executes the shutdown, restart, or hibernate command based on user choice.
void executeShutdown(int choice); // Cancels the scheduled shutdown, if any, and logs the cancellation.

#endif // End of conditional inclusion