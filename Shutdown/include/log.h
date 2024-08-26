#ifndef LOG_H // If LOG_H not defined,
#define LOG_H // define it to prevent further inclusion

void logActivityWriter(const char *action); // Logs the given action (e.g., shutdown, restart) to a file with a timestamp.

#endif // End of conditional inclusion