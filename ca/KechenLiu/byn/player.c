#include <stdlib.h>
#include "player.h"


/* init Nplayers for the game, create an array of Players. */
Player *init_Nplayers(int Nplayers) {
    Player *players = malloc(Nplayers * sizeof(Player));
    int i;

    for (i = 0; i < Nplayers; i++) {
        players[i].id = i;
        players[i].cards = malloc(sizeof(llist));
        players[i].cards = llist_create();
    }
    return players;
}


/* free the memory area created by malloc. */
void remove_players(Player *players, int Nplayers) {
    int i;

    for (i = 0; i < Nplayers; i++) {
        free(players[i].cards);
    }
    free(players);
}
