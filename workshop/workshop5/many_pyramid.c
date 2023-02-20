#include "pyramid.h"

#include <stdio.h>

int get_height() {
	int height;
	printf("How high would you like the pyramid?: \n");
	scanf("%d", &height);

	while (1) {
		if (height < 30) return height;

		fprintf(stderr, "Pick another height (must be between 1    and 30):");
		scanf("%d", &height);
	}
	return height;
}

void print_pyramid() {
	int height = get_height();
	int i, k, space;

	for (i = 1; i <= height; ++i, k = 0) {
		for (space = 1; space <= height - i; ++space) {
			printf(" ");
		}
		while(k != 2 * i - 1) {
			printf("*");
			++k;
		}
		printf("\n");
	}
	return;
}

void many_pyramids() {
	int height = get_height();

	int i, k, space;
	int count;

	for (count = 1; count <= height; count++) {
		for (i = 1; i <= count; ++i, k = 0) {
			for (space = 1; space <= height - i; ++space) {
				printf(" ");
			}
			while(k != 2 * i - 1) {
				printf("*");
				++k;
			}
			printf("\n");
		}
	}
	return;
}
