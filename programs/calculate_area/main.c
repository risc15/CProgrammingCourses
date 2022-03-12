#include <stdio.h>

int calculateSquarePerimeter(int x, int y) {
	return (x * 2) + (y * 2);
}

int calculateSquareArea(int x, int y) {
	return x * y;
}

float calculateCircumference(float radius) {
	return (radius * 2) * 3.14159265359;
}

float calculateCircleArea(float radius) {
	return (radius * radius) * 3.14159265359;
}

int main() {
	int height = 7;
	int width = 5;
	float radius = 25.0f;

	printf("Perimeter of the rectangle = %d\n",
			calculateSquarePerimeter(height, width));
	printf("Area of the rectangle = %d\n",
			calculateSquareArea(height, width));
	printf("Perimeter of the circle = %f\n",
			calculateCircumference(radius));
	printf("Area of the circle = %f\n",
			calculateCircleArea(radius));
}
