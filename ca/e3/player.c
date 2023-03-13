#include <stdlib.h>
#include <stdio.h>

#define DECK_LEN = 52
#include "llist.c"
#define PLAYER_SIZE = 16

typedef struct {
    int id;
    llist* cards;
} Player;

unsigned int get_player_size() {
    return sizeof(Player);  // 16
}

Player *create_single_player(int new_id, llist *new_cards) {
    unsigned int player_size = get_player_size();
    Player *new_player;
    new_player = (Player *) malloc(player_size);

    new_player->id = new_id;
    new_player->cards = new_cards;
    return new_player;
}

// rewrite without using malloc

int* init_player_cards_from_deck(int id, int *deck, int len) {
    // ! where to free???
    int* cards = (int *) malloc(len * sizeof(int));
    int* dptr = deck + id * len;
    int* cptr = cards;

    int i;
    for (i = 0; i < len; i++) {
        memcpy(cptr++, dptr++, sizeof(int ));
    }
    // free(cards);
    return cards;
}


/* create a llist from an integer array .*/
/*
llist create_llist_from_array(int *numbers, int len) {
    llist *my_list = llist_create(NULL);

    int i;
    for (i = 0; i < len; i++) {
        llist_add_rear((void *) (numbers + i), my_list);
    }
    return my_list;
}
 */

Player *create_Nplayers(int Nplayers, int *deck) {
    unsigned int player_size = get_player_size();
    int player_cards_number = 52 / Nplayers;

    Player *players = (Player *) malloc( Nplayers * player_size);

    int i;
    for (i = 0; i < Nplayers; i++) {
        (players + i * player_size)->id = i;
        // (players + i * player_size)->cards = llist_create(NULL);
        int *new_cards = init_player_cards_from_deck(i, deck, player_cards_number);
        (players + i * player_size)->cards = create_llist_from_array(new_cards, player_cards_number);
        // free(new_cards);
    }
    return players;
}

Player* get_player_by_id(int id, Player *players) {
    unsigned int player_size = get_player_size();
    return (players + id * player_size);
}


// shall we use malloc?
// return an array of pointers to players
/*
Player* init_Nplayers(int Nplayers) {
    int i;
    Player* players = (Player *) malloc(8 * Nplayers);

    for(i = 0; i < Nplayers; i++) {
        llist player_cards = llist_create(NULL);
        Player *player = create_single_player(i, player_cards);
        // (players + i * sizeof (Player)) = player;
        // (players + i * 8) = player;
        // print_single_player(player);
        *(players + i * 8) = *player;
        // printf("%p\n", players + i * 8);
    }
    return players;
}
 */

void print_single_player(Player* player) {
    printf("%d: ", player->id);
    llist_print(player->cards, numprint);
}

void print_players(Player* players, int Nplayers) {
    int i;
    unsigned int player_size = get_player_size();

    for (i = 0; i < Nplayers; i++) {
        print_single_player( players + i * player_size);
    }
}