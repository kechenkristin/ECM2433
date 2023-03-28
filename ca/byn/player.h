#include <stdlib.h>
#define DECK_LEN  52
#include "list.h"


typedef struct {
    int id;
    llist* cards;
} Player;


/* init Nplayers for the game, create an array of Players. */
Player *init_Nplayers(int Nplayers);

/* free the memory area created by malloc. */
void remove_players(Player *players, int Nplayers);
