/*
 * Example 2 of Memory Allocation
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("== Malloc example 2 ==\n");

    printf("Request memory\n");
    
    char *ptr = (char *) malloc(1024);

    // malloc can fail in systems with low memory, let's check if it was a
    // success:
    if (ptr != NULL) {
        ptr[0] = 'A';
        ptr[1] = 0;
        printf("buffer: %s\n", ptr);

        printf("Free memory\n");
        free(ptr);
    }
}
