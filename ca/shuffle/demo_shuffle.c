#include "riffle.h"
#include <stdio.h>

int main() {
    // shuffle an array of integers 1, . . . , 20
    printf("Demonstrate the result of shuffling array.\n");
    int deck[LEN];
    init();
    printf("Before shuffle the integer array\n");
    init_array(deck, LEN);
    printIntDeck(deck, LEN);
    printf("\n");

    printf("After riffle shuffle the integer array\n");
    riffle(deck, LEN, INTEGER_SIZE, 1);
    printIntDeck(deck, LEN);
    printf("\n\n");


    // shuffling the array of Greek letter names:
    int greek_size = 8;
    int greek_len = 12;
    char *greek[] = {" alpha ", " beta ", " gamma ", " delta ", " epsilon ", " zeta ",
                     " eta ", " theta ", " iota ", " kappa ", " lambda ", " mu "};
    printf("Before shuffle the char array\n");
    printCharDeck(greek, greek_len);
    printf("\n");

    printf("After riffle shuffle the char array\n");
    riffle(greek, greek_len, greek_size, 1);
    printCharDeck(greek, greek_len);
    printf("\n\n");


    printf("Test check shuffle\n");
    printf("Test check shuffle for integer array\n");
    int c1 = check_shuffle(deck, LEN, INTEGER_SIZE, cmpInt);
    printf("Return value of check shuffle for integer array (1 if obey rules, 0 not): %d\n", c1);
    int c2 = check_shuffle(greek, greek_len, greek_size, cmpStr);
    printf("Return value of check shuffle for string array (1 if obey rules, 0 not): %d\n", c2);

}
