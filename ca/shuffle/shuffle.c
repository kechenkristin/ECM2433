/* Online C Compiler and Editor */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int chance_50() {
    srand(time(NULL));   // Initialization, should only be called once.
    // [0, 100)
    return rand() % 2;
}

void riffle_once(int *L, int len, int size, int *work) {
    int wlp, lp, rp, cutPoint;

    cutPoint = len / 2;
    // printf("%d", cutPoint);
    wlp = 0;
    lp = 0;
    rp = cutPoint;

    int i;
    work = (int *) malloc(len * sizeof(4));

    while (lp < cutPoint && rp < len) {
        int chance = chance_50();

        if (chance == 0) {
            work[wlp++] = L[rp++];
        } else {
            work[wlp++] = L[lp++];
        }
    }

    printf("work\n");
    for (i = 0; i < len; i++) {
        printf("%d ", work[i]);
    }

    while (lp < cutPoint) {
        work[wlp++] = L[lp++];
    }

    while (rp < len) {
        work[wlp++] = L[rp++];
    }

    // test work
    printf("work\n");
    for (i = 0; i < len; i++) {
        printf("%d ", work[i]);
    }
    printf("\n");

    memcpy(L, work, len * sizeof(size));

    printf("L\n");
    for (i = 0; i < len; i++) {
        printf("%d ", L[i]);
    }

    free(work);
    printf("\n");
}

int main() {
    int myNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *work;
    int i;

    int test[100];


    for (i = 0; i < 100; i++) {
        test[i] = i;
    }


    /*
	for (i =0; i < 8; i++) {
		printf("%d", myNumbers[i]);
	}
     */

    // riffle_once(test, 100, 4, work);

    printf("\n");


    /*
    for (i = 0; i < 100; i++) {
        printf("%d ", test[i]);
    }
     */

    int shortTest[] = {1, 2, 3, 4};
    riffle_once(shortTest, 4, 4, work);

    srand(time(NULL));   // Initialization, should only be called once.
    // [0, 100)
    int r = rand() % 2;
    printf("%d", r);
}
