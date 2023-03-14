#include <stdlib.h>
#include <stdio.h>

#define DECK_LEN  52
#include "list.c"
#define PLAYER_SIZE 16

typedef struct {
    int id;
    llist *cards;
} Player;

unsigned int get_player_size() {
    return sizeof(Player);  // 16
}

Player *create_single_player(int new_id, llist *new_cards) {
    Player *new_player;
    new_player = (Player *) malloc(PLAYER_SIZE);

    new_player->id = new_id;
    new_player->cards = new_cards;
    return new_player;
}



// rewrite without using malloc
// doesn't work
llist init_player_hand_cards(int id, int *deck, int len) {
    int *hand_cards = deck + id * len;

    int i;
    llist* hand_cards_llist;
    hand_cards_llist = llist_create(0);
    for (i = 0; i < len; i++) {
        llist_add_rear(*(hand_cards + i), hand_cards_llist);
        // printf("%d ", *(hand_cards + i));
    }
    printf(" ");
    // llist_print(hand_cards_llist, numprint);
    return hand_cards_llist;
}



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



Player* init_Nplayers(int Nplayers, int *deck) {
    int player_cards_number = DECK_LEN / Nplayers;
    Player *players = malloc(8 * Nplayers);
    Player *ptr = players;

    int i;

    for (i = 0; i < Nplayers; i++) {
        int *new_cards_malloc = init_player_cards_from_deck(i, deck, player_cards_number);
        ptr = create_single_player(i, new_cards_malloc);
        // players[i]->id = i;
        // players[i].cards = create_llist_from_array(new_cards_malloc, player_cards_number);
        // players = create_single_player(i, new_cards_malloc);
        ptr += 8;
    }

    return players;
}


void print_single_player(Player* player) {
    printf("%d: ", player->id);
    llist_print(player->cards);
}

void print_players(Player* players, int Nplayers) {
    int i;
    for (i = 0; i < Nplayers; i++) {
        // print_single_player(get_player_by_id(i, players));
        // players++;
        print_single_player(players);
        players += PLAYER_SIZE;
    }
}

Player *create_Nplayers(int Nplayers, int *deck) {
    int player_cards_number = DECK_LEN / Nplayers;
    printf("player cards number: %d\n", player_cards_number);
    Player *players = (Player *) malloc( Nplayers * PLAYER_SIZE);
    Player *ptr = players;

    int i;
    for (i = 0; i < Nplayers; i++) {
        ptr->id = i;
        // malloc free
        int *new_cards_malloc = init_player_cards_from_deck(i, deck, player_cards_number);
        ptr->cards = create_llist_from_array(new_cards_malloc, player_cards_number);
        // llist_print((ptr->cards));
        print_single_player(ptr);
        // printf("size: %d\n", sizeof(*ptr));
        ptr += PLAYER_SIZE;
        // free(new_cards_malloc);
    }

   //  print_players(players, Nplayers);

    return players;
}

/* returns true(not 0) if the deck is equal divided. */
int equal_divided(int Nplayers) {
    int player_cards_number = DECK_LEN / Nplayers;
    int player_cards = player_cards_number * Nplayers;
    int remain_cards = 52 - player_cards;
    return remain_cards;
}

/*
llist init_pile(int Nplayers, int *deck) {
    int player_hand_cards = 52 / Nplayers;
    int player_cards = player_hand_cards * Nplayers;
    int pile_cards = 52 - player_cards;

    llist pile_llist;

    if (pile_cards > 0) {
        int* pile;
        pile = deck + player_cards;
        pile_llist = create_llist_from_array(pile, pile_cards);
    } else {
        pile_llist = llist_create(NULL);
    }
    return pile_llist;
}
 */

void remove_players(Player* players) {
    free(players);
}

Player* get_player_by_id(int id, Player *players) {
    Player *ptr = players;
    return (Player *) (ptr + id * PLAYER_SIZE);
}





void print_players2(Player* players, int Nplayers) {
    int i;
    for (i = 0; i < Nplayers; i++) {
        printf("%d: ", players->id);
        llist_print(players->cards);
        players += PLAYER_SIZE;
    }
}
