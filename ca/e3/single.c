//
// Created by kristin on 26/03/23.
//


#include <stdio.h>

#include "beggar.c"

int main(int argc, char *argv[]) {
    /* https://stackoverflow.com/questions/5157337/reading-command-line-parameters */
    int numOfPlayers;
    numOfPlayers = atoi(argv[1]);
    printf("You have entered %d as number of players. \n", numOfPlayers);

    int *deck_array = init_deck_array();
    beggar(numOfPlayers, deck_array, 1);

}