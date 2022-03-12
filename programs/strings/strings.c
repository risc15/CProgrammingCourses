#include <stdio.h>

int main(void) {

    // There are several ways to initialize a string:
    char c1[] = "This is a string!";
    char c2[50] = "This, also, is a string.";
    char c3[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    char c4[5] = {'a', 'b', 'c', 'd', '\0'};

    // Don't do this:
    // char c[5] = "abcde";
    // There has to be space for the \0 character at the end of a string.

    char name[20];
    char *ptr = name;
    int index = 0;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter an index from 0 to %d: ", (int)sizeof(name));
    scanf("%d", &index);
    *(ptr + index) = 'B';
    printf("Your name is %s\n", name);

    // Now to use fgets() to read a line of a string:
    char name2[30];
    printf("\nEnter another name: ");
    fgets(name2, sizeof(name2), stdin); // read string
    printf("\nName: ");
    puts(name2); // display string
    puts(name);
    for(int i = 0; i < (int)sizeof(name2); i++) {
        printf("Index %d: %c\n",i, name2[i]);
    }

    printf("\nThe number of characters in name2 is: %d", (int)sizeof(name2));

    return 0;

}

