#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int shortest;
    int longest;
    int average;
} Stats;


/*
 * create a Stats struct
 */
Stats* create_stats(int shortest, int longest, int average);


/*
 * print the Stats struct
 */
void print_stats(Stats *stats);


/*
 * free memory space for the stats struct
 */
void free_stats(Stats *stats);
