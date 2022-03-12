#include <stdio.h>

void swap(int *n1, int *n2);
void addOne(int *ptr);

int main() {
    int num1 = 5, num2 = 10;
    
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    
    // Address of num1 and num2 is passed
    swap( &num1, &num2 );

    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    int *p;
    int i = 10;
    p = &i;
    addOne(p);
    p = &num2;
    addOne(p);

    return 0;
}

/*
 *  User Defined Functions
 */

// Demonstrate passing addresses as arguments.
void swap(int *n1, int *n2) {
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

// Demonstrate passing a pointer as an argument.
void addOne(int *ptr) {
    printf("Adding 1 to address %p\n", ptr);
    (*ptr)++;   // Adding 1 to ptr.
    printf("%p now contains: %d\n", ptr, *ptr);
}
