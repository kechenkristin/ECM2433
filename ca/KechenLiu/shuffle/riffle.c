#include "riffle.h"
#include <stdio.h>


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


void init_array(int *deck, const int len) {
    int i;
    for (i = 0; i < len; ++i) {
        *deck++ = i + 1;
    }
}


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
void printCharDeck(char *deck[], const int len) {
    int i;

    printf("[");
    for (i = 0; i < len; i++){
        printf("%s", deck[i]);
    }
    printf("]");
}

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


void riffle(void *L, int len, int size, int N) {
    void *work;
    int i;
    for (i = 0; i < N; i++) {
        riffle_once(L, len, size, work);
    }
}


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


void generate_array_for_quality(int *nums, int len) {
    int i;
    for (i = 0; i < len; i++) {
        *nums = i;
        nums++;
    }
}


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
