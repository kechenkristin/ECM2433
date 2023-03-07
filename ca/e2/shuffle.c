/* Online C Compiler and Editor */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10


void init() {
    srand((unsigned int) time(NULL));
}


int randomize(int low, int high) {
    int diff, val;

    diff = high - low;
    if (diff == 0) {
        return low;
    }

    val = rand() % diff;
    return val + low;
}

void initDeck(int *deck, const int size) {
    int i;
    for (i = 0; i < size; ++i) {
        *deck++ = i + 1;
    }
}

void writeDeck(const int *deck, const int size) {
    int i;

    printf("[");
    if (size > 0) {
        printf("%d", *deck++);
    }
    for (i = 1; i < size; ++i) {
        printf(", %d", *deck++);
    }
    printf("]");
}


void riffle_once(int *L, int len, int size, int *work) {
    int wlp, lp, rp, cutPoint;

    cutPoint = len / 2;
    // printf("%d", cutPoint);
    wlp = 0;
    lp = 0;
    rp = cutPoint;

    // int i;
    work = (int *) malloc(len * sizeof(size));

    while (lp < cutPoint && rp < len) {

        if (randomize(0, 2) == 1) {
            work[wlp++] = L[rp++];
        } else {
            work[wlp++] = L[lp++];
        }
    }

    /*
    printf("work\n");
    for (i = 0; i < len; i++) {
        printf("%d ", work[i]);
    }
     */

    while (lp < cutPoint) {
        work[wlp++] = L[lp++];
    }

    while (rp < len) {
        work[wlp++] = L[rp++];
    }

    // test work
    /*
    printf("work\n");
    for (i = 0; i < len; i++) {
        printf("%d ", work[i]);
    }
    printf("\n");
     */

    memcpy(L, work, len * sizeof(size));

    /*
    printf("L\n");
    for (i = 0; i < len; i++) {
        printf("%d ", L[i]);
    }
     */

    free(work);
    // printf("\n");
}


void riffle(void *L, int len, int size, int N) {
    int *work;
    int i;
    for (i = 0; i < N; i++) {
        riffle_once(L, len, size, work);
    }
}


int main() {
    printf("randomize: %d\n", randomize(0, 2));

    int deck[SIZE];

    init();

    printf("Riffle e2\n");
    initDeck(deck, SIZE);
    writeDeck(deck, SIZE);
    printf("\n");
    int *work;
    int i;


    riffle(deck, SIZE, 4, 100);
    writeDeck(deck, SIZE);
    printf("\n\n");
}

