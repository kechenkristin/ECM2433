#include <stdio.h>

#include "stats.h"

Stats* create_stats(int shortest, int longest, int average) {
    Stats* stats;
    stats = (Stats *) malloc(sizeof(Stats));

    stats->shortest = shortest;
    stats->longest =longest;
    stats->average = average;

    return stats;
}

void print_stats(Stats *stats) {
    printf("shortest: %d\nlongest: %d\naverage: %d\n", stats->shortest, stats->longest, stats->average);
}

void free_stats(Stats *stats) {
    free(stats);
}

