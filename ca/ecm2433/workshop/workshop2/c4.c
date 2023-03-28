#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

float* generateArr(float* array, int arrLen);

int main() {
	float demo[1000];
	int demoSize = sizeof(demo) / sizeof(demo[1]);
	demo = generateArr(demo, demoSize);
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
		array[i] = gsl_ran_flat(r, 0, 9);
		printf("%2d: %lf\n", i, array[i]);
	}

	return array;
}
