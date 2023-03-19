#include <stdlib.h>
#include <stdio.h>

#define PLAYER_NUMBER 4
#define PACK_LEN 13
#define SHUFFLE_TIMES 11

#include "shuffle.c"
#include "player.c"


/* that returns true (non-zero) if one player has all the cards and the others have none */
int finished(Player *players, int Nplayers);

/* play a single game of beggar-your-neighbour with Nplayers using the shuffled deck of cards. If the argument talkative
is not zero, your function should print details of what it is doing, similar to the excerpt above. Your
function should return the number of turns that it takes for the game to finish.*/
int beggar(int Nplayers, int *deck, int talkative);


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

void remove_deck_array(int *deck) {
    free(deck);
}

// free!
/* init a llist from an integer array. */
llist *init_deck_llist(int *deck) {
    return create_llist_from_array(deck, DECK_LEN);
}

// free!
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
    }
    return 0;
}

void print_turn(Player *players, llist pile, int Nplayers, int currPlayerId, int turnNum) {
    printf("Turn %d\n", turnNum);
    printf("Pile: ");
    llist_print(pile);

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
    int next_penalty_cards_num = is_penalty_cards(p_card_val);

    if (next_penalty_cards_num) return next_penalty_cards_num;
    return 0;
}

int penalty_turn(Player *player, llist *pile, int penalty_cards_num) {
    int i;

    int player_hand_cards_num = llist_len(player->cards);
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

int beggar_v1(Player *players, int Nplayers, llist *pile) {
    int i;
    int turnCounter = 1;

    int next_pcards_num = 0;
    for (i = 0; i < Nplayers; i++) {
        print_turn(players, pile, Nplayers, i, turnCounter);
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


int beggar_v2(Player *players, int Nplayers, llist *pile) {
    int i;
    int turnCounter = 1;

    int next_pcards_num = 0;
    while (1) {
        for (i = 0; i < Nplayers; i++) {
            print_turn(players, pile, Nplayers, i, turnCounter);
            if (finished(players, Nplayers)) return turnCounter;
            if (llist_len(players[i].cards) == 0) continue;

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

int beggar_v3(int Nplayers, int *deck, int talkative) {
    // set up
    shuffle_deck(deck);
    Player *players = setup_player(Nplayers, deck);
    llist pile = init_pile();

    int i;
    int turnCounter = 1;

    int next_pcards_num = 0;
    while (1) {
        for (i = 0; i < Nplayers; i++) {


            if (llist_len(players[i].cards) == 0) continue;

            if (talkative) print_turn(players, pile, Nplayers, i, turnCounter);

            if (finished(players, Nplayers)) {
                remove_players(players, Nplayers);
                llist_free(pile);
                return turnCounter;
            }

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

llist *no_penalty_turn(Player *player, llist *pile) {
    int p_card_val = llist_remove_front(player->cards);
    llist_add_rear(p_card_val, pile);
    return NULL;
}

llist *penalty_turn2(Player *player, llist *pile, int penalty_cards_num) {
    int i;


    int player_hand_cards_num = llist_len(player->cards);
    if (player_hand_cards_num < penalty_cards_num) penalty_cards_num = player_hand_cards_num;

    for (i = 0; i < penalty_cards_num; i++) {
        int p_card_val = llist_remove_front(player->cards);

        llist_add_rear(p_card_val, pile);

        int next_penalty_cards_num = is_penalty_cards(p_card_val);
        if (next_penalty_cards_num) return NULL;
    }


    llist *new_pile = llist_create();
    llist *ptr = llist_copy(pile);
    *pile = *new_pile;
    return ptr;
}


llist *take_turn(Player *player, llist *pile) {
    int pile_val = llist_get_rear(pile);
    int penalty_cards_num = is_penalty_cards(pile_val);

    if (penalty_cards_num) {
        llist *ret = penalty_turn2(player, pile, penalty_cards_num);
        return ret;
    } else {
        llist *ret = no_penalty_turn(player, pile);
        return ret;
    }
}

int beggar_v4(int Nplayers, int *deck, int talkative) {
    // set up
    shuffle_deck(deck);
    Player *players = setup_player(Nplayers, deck);
    llist pile = init_pile();

    int i;
    int turnCounter = 1;

    llist *reward;
    while (1) {
        for (i = 0; i < Nplayers; i++) {

            if (llist_len(players[i].cards) == 0) continue;

            if (talkative) print_turn(players, pile, Nplayers, i, turnCounter);

            if (finished(players, Nplayers)) {
                remove_players(players, Nplayers);
                llist_free(pile);
                return turnCounter;
            }

            reward = take_turn(&players[i], pile);

            if (reward != NULL) {
                int previous_player_id = get_previous_player_id(i, Nplayers, players);
                llist_append(players[previous_player_id].cards, reward);
                // llist_print(players[previous_player_id].cards);
            }
            turnCounter++;
        }
    }
}


int main() {
    // printf("player size: %d", get_player_size());

    /*
    int deck[52];
    init_deck_number(deck);
    printIntDeck(deck, 52);

    printf("\nshuffle deck\n");
    shuffle_deck(deck);
    printIntDeck(deck, 52);

    // printf("\ndeal cards for players\n");
    // deal_card_for_player(4, deck, )

    // test create a llist using array
    printf("\ntest create a llist using array\n");
    llist deck_llist = create_llist_from_array(deck, DECK_LEN);

    // test copy list
    printf("test copy_llist\n");
    llist *copy_list_test = llist_copy(deck_llist);
    llist_print(copy_list_test);
    */

    int *deck_array = init_deck_array();
    beggar_v4(PLAYER_NUMBER, deck_array, 1);
    /*
    llist deck_llist = init_deck_llist(deck_array);
    llist_print(deck_llist);
     */

    /*
    // test list_len
    printf("test llist_len: %d\n", llist_len(deck_llist));

    // test create a player
    printf("\ntest create a player\n");
    Player *player_test = create_single_player(1, deck_llist);
    // test print player
    print_single_player(player_test);
*/

    // test init_player_cards_from_deck
    /*
    printf("\ntest init_player_cards_from_deck\n");
    int *player1_cards = init_player_cards_from_deck(1, deck, 17);
    printIntDeck(player1_cards, 17);
     */

    /*
    // test create_players
    printf("\ntest create_players\n");
    // Player *players = create_Nplayers(PLAYER_NUMBER, deck);
    Player *players = init_Nplayers(PLAYER_NUMBER);

    printf("create_players success\n");
    print_players(players, PLAYER_NUMBER);

    // test deal cards for players
    deal_card_for_player(PLAYER_NUMBER, deck_array, players);
    print_players(players, PLAYER_NUMBER);
     */

    /*
    // test setup_players
    printf("test set up players\n");
    Player *players = setup_player(PLAYER_NUMBER, deck_array);
    print_players(players, PLAYER_NUMBER);
     */

    /*
    // test is penalty card
    printf("%d\n", is_penalty_cards(14));
    // printf("%d\n", is_penalty_cards(13));
    // printf("%d\n", is_penalty_cards(9));
     */

    /*
    // test init pile
    printf("test init pile\n");
    llist pile = init_pile();
    llist_print(pile);
     */


    // beggar_v2(players, PLAYER_NUMBER, pile);

    // test llist append
    /*
    printf("test llist append\n");
    llist_append(pile, deck_llist);
    llist_print(pile);

    llist list1 = llist_create();
    llist_add_rear(1, list1);
    llist_add_rear(2, list1);
    llist list2 = llist_create();
    llist_add_rear(3, list2);
    llist_add_rear(4, list2);
    llist_append(list1, list2);
    llist_print(list1);
     */

    /*
    // test print_turn
    printf("test print turn\n");
    print_turn(players, pile, PLAYER_NUMBER, 0, 0);


    // test single turn
    printf("test single turn\n");
    int p_val = single_turn(&players[0], pile);
    print_turn(players, pile, PLAYER_NUMBER, 0, 0);


    // test penalty turn
    printf("test penalty turn\n");
    int p_val1 = penalty_turn(&players[1], pile, 3);
    print_turn(players, pile, PLAYER_NUMBER, 1, 1);

    int p_val2 = penalty_turn(&players[3], pile, 3);
    print_turn(players, pile, PLAYER_NUMBER, 3, 1);
    */

    // printf("\n%d", p_val2);
    /*
    // test get_player_by_id
    printf("get_player_by_id\n");
    Player *player0 = get_player_by_id(0, players);
    print_single_player(player0);
    printf("cards len: %d\n", llist_len(player0->cards));


    Player *player1 = get_player_by_id(1, players);
    print_single_player(player1);


    Player *player2 = get_player_by_id(2, players);
    print_single_player(player2);


    Player *player3 = get_player_by_id(3, players);
    print_single_player(player3);

    Player *player4 = get_player_by_id(4, players);
    print_single_player(player4);

    Player *player5 = get_player_by_id(5, players);
    print_single_player(player5);
     */




    // print_single_player(players);




    // test init pile
    /*
    printf("\ntest init pile\n");
    llist pile_llist = init_pile(PLAYER_NUMBER, deck);

    llist_print(pile_llist);

    // test remove player
    printf("\ntest remove player\n");
    remove_players(players);
    printf("sig test");
    print_players(players, PLAYER_NUMBER);
     */

    // printf("\ninit_player_hand_cards\n");
    // init_player_hand_cards(2, deck, 17);



    // test init_Nplayers
    /*
    printf("test create_players\n");
    Player* players1 = init_Nplayers(3);
    print_players_by_pointer(players1, 3);
     */

    // test deal cards for players
    /*
    printf("\nTest deal cards for players\n");
    deal_card_for_player(3, pile, players);
    print_players(players, 3);
     */

    /*
    // test remove players
    printf("\ntest remove players\n");
    remove_players(players, PLAYER_NUMBER);
     */



}
