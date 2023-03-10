#include <stdio.h>

#include "test3.c"



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

    /*
    int test[20];
    generate_array(test, 20);
    printIntDeck(test, 20);
     */
    // float test2 = average_quality(21, 1, 1);
    // printf("%f", test2);

    int shuffles;
    for (shuffles = 1; shuffles <= 15; shuffles++) {
        float aq = average_quality(50, shuffles, 30);
        printf("average quality (with %d shuffles): %f \n", shuffles, aq);
    }
}