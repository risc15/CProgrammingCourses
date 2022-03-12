#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: \n");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));

    // If memory cannot be allocated:
    if(ptr == NULL) {
        printf("Error! Memory not allocated.\n");
        exit(1);
    }

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d\n\n", sum);
    
    for(int i = 0; i < n; i++) {
        printf("%p contains: %d\n", ptr + i, *(ptr + i));
    }

    printf("\nTo recap: use *var to access the value like this: %d\n", *ptr);
    printf("Use &var to access the address of the variable: %p\n", &ptr);
    printf("To assign a variable as a pointer, use: (type) *ptr \n");
    
    
    printf("To access the contents at a pointer plus an index, use *(ptr + index)\n");
    printf("You can pass pointers as arguments to functions! Use type functionName (int *ptr)\n");
    printf("malloc() reserves a block of memory of the specified number of\nbytes. And, it returns a pointer of void which can be cast into\npointers of any form.\n");
    printf("calloc() allocates memory and initializes all bits to 0.\n");
    printf("free() frees up the reserved space malloc or calloc created.\n");
    printf("realloc() re-allocates the memory given by malloc or calloc.\n\n");

    printf("Addresses of current array:\n");
    for(int i = 0; i < n; i++) {
        printf("%p\n", ptr + i);
    }

    printf("\nEnter the new size of the array:\n");
    scanf("%d", &n);
    
    // Reallocating memory:
    ptr = realloc(ptr, n * sizeof(int));

    printf("\nAddresses of newly allocated memory:\n");
    for(int i = 0; i < n; i++) {
        printf("%p\n", ptr + i);
    }

    free(ptr);

    return 0;
}
