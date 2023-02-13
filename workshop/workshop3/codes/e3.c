#include <stdio.h>

int printInteger(int);

int* updateInteger(int*);

int main() {

	/* e31 */
	int x = 42;
	int y = 0;
	printf("in main function x = %d, y = %d\n",x,y);
	y = printInteger(x);
	printf("in main function x = %d, y = %d\n",x,y);

	/* e32 */
	int z = 42;
	printf("in main function z = %d\n",z);
	updateInteger(&z);
	printf("in main function z = %d\n",z);
}

int printInteger(int val) {
	return val + 3;
}

int* updateInteger(int* val) {
	*val += 3;
	return val;
}
