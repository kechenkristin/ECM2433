#include <stdio.h>

int main() {
	int x = 4;
	printf("The value of x is: %d\n", x);
	printf("The memory address of x is: %p\n", &x);

	/* Define xPtr as a pointer to x */
	int* xPtr = &x;
	*xPtr = 6;

	printf("The value of x is: %d\n", *xPtr);

	printf("The memory address of x is: %p\n", xPtr);
}
