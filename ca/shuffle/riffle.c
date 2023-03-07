#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void init() {
	srand((unsigned int) time(NULL));
}


int randomize(int low, int high) {
	srand((unsigned int) time(NULL));
	int diff, val;

	diff = high - low;
	if (diff == 0) {
		return low;
	}

	val = rand() % diff;
	return val + low;
}


void riffle_once(void *L, int len, int size, void *work) {
	int wlp, lp, rp, cutPoint;
	void *ptr, *LPtr, *RPtr;

	cutPoint = len / 2;
	wlp = 0;
	lp = 0;
	rp = cutPoint;


	work = malloc(len * size);

	ptr = work;
	LPtr = L;
	RPtr = L + size * cutPoint;

	// printf("%p", LPtr);

	while (lp < cutPoint && rp < len) {

		if (randomize(0, 2) == 1) {
			memcpy(ptr, LPtr, size);
			ptr += size;
			LPtr += size;
			wlp++;
			lp++;
			// work[wlp++] = L[lp++];
		} else {
			memcpy(ptr, RPtr, size);
			ptr += size;
			RPtr += size;
			wlp++;
			rp++;
			// work[wlp++] = L[rp++];
		}
	}




	while (lp < cutPoint) {
		memcpy(ptr, LPtr, size);
		ptr += size;
		LPtr += size;
		wlp++;
		lp++;
		// work[wlp++] = L[lp++];
	}

	while (rp < len) {
		memcpy(ptr, RPtr, size);
		ptr += size;
		RPtr += size;
		wlp++;
		rp++;
		// work[wlp++] = L[rp++];
	}
	memcpy(L, work, len * size);
	free(work);
}


void riffle(void *L, int len, int size, int N) {
	int *work;
	int i;
	for (i = 0; i < N; i++) {
		riffle_once(L, len, size, work);
	}
}
