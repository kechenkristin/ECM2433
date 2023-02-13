#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	argv++;

	int count = atoi(*argv);
	if (count <= 0) return 0;
	short int *ptr = (short int*)malloc(count * sizeof(short int));

	int i;
	for (i = 0; i < count; i++) {
		ptr[i] = i + 1;
		printf("%d\n", ptr[i]);
	}

	/* oops! forgot to free p */
	/* free(ptr); */
	return 0;
}
