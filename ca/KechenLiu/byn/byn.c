#include <stdlib.h>
#include <stdio.h>

#include "beggar.h"
#include "stats.h"


/*
 * uses your beggar function to find the shortest, average and longest of games games
 *
 * int Nplayers: number of players
 * int games: times of trials
 *
 * returns a strut with fields shortest, longest and average.
 */
Stats *statistics(int Nplayers, int games) {
    int i;
    int average_sum = 0;
    int shortest = 999;
    int longest = 0;


    for (i = 0; i < games; i++) {

        int *deck_array = init_deck_array();
        int per = beggar(Nplayers, deck_array, 0);

        if (per < shortest) shortest = per;
        if (per > longest) longest = per;
        average_sum += per;
    }

    int average = average_sum / games;
    return create_stats(shortest, longest, average);
}

int main(int argc, char *argv[]) {
    int maxNumOfPlayers, numOfTrials;
    maxNumOfPlayers = atoi(argv[1]);
    numOfTrials = atoi(argv[2]);
    printf("You have entered %d as max number of players, %d as trial times\n", maxNumOfPlayers, numOfTrials);

    if (numOfTrials < 100) {
        printf("At least 100 trials, now the program terminates! Please retype and re-run again! \n");
        return 0;
    }

    int i;

    char *filename = "statistics.txt";
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening the file %s", filename);
        return -1;
    }


    for (i = 2; i <= maxNumOfPlayers; i++) {
        Stats *stats = statistics(i, numOfTrials);
        printf("%d players: \n", i);
        print_stats(stats);

        fprintf(fp, "%d players: \nshortest: %d\nlongest: %d\naverage: %d\n", i,stats->shortest, stats->longest, stats->average);

        free_stats(stats);
    }
}
