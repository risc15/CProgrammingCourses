#include <stdio.h>

int main() {
	// Print F
	for(int i = 0; i < 7; i++) {
		for(int j = 0; j < 7; j++) {
			if(i == 0) {
				printf("#");
			} else if(i == 3 && j != 5) {
				printf("#");
			} else if(j < 1) {
				printf("#");
			}
		}
		printf("\n");
	}

	printf("\n");

	// Print C
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 12; j++) {
			if((i == 0 || i == 8) && (j > 3 && j < 10)) {
				printf("#");
			} else if(((i == 1 || i == 7)) && ((j > 1 && j < 4) || (j > 9))) {
				printf("#");
			} else if((j == 1) && (i > 1 && i < 7)) {
				printf("#");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
