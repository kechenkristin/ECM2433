#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void riffleShuffle(int *const deck, const int size, int flips) {
    int n, cutPoint, nlp, lp, rp, bound;
    int *nl;

    nl = (int *) malloc(size * sizeof(int));

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

float quality(int *numbers, int len) {
    int good_count = 0;
    int num_of_pairs = len - 1;

    int *sPtr, *fPtr, i;
    fPtr = numbers;
    fPtr++;
    // printf("%d\n", *fPtr);

    for (sPtr = numbers, i = 0; i < num_of_pairs; fPtr++, sPtr++, i++) {
        printf("(%d, %d) ", *sPtr, *fPtr);
        if (*sPtr < *fPtr) good_count++;
    }
    printf("\n");
    printf("%d\n", good_count);
    printf("%d\n", len);
    float ret = good_count / (float) num_of_pairs;
    return ret;
}


int main() {

    int arr[7];
    printf("\n");


    int i;
    int good_count = 0;

    for (i = 0; i < 7; i++) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    int *sPtr, *fPtr;
    // sPtr = arr;
    // printf("%d\n", *sPtr);
    fPtr = arr;
    fPtr++;
    // printf("%d\n", *fPtr);

    for (sPtr = arr; *fPtr; fPtr++, sPtr++) {
        printf("(%d, %d) ", *sPtr, *fPtr);
        if (*sPtr < *fPtr) good_count++;
    }
    printf("\n");
    printf("%d\n", good_count);

    for (i = 0; i < 7 - 1; i++) {
        printf("(%d, %d) ", arr[i], arr[i + 1]);
    }
    printf("\n");
    float f1 = quality(arr, 7);
    printf("%f\n", f1);

    int nums[] = {1, 4, 2, 3, 6, 5, 0};
    float f2 = quality(nums, 7);
    printf("%f\n", f2);

}