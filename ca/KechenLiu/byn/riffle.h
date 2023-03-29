#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define INTEGER_SIZE 4

/* init, set time as random seed */
void init();

/*
 * generate random number at the range of [low, high)
 * input:
 * int low: lowest bound
 * int high: highest bound
 * return: a random number between [low, high)
 */
int randomize(int, int);


/*
 * automatically generate an integer deck[1, 2, ..., len]
 * input:
 * int* deck a pointer to an integer array
 * const int len: the length of the array
 */
void init_array(int*, const int);


/*
 * print integer deck
 * parameters:
 * int* deck a pointer to an integer array
 * const int len: the length of the array
 */
void printIntDeck(const int*, const int);


/*
 * print array of strings
 * parameters:
 * int* deck a pointer to an integer array
 * const int len: the length of the array
 */
void printCharDeck(char *deck[], int len);

/*
 * performs a single riffle shuffle of the array L each of whose len elements is of size size bytes
 * parameters:
 * void *L: array needed to be shuffled
 * int len: length of the array
 * int size: elements of size size bytes
 * void* work: the array work should be an additional array of at least the same size as L that can be used as workspace
 */
void riffle_once(void*, int, int, void*);

/*
 * thoroughly shuffles the array L by performing N successive riffles
 * parameters:
 * void* L: array needs to be shuffles
 * int len: the length of the array
 * int size: the size of elements
 * int N: shuffle times
 */
void riffle(void*, int, int, int);

/*
 * cmp functions for comparing integers
 * return -1, 0 or +1 if the first argument is greater than, equal to, or less than the second argument respectively
 */
int cmpInt(void*, void*);

/*
 * cmp functions for comparing string
 */
int cmpStr(void*, void*);

/*
 * checks that your riffle function respects that
 * all the elements in the original array should be in the shuffled array and vice versa ;
 * void* L: array needed to be checked
 * int len: length of the array
 * int size: size of element in the array
 * int (*cmp)(void *, void *): compare function
 * it should return 1 if it does and 0 if not.
 */
int check_shuffle(void*, int, int, int (*cmp)(void *, void *));

/*
 * evaluates how well an array numbers of len integers is shuffled
 * int* numbers: an array of integers
 * int len: length of the array
 * return: quality of the shuffled array, which shows how well an array number of len integers is shuffled
 */
float quality(int*, int);

/* automatically generate an integer array with length len(0, 1, 2, ..., len - 1) */
void generate_array_for_quality(int*, int);

/*
 * evaluate the average quality of a shuffle of the integers
 * int N: array length, can be used to generate an array with elements 0, 1, ..., N - 1.
 * int shuffles: times for shuffling the array
 * int trials: times of trials
 * return: average quality
 */
float average_quality(int N, int shuffles, int trials);
