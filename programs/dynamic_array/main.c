#include <stdlib.h>
#include <stdio.h>

typedef struct dyn_array {
    int size;
    int data[];
} dynarray;

int main(){
    dynarray *myArray = 
        malloc(sizeof *myArray + 50 * sizeof *myArray->data);
    
    myArray->data[10] = 100;

    size_t n = sizeof(*myArray->data) / sizeof(myArray->data[0]);
    size_t o = sizeof(*myArray->data);
    printf("The number of elements in the array is %i\n", n);
    printf("The size of the array in bytes is: %i\n", o);
    printf("%i\n", myArray->data[10]);
    printf("\n\n");

    n = sizeof(*myArray->data) / sizeof(myArray->data[0]);
    o = sizeof(*myArray->data);
    printf("The number of elements in the array is %i\n", n);
    printf("The size of the array in bytes is: %i\n", o);
}
