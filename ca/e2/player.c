#include <stdlib.h>
#include <stdio.h>

#define DECK_LEN = 52
#include "ds3.c"
#include "test3.c"

typedef struct {
    int id;
    llist* cards;
} Player;


Player *create_player(int new_id, llist *new_cards) {
    Player *new_player = (Player *) malloc(sizeof(Player));

    new_player->id = new_id;
    new_player->cards = new_cards;
    return new_player;
}

void print_player(Player* player) {
    printf("%d: ", player->id);
    llist_print(player->cards, numprint);
}


void init_players(int Nplayers, Player* players) {
    int i;
}

int main() {
    Player player1 = create_player(1, )
}
