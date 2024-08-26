#include "utility.h" // Header's library
#include <stdio.h> // Input & Output's library


// Implementation of the function to clear the input buffer.
// This is useful to avoid issues with unwanted input remaining in the buffer.
void clearInputBuffer() { // No values returned tho you use a void function to call

    while (getchar() != '\n');  // Consume characters until newline

}