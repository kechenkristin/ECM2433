#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

float* generateArr(float* array, int arrLen);
void histogram(float* array, int arrLen);

int main() {
	float demo[1000];
	int demoSize = sizeof(demo) / sizeof(demo[1]);
	float* demoPointer = demo;
	demoPointer = generateArr(demo, demoSize);

	histogram(demo, demoSize);
	return 0;
}

float* generateArr(float* array, int arrLen) {
	const gsl_rng_type *T;
	gsl_rng *r;
	/* create a random number generator */
	gsl_rng_env_setup();
	T = gsl_rng_default;
	r = gsl_rng_alloc(T);
	/* seed it – equivalent of srand(time(0)) */
	gsl_rng_set(r,time(0));


	int i;

	for (i = 0; i < arrLen; i++) {
		/* array[i] = gsl_ran_flat(r, 0, 9); */
		array[i] = gsl_ran_gaussian(r, 5);
		printf("%2d: %lf\n", i, array[i]);
	}

	return array;
}

void histogram(float* array, int arrLen) {
	int i;

	int count[8];

	for (i = 0; i < 9; i++) {
		count[i] = 0;
	}

	for (i = 0; i < arrLen; i++) {
		if (array[i] >= 0 && array[i] < 1) count[0]++;
		if (array[i] >= 1 && array[i] < 2) count[1]++;
		if (array[i] >= 2 && array[i] < 3) count[2]++;
		if (array[i] >= 3 && array[i] < 4) count[3]++;
		if (array[i] >= 4 && array[i] < 5) count[4]++;
		if (array[i] >= 5 && array[i] < 6) count[5]++;
		if (array[i] >= 6 && array[i] < 7) count[6]++;
		if (array[i] >= 7 && array[i] < 8) count[7]++;
		if (array[i] >= 8 && array[i] < 9) count[8]++;
	}

	int j;

	for (i = 0; i < 9; i++) {
		printf("%d: ", i);
		for (j = 0; j < count[i]; j++) {
			printf("X");
		}
		printf("\n");
	}
}
