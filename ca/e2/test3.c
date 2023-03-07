#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void init() {
    srand((unsigned int) time(NULL));
}


int randomize(int low, int high) {
    // srand((unsigned int) time(NULL));
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



void riffle_once(void *L, int len, int size, void *work) {
    // srand((unsigned int) time(NULL));
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

    if (val < 0) return -1;
    if (val == 0) return 0;
    return 1;
}

int cmpStr(void *v1, void *v2) {
    char *str1 = (char *)v1;
    char *str2 = (char *)v2;
    return strcmp(str1, str2);
}

// L05
int check_shuffle(void *L, int len, int size, int (*cmp)(void *, void *)) {
    void *before, *after, *work, *BPtr, *APtr;

    before = malloc(len * size);
    after = malloc(len * size);

    // before shuffle
    memcpy(before, L, len * size);
    riffle_once(L, len, size, work);
    memcpy(after, L, size * len);

    int is_equal = 0;
    int i, j;

    // L04
    for (BPtr = before, i = 0; i < len; i++, BPtr++) {
        for (APtr = after, j = 0; j < len; j++, APtr++) {
            int r = cmp(BPtr, APtr);
            if (r == 0) is_equal = 1;
        }
        is_equal ^= is_equal;
    }
    return is_equal;
}

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
    int i1 = 0;
    int i2 = 8;
    int *p1 = &i1;
    int *p2 = &i2;

    int r = cmpInt(p1, p2);
    printf("%d\n", r);

}
