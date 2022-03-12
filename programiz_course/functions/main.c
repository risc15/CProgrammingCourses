#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long processInput(int x, int y, int z) {
    int a = x + y;
    int b = a * z;
    int c = b + x + y + z;
    return c;
}

int main(void) {
    printf("Let's play a game that will take far too long to actually complete.\n");

    long guess = 0;
    int tries = 0;

    // Seed the random number with srand and give it the current time:
    srand(time(0));

    int secretNumber = abs(processInput(processInput(rand(),rand(),rand()),rand(),rand()));

    // Now guess the number:
    while(guess != secretNumber) {
        printf("You have guessed %d time(s). Enter a number: ", tries);
        scanf("%d", &secretNumber);

        if(guess < secretNumber) {
            printf("Number is higher.\n");
            tries++;
        } else if(guess > secretNumber) {
            printf("Number is lower.\n");
            tries++;
        } else {
            printf("Correct! The number was %d.\n", secretNumber);
        }
    }
    return 0;
}
