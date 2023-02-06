#include <stdio.h>


int main(int argc, char **argv) {
	/* Write and test a program to print its command line arguments. */

	char **p;
	int i;

	for (p = argv, i = 0; i < argc; i++, p++) {
		printf("%s\n", *p);
	}

	return 0;
}
