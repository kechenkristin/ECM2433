#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringConcat.c"

int main(int argc, char **argv) {
	argv++;

	int count = atoi(*argv);

	int wordsLen = argc - 2;

	if (count <= 0) return 0;

	argv++;
	char* str = concatenate(wordsLen, argv, " ");

	int i;
	for (i = 0; i < count; i++) {
		printf("%s\n", str);
	}

	return 0;
}
