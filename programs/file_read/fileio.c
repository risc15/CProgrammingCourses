#include <stdio.h>
#include <stdlib.h>

char* read(char* file) {
    FILE *filePointer = fopen(file, "r");
    char *buffer = malloc(255);

    fgets(buffer, 255, (FILE*) filePointer);
    fclose(filePointer);
    return buffer;
}

int main() {
    printf("reading file: \n");
    printf("%s\n", read("sup.txt"));
    return 0;
}
