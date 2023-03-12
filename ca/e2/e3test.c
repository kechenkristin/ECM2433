#include <stdlib.h>
#include <stdio.h>

#define DECK_LEN = 52
#include "ds3.c"
#include "test3.c"
#include "player.c"




/* that returns true (non-zero) if one player has all the cards and the others have none */
int finished(Player *players, int Nplayers);

/* play a single game of beggar-your-neighbour with Nplayers using the shuffled deck of cards. If the argument talkative
is not zero, your function should print details of what it is doing, similar to the excerpt above. Your
function should return the number of turns that it takes for the game to finish.*/
int beggar(int Nplayers, int *deck, int talkative);

void deal_card_for_player(int Nplayers, int *deck, Player *players);


void deal_card_for_player(int Nplayers, int *deck, Player *players){
    riffle(deck, 52, 4, 11);

    int player_handcard_number = 52 / Nplayers;
    int i;
    for (i = 0; i < player_handcard_number * Nplayers; i++) {
        llist_add_rear((deck + i), (players + i % Nplayers)->cards);
    }
}


/* automatically generate an integer deck[2, 3 ..., 14] * 4 */
void init_deck(int *deck) {
    int i;
    for (i = 0; i < 52; i++) {
        // if ((i % 14) == 0) continue;
        *deck++ = (i % 13) + 2;
    }
}





int main() {
    int deck[52];
    init_deck(deck);
    printIntDeck(deck, 52);

    printf("\n deal cards for players\n");
    // deal_card_for_player(4, deck, )
}
