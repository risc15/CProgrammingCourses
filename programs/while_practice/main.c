#include <stdio.h>

int main()
{
	int x = 0;
	int y = 0;
	while (x < 5) {
		if (y < 5) {
			x++;
			if (y < 3) {
				x--;
			}
		}
		y = y + 2;
		printf("%i%i ", x, y);
		x++;
	}
	printf("\n");
	return 0;
}
