#include <stdlib.h>
#include <stdio.h>

#define DECK_LEN  52

#include "list.c"

#define PLAYER_SIZE 16

typedef struct {
    int id;
    llist cards;
} Player;

unsigned int get_player_size() {
    return sizeof(Player);  // 16
}

Player *create_single_player(int new_id, llist *new_cards) {
    Player *new_player;
    new_player = (Player *) malloc(PLAYER_SIZE);

    new_player->id = new_id;
    new_player->cards = (llist) malloc(sizeof(llist));
    new_player->cards = new_cards;
    return new_player;
}


void print_single_player(Player *player) {
    printf("%d: ", player->id);
    llist_print(player->cards);
}


int *init_player_cards_from_deck(int id, int *deck, int len) {
    int *cards = (int *) malloc(len * sizeof(int));
    int *dptr = deck + id * len;
    int *cptr = cards;

    int i;
    for (i = 0; i < len; i++) {
        memcpy(cptr++, dptr++, sizeof(int));
    }
    return cards;
}


Player *create_Nplayers(int Nplayers, int *deck) {
    int player_cards_number = DECK_LEN / Nplayers;
    Player *players = malloc(Nplayers * sizeof(Player));

    int i;

    for (i = 0; i < Nplayers; i++) {
        players[i].id = i;
        int *new_cards_malloc = init_player_cards_from_deck(i, deck, player_cards_number);
        players[i].cards = (llist) malloc(sizeof(llist));
        players[i].cards = create_llist_from_array(new_cards_malloc, player_cards_number);
        free(new_cards_malloc);
    }
    return players;
}

/* init Nplayers for the game, create an array of Players. */
Player *init_Nplayers(int Nplayers) {
    Player *players = malloc(Nplayers * sizeof(Player));
    int i;

    for (i = 0; i < Nplayers; i++) {
        players[i].id = i;
        players[i].cards = (llist) malloc(sizeof(llist));
        players[i].cards = llist_create();
    }
    return players;
}

/* print out all the players in the players array with the id: cards format. */
void print_players(Player *players, int Nplayers) {
    int i;
    for (i = 0; i < Nplayers; i++) {
        printf("%d: ", players[i].id);
        llist_print(players[i].cards);
    }
}

/* get a player by the id, return a pointer to the player */
Player* get_player_by_id(int id, Player *players) {
    return &players[id];
}

/* free the memory area created by malloc. */
void remove_players(Player *players, int Nplayers) {
    int i;

    for (i = 0; i < Nplayers; i++) {
        free(players[i].cards);
    }
    free(players);
}