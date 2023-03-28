#include <stdio.h>

int main() {
	unsigned short int x = 1;
	short int y = 65535;
	// short int y = 65540;
	y = y + 5;
	unsigned char c = 'A';

	// d
	x = -1;
	c = 66;

	printf("x has the value %d \n", x);
	printf("y has the value %d \n", y);
	printf("c has the value %c \n", c);
	
	return 0;
}
