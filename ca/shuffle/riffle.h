#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20
#define INTEGER_SIZE 4

/* init, set time as random seed */
void init();

/* generate random number at the range of [low, high) */
int randomize(int, int);

/* automatically generate an integer deck[1, 2, ..., len] */
void init_array(int*, const int);

/* print integer deck */
void printIntDeck(const int*, const int);

/* print array of strings */
// void printCharDeck(char*, int);
void printCharDeck(char *deck[], int len);

/*  performs a single riffle shuffle of the array L each of
 whose len elements is of size size bytes */
void riffle_once(void*, int, int, void*);

/* riffle the cards. */
void riffle(void*, int, int, int);

/* cmp functions for comparing integers,
 * return -1, 0 or +1 if the first argument is greater than, equal to, or less than the second
argument respectively */
int cmpInt(void*, void*);

/* cmp functions for comparing string*/
int cmpStr(void*, void*);

/* checks that your riffle function respects that
 * all the elements in the original array should be in the shuffled array and vice versa ;
 * it should return 1 if it does and 0 if not. */
int check_shuffle(void*, int, int, int (*cmp)(void *, void *));

/* evaluates how well an array numbers of len integers is shuffled */
float quality(int*, int);

/* automatically generate an integer array with length len(0, 1, 2, ..., len - 1) */
void generate_array_for_quality(int*, int);

/* evaluate the average quality of a shuffle of the integers */
float average_quality(int, int, int);
