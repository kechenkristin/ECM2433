#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20
#define INTEGER_SIZE 4

/* init, set time as random seed */
void init() {
    srand((unsigned int) time(NULL));
}


/* generate random number at the range of [low, high) */
int randomize(int low, int high) {
    int diff, val;

    diff = high - low;
    if (diff == 0) {
        return low;
    }

    val = rand() % diff;
    return val + low;
}


/* automatically generate an integer deck[1, 2, ..., len] */
void init_array(int *deck, const int len) {
    int i;
    for (i = 0; i < len; ++i) {
        *deck++ = i + 1;
    }
}


/* print integer deck */
void printIntDeck(const int *deck, const int len) {
    int i;

    printf("[");
    if (len > 0) {
        printf("%d", *deck++);
    }
    for (i = 1; i < len; ++i) {
        printf(", %d", *deck++);
    }
    printf("]");
}


/* print array of strings */
/* https://stackoverflow.com/questions/60591105/how-do-i-print-the-contents-of-an-array-of-strings */
void printCharDeck2(const char *deck, const int len) {
    printf("[");
    char **ptr;
    for (ptr = deck; *ptr; ptr++)
        printf("%s", *ptr);
    printf("]");
}


/*  performs a single riffle shuffle of the array L each of
 whose len elements is of size size bytes */
void riffle_once(void *L, int len, int size, void *work) {
    int wlp, lp, rp, cutPoint;
    void *ptr, *LPtr, *RPtr;

    // malloc heap space for work
    work = malloc(len * size);

    // the array to be shuffled will be divided into two halves
    cutPoint = len / 2;
    wlp = 0;
    lp = 0;
    rp = cutPoint;
    ptr = work;
    LPtr = L;
    RPtr = L + size * cutPoint;


    while (lp < cutPoint && rp < len) {
        // 50% chance from left side array
        if (randomize(0, 2) == 1) {
            memcpy(ptr, LPtr, size);
            ptr += size;
            LPtr += size;
            wlp++;
            lp++;
            // work[wlp++] = L[lp++];
        } else {
            // 50% chance from right side array
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


/* shuffles the array L by performing N successive riffles */
void riffle(void *L, int len, int size, int N) {
    void *work;
    int i;
    for (i = 0; i < N; i++) {
        riffle_once(L, len, size, work);
    }
}

/* cmp functions for comparing integers,
 * return -1, 0 or +1 if the first argument is greater than, equal to, or less than the second
argument respectively */
int cmpInt(void *v1, void *v2) {
    int *i1 = (int *)v1;
    int *i2 = (int *)v2;
    int val = *i1 - *i2;

    // first greater than, -1
    if (val > 0) return -1;
    // first less than, 1
    if (val < 0) return 1;
    return 0;
}

/* cmp functions for comparing string*/
int cmpStr(void *v1, void *v2) {
    char *str1 = (char *)v1;
    char *str2 = (char *)v2;
    int val = strcmp(str1, str2);

    // first greater than, -1
    if (val > 0) return -1;
    // first less than, 1
    if (val < 0) return 1;
    return 0;
}

/* checks that your riffle function respects that
 * all the elements in the original array should be in the shuffled array and vice versa ;
 * it should return 1 if it does and 0 if not. */
int check_shuffle(void *L, int len, int size, int (*cmp)(void *, void *)) {
    void *before, *after, *BPtr, *APtr;

    before = malloc(len * size);
    after = malloc(len * size);

    // before shuffle
    memcpy(before, L, len * size);
    // riffle_once(L, len, size, work);
    riffle(L, len, size,1);
    // after shuffle
    memcpy(after, L,len * size);

    int is_equal_count = 0;
    int i, j;

    for (BPtr = before, i = 0; i < len; i++, BPtr+= size) {
        for (APtr = after, j = 0; j < len; j++, APtr+= size) {
            int r = cmp(BPtr, APtr);
            if (r == 0) is_equal_count++;
        }
    }

    free(before);
    free(after);
    return is_equal_count == len;
}


/* evaluates how well an array numbers of len integers is shuffled */
float quality(int *numbers, int len) {
    int good_count = 0;
    int num_of_pairs = len - 1;

    int *sPtr, *fPtr, i;
    fPtr = numbers;
    fPtr++;

    for (sPtr = numbers, i = 0; i < num_of_pairs; fPtr++, sPtr++, i++) {
        if (*sPtr < *fPtr) good_count++;
    }
    float ret = good_count / (float) num_of_pairs;
    return ret;
}

/* automatically generate an integer array with length len(0, 1, 2, ..., len - 1) */
void generate_array_for_quality(int *nums, int len) {
    int i;
    for (i = 0; i < len; i++) {
        *nums = i;
        nums++;
    }
}


/* evaluate the average quality of a shuffle of the integers */
float average_quality(int N, int shuffles, int trials) {
    int array_len = N;
    int nums[array_len];
    float quality_count = 0;
    int i;

    for (i = 0; i < trials; i++) {
        generate_array_for_quality(nums, array_len);
        riffle(nums, array_len, INTEGER_SIZE, shuffles);
        float quality_per = quality(nums, array_len);
        quality_count += quality_per;

    }
    return quality_count / trials;
}


/*
int main() {
    // printf("randomize: %d\n", randomize(0, 2));

    int deck[SIZE];

    init();

    printf("Riffle e2\n");
    initDeck(deck, SIZE);
    writeDeck(deck, SIZE);
    printf("\n");
    int *work;
    int i;

    printf("riffle_once\n");
    riffle_once(deck, SIZE, 4, work);
    writeDeck(deck, SIZE);

    printf("\n");
    printf("riffle\n");
    riffle(deck, SIZE, 4, 100);
    writeDeck(deck, SIZE);
    printf("\n\n");

    printf("test cmp function\n");
    int i1 = 8;
    int i2 = 8;
    int *p1 = &i1;
    int *p2 = &i2;

    int r = cmpInt(p1, p2);
    printf("%d\n", r);

    printf("test check shuffle\n");
    int deck2[SIZE];
    initDeck(deck2, SIZE);
    writeDeck(deck2, SIZE);
    printf("\n");
    int c = check_shuffle(deck2, SIZE, 4, cmpInt);
    writeDeck(deck2, SIZE);
    printf("\n");
    printf("%d\n", c);
}
 */