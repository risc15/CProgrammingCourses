#include <stdio.h>

int main() {

    // Demonstrate the use of address. To get the address of a variable, 
    // prepend an ampersand (&) to the variable:
    int var = 5;
    printf("var: %d\n", var);
    printf("address of var: %p\n", &var);

    // Create a pointer pc and a normal variable c. Add an asterisk (*) to the
    // variable:
    int* pc, c;
    // int *pc is also valid.

    c = 5;
    pc = &c;
    printf("c is equal to: %d\n", c);
    printf("address of c: %p\n", &c);

    int* pointer;
    int variable;

    pointer = &variable;
    variable = 1337;

    printf("\nThe following will be in hexadecimal:\n");
    printf("=====================================\n\n");
    printf("The address stored in pointer is: %x\n", pointer);
    printf("The address of the pointer itself is: %x\n", &pointer);
    printf("The value at the pointer is: %x\n\n", *pointer);

    // =======================================================================

    int x[4];
    
    for (int i = 0; i < 4; i++) {
        printf("&x[%d] = %p\n", i, &x[i]);
    }

    printf("Address of array x: %p\n\n", x);

    // =======================================================================

    /*
    int y[6], sum = 0;
    printf("Enter 6 numbers: \n");
    for (int i = 0; i < 6; i++) {
        // Equivalent to scanf("%d", &x[i])
        scanf("%d", x+i);

        // Equivalent to sum += x[i]
        sum += *(x+i);
    }
    
    printf("Sum = %d\n", sum);
    
    */

    printf("Enter array size: ");
    int size = 0;
    scanf("%d", &size);
    int myArray[size];
    pointer = &myArray[0];
    printf("Array created of size: %d\n======================\n", size);

    _Bool running = 1;
    int index = 0;
    int value = 0;
    int operation = 0;

    while(running) {

        for (int i = 0; i < size; i++) {
            printf("Array at address %p contains %p (%d).\n", 
                    &pointer + i, 
                    *(pointer+i),
                    *(pointer+i));
        }
        
        printf("\nIndex is: %d\n", index);
        printf("Pointer set to array address at: %p\n", &pointer);
        printf("The pointer resides at address: %p\n", pointer);
        printf("Last operation was %d\n", operation);

        printf("\nEnter operation:\n");
        printf("0 = Clear Array\n1 = Fill Array\n2 = Insert Into Array\n");
        scanf("%d", &operation);

        switch (operation) {
            case 0:
                
                for (int i = 0; i < size; i++) {
                    *(pointer + i) = 0;
                }
                
                break;
            case 1:
                printf("Enter value:\n");
                scanf("%d", &value);

                for (int i = 0; i < size; i++) {
                    *(pointer + i) = value;
                }
                
                break;
            case 2:
                printf("Enter index (number only) to change value: \n");
                scanf("%d", &index);
                
                if (index < size && index >= 0) {
                    printf("Enter value: \n");
                    scanf("%d", &value);
                    *(pointer + index) = value;
                } else {
                    printf("Error.\n");
                }
                
                break;
            default:
                running = 0;
        }
        
    }

    return 0;
}
