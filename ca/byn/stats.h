#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int shortest;
    int longest;
    int average;
} Stats;

Stats* create_stats(int shortest, int longest, int average);

void print_stats(Stats *stats);

void free_stats(Stats *stats);