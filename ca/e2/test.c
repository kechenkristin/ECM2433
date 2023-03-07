#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10

void init() {
    srand((unsigned int)time(NULL));
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

void riffleShuffle(int * const deck, const int size, int flips) {
    int n, cutPoint, nlp, lp, rp, bound;
    int *nl;

    nl = (int *)malloc(size * sizeof(int));

    for (n = 0; n < flips; ++n) {
        cutPoint = size / 2;

        if (randomize(0, 2) > 0) {
            cutPoint = cutPoint + randomize(0, size / 10);
        } else {
            cutPoint = cutPoint - randomize(0, size / 10);
        }


        nlp = 0;
        lp = 0;
        rp = cutPoint;

        while (lp < cutPoint && rp < size) {
            /* Allow for an imperfect riffling so that more than one card can come from the same side in a row
               biased towards the side with more cards. Remove the IF statement for perfect riffling. */
            bound = (cutPoint - lp) * 50 / (size - rp);
            printf("bound: %d\n", bound);
            if (randomize(0, 50) >= bound) {
                nl[nlp++] = deck[rp++];
            } else {
                nl[nlp++] = deck[lp++];
            }
        }
        while (lp < cutPoint) {
            nl[nlp++] = deck[lp++];
        }
        while (rp < size) {
            nl[nlp++] = deck[rp++];
        }

        memcpy(deck, nl, size * sizeof(int));
    }

    free(nl);
}



int main() {

    int deck[SIZE];

    init();

    printf("Riffle e2\n");
    initDeck(deck, SIZE);
    writeDeck(deck, SIZE);
    printf("\n");
    riffleShuffle(deck, SIZE, 100);
    writeDeck(deck, SIZE);
    printf("\n\n");

    /*
    printf("test\n");
    int wlp, lp, rp, cutPoint;
    int len = 8;

    cutPoint = len / 2;
    // printf("%d", cutPoint);
    wlp = 0;
    lp = 0;
    rp = cutPoint;


    // int L[] = {1, 2, 3,  4};

    int i;
    int L[8];

    for (i = 0; i < 8; i++) {
        // printf("%d ", L[i]);
        L[i] = i;
    }
    //int* work;

    //work = (int *) malloc(len * sizeof(4));
    int work[8];

    while (lp < cutPoint && rp < len) {
        int chance = chance_50();

        if (chance == 0) {
            work[wlp] = L[rp];
            wlp++;
            rp++;
        } else {
            work[wlp] = L[lp];
            wlp++;
            lp++;
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

    // memcpy(L, work, len * sizeof(4));

    printf("L\n");
    for (i = 0; i < len; i++) {
        printf("%d ", L[i]);
    }

    // free(work);
    printf("\n");
     */


}