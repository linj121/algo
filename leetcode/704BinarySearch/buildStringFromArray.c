#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int arr[] = {42, -7, 0, 123, INT_MAX, INT_MIN}; // Example int array
    int arr_size = sizeof(arr) / sizeof(arr[0]);     // Number of elements in the array

    // Calculate the maximum required buffer size
    // Each int can take up to 12 characters (for 32-bit int), plus 2 for separators (e.g., ", ")
    int max_int_chars = 12;
    int buffer_size = arr_size * (max_int_chars + 2) + 1; // +1 for null terminator
    char *buffer = malloc(buffer_size);                  // Allocate the buffer
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Build the string
    int offset = 0; // Track the current position in the buffer
    for (int i = 0; i < arr_size; i++) {
        // Append the current integer to the buffer
        int written = snprintf(buffer + offset, buffer_size - offset, "%d", arr[i]);
        if (written < 0 || written >= buffer_size - offset) {
            fprintf(stderr, "Error formatting string\n");
            free(buffer);
            return 1;
        }
        offset += written;

        // Append a separator (e.g., ", ") if not the last element
        if (i < arr_size - 1) {
            written = snprintf(buffer + offset, buffer_size - offset, ", ");
            if (written < 0 || written >= buffer_size - offset) {
                fprintf(stderr, "Error formatting string\n");
                free(buffer);
                return 1;
            }
            offset += written;
        }
    }

    // Print the result
    printf("Resulting string: %s\n", buffer);

    // Free the allocated buffer
    free(buffer);

    return 0;
}

