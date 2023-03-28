#include <stdio.h>
#include "beggar.h"

void deal_card_for_player(int Nplayers, int *deck, Player *players) {
    int i;
    for (i = 0; i < DECK_LEN; i++) {
        llist_add_rear(deck[i], players[i % Nplayers].cards);
    }
}


/* automatically generate an integer deck[2, 3 ..., 14] * 4 */
void init_deck_number(int *deck) {
    int i;
    for (i = 0; i < DECK_LEN; i++)
        // if ((i % 14) == 0) continue;
        *deck++ = (i % PACK_LEN) + 2;
}

void shuffle_deck(int *deck) {
    riffle(deck, DECK_LEN, INTEGER_SIZE, SHUFFLE_TIMES);
}

int *init_deck_array() {
    int *deck_array = (int *) malloc(INTEGER_SIZE * DECK_LEN);
    init_deck_number(deck_array);
    shuffle_deck(deck_array);
    return deck_array;
}


/* init a llist pile */
llist *init_pile() {
    return llist_create();
}

Player *setup_player(int Nplayers, int *deck) {
    Player *players = init_Nplayers(Nplayers);
    deal_card_for_player(Nplayers, deck, players);
    return players;
}


/* returns 1 if finished, 0 not finished*/
int finished(Player *players, int Nplayers) {
    int i;
    for (i = 0; i < Nplayers; i++) {
        if (llist_len(players[i].cards) == DECK_LEN) return 1;
    }
    return 0;
}


/*  if the card_val is a penalty:
 * return non-zero number(how many cards should next player pays) */
int is_penalty_cards(int card_val) {
    switch (card_val) {
        case 14:
            return 4;
        case 13:
            return 3;
        case 12:
            return 2;
        case 11:
            return 1;
        default:
            return 0;
    }
}

void print_turn(Player *players, llist pile, int Nplayers, int currPlayerId, int turnNum) {
    printf("Turn %d\n", turnNum);
    printf("Pile: ");
    llist_print(&pile);

    int i;
    for (i = 0; i < Nplayers; i++) {
        if (i == currPlayerId) {
            printf("*");
        } else {
            printf(" ");
        }
        printf("   %d: ", players[i].id);
        llist_print(players[i].cards);
    }
}

int single_turn(Player *player, llist *pile) {
    int p_card_val = llist_remove_front(player->cards);
    llist_add_rear(p_card_val, pile);

    // determine whether the next player should pay penalty cards or not
    int next_penalty_cards_num = is_penalty_cards(p_card_val);

    // if the next player should pay for penalty card, return how many cards the next player should pay
    if (next_penalty_cards_num) return next_penalty_cards_num;
    return 0;
}

int penalty_turn(Player *player, llist *pile, int penalty_cards_num) {
    int i;

    // get player's hand card number
    int player_hand_cards_num = llist_len(player->cards);

    // if the player's hand cards number less than penalty cards, then the player only need to pay all the hand cards
    if (player_hand_cards_num < penalty_cards_num) penalty_cards_num = player_hand_cards_num;

    for (i = 0; i < penalty_cards_num; i++) {
        int p_card_val = llist_remove_front(player->cards);

        int next_penalty_cards_num = is_penalty_cards(p_card_val);
        llist_add_rear(p_card_val, pile);
        if (next_penalty_cards_num) return next_penalty_cards_num;
    }
    return 0;
}


/* return the index of the previous player */
int get_previous_player_id(int id, int Nplayers, Player *players) {
    int index;
    if (id == 0) {
        index = Nplayers - 1;
    } else {
        index = id - 1;
    }

    while (1) {
        if (llist_len(players[index].cards) != 0) return index;
        index--;
        if (index == -1) index = Nplayers - 1;
    }
}


/* player get bonus cards, and set the pile to be empty. */
void get_bonus_cards(Player *player, llist *pile) {
    llist *ptr = pile;
    llist_append(player->cards, ptr);
    llist *new_pile = llist_create();
    *pile = *new_pile;
}


int beggar(int Nplayers, int *deck, int talkative) {
    // set up
    shuffle_deck(deck);
    Player *players = setup_player(Nplayers, deck);
    llist *pile = init_pile();

    int i;
    int turnCounter = 1;

    int next_pcards_num = 0;
    while (1) {
        for (i = 0; i < Nplayers; i++) {


            if (llist_len(players[i].cards) == 0) continue;

            if (talkative) print_turn(players, *pile, Nplayers, i, turnCounter);

            if (finished(players, Nplayers)) {

                /*
                for (i = 0; i < Nplayers; i++) {
                    llist_free(players[i].cards);
                }
                 */

                remove_players(players, Nplayers);
                llist_free(pile);

                return turnCounter;
            }

            // if the next penalty card is zero, then go to single turn without paying penalty cards
            if (next_pcards_num == 0) {
                next_pcards_num = single_turn(&players[i], pile);
            } else {
                next_pcards_num = penalty_turn(&players[i], pile, next_pcards_num);
                if (next_pcards_num == 0) {
                    get_bonus_cards(&players[get_previous_player_id(i, Nplayers, players)], pile);
                }
            }
            turnCounter++;
        }
    }
}
