#include <stdio.h>
#include <stdlib.h>
#include "stats.h"


/*
 * create a Stats struct
 */
Stats* create_stats(int shortest, int longest, int average) {
    Stats* stats;
    stats = (Stats *) malloc(sizeof(Stats));

    stats->shortest = shortest;
    stats->longest =longest;
    stats->average = average;

    return stats;
}

/*
 * print the Stats struct
 */
void print_stats(Stats *stats) {
    printf("shortest: %d\nlongest: %d\naverage: %d\n", stats->shortest, stats->longest, stats->average);
}

/*
 * free memory space for the stats struct
 */
void free_stats(Stats *stats) {
    free(stats);
}
