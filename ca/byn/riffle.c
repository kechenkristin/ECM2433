#include <stdio.h>
#include "riffle.h"

/* init, set time as random seed */
void init() {
    srand((unsigned int) time(NULL));
}


/*
 * generate random number at the range of [low, high)
 * input:
 * int low: lowest bound
 * int high: highest bound
 * return: a random number between [low, high)
 */
int randomize(int low, int high) {
    int diff, val;

    diff = high - low;
    if (diff == 0) {
        return low;
    }

    val = rand() % diff;
    return val + low;
}


/*
 * automatically generate an integer deck[1, 2, ..., len]
 * input:
 * int* deck a pointer to an integer array
 * const int len: the length of the array
 */
void init_array(int *deck, const int len) {
    int i;
    for (i = 0; i < len; ++i) {
        *deck++ = i + 1;
    }
}


/*
 * print integer deck
 * parameters:
 * int* deck a pointer to an integer array
 * const int len: the length of the array
 */
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


/* https://stackoverflow.com/questions/37224829/printing-strings-from-an-array-in-a-function-in-c */
/*
 * print array of strings
 * parameters:
 * int* deck a pointer to an integer array
 * const int len: the length of the array
 */
void printCharDeck(char *deck[], const int len) {
    int i;

    printf("[");
    for (i = 0; i < len; i++){
        printf("%s", deck[i]);
    }
    printf("]");
}


/*
 * performs a single riffle shuffle of the array L each of whose len elements is of size size bytes
 * parameters:
 * void *L: array needed to be shuffled
 * int len: length of the array
 * int size: elements of size size bytes
 * void* work: the array work should be an additional array of at least the same size as L that can be used as workspace
 */
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


/*
 * thoroughly shuffles the array L by performing N successive riffles
 * parameters:
 * void* L: array needs to be shuffles
 * int len: the length of the array
 * int size: the size of elements
 * int N: shuffle times
 */
void riffle(void *L, int len, int size, int N) {
    void *work;
    int i;
    for (i = 0; i < N; i++) {
        riffle_once(L, len, size, work);
    }
}


/*
 * cmp functions for comparing integers
 * return -1, 0 or +1 if the first argument is greater than, equal to, or less than the second argument respectively
 */
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


/*
 * cmp functions for comparing string
 */
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


/*
 * checks that your riffle function respects that
 * all the elements in the original array should be in the shuffled array and vice versa ;
 * void* L: array needed to be checked
 * int len: length of the array
 * int size: size of element in the array
 * int (*cmp)(void *, void *): compare function
 * it should return 1 if it does and 0 if not.
 */
int check_shuffle(void *L, int len, int size, int (*cmp)(void *, void *)) {
    void *before, *after, *BPtr, *APtr;

    // allocate memory space 
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

    // free
    free(before);
    free(after);

    if (is_equal_count == len) return 1;
    return 0;
}


/*
 * evaluates how well an array numbers of len integers is shuffled
 * int* numbers: an array of integers
 * int len: length of the array
 * return: quality of the shuffled array, which shows how well an array number of len integers is shuffled
 */
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


/*
 * evaluate the average quality of a shuffle of the integers
 * int N: array length, can be used to generate an array with elements 0, 1, ..., N - 1.
 * int shuffles: times for shuffling the array
 * int trials: times of trials
 * return: average quality
 */
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
