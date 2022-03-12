/*
 * Dynamic Memory Allocation - malloc, free, and buffer overflows
 */

#include <stdio.h>
// Include stdlib to have access to malloc and free:
#include <stdlib.h>

int main(void) {
    printf("== Malloc example 1 ==\n");

    printf("Request memory\n");
    // 1K of memory:
    void *ptr = malloc(1024);

    printf("Free memory\n");
    free(ptr);
}
