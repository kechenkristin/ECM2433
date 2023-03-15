#include <stdlib.h>
#include <stdio.h>

#define PLAYER_NUMBER 6
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

int* init_deck_array() {
    int* deck_array = (int *) malloc(INTEGER_SIZE * DECK_LEN);
    init_deck_number(deck_array);
    shuffle_deck(deck_array);
    return deck_array;
}

void remove_deck_array(int *deck) {
    free(deck);
}

// free!
llist* init_deck_llist(int *deck) {
    return create_llist_from_array(deck, DECK_LEN);
}

int finished(Player *players, int Nplayers) {
    int i;
    for (i = 0; i < Nplayers; i++) {
        if (llist_len(players[i].cards) == DECK_LEN) return 1;
    }
    return 0;
}

void print_turn(Player *players, llist pile) {
    
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
     */

    int* deck_array = init_deck_array();
    llist deck_llist = init_deck_llist(deck_array);
    llist_print(deck_llist);

    // test list_len
    printf("test llist_len: %d\n", llist_len(deck_llist));

    // test create a player

    printf("\ntest create a player\n");
    Player *player_test = create_single_player(1, deck_llist);
    // test print player
    print_single_player(player_test);


    // test init_player_cards_from_deck
    /*
    printf("\ntest init_player_cards_from_deck\n");
    int *player1_cards = init_player_cards_from_deck(1, deck, 17);
    printIntDeck(player1_cards, 17);
     */

    // test create_players

    printf("\ntest create_players\n");
    // Player *players = create_Nplayers(PLAYER_NUMBER, deck);
    Player *players = init_Nplayers(PLAYER_NUMBER);

    printf("create_players success\n");
    print_players(players, PLAYER_NUMBER);

    // test deal cards for players
    deal_card_for_player(PLAYER_NUMBER, deck_array, players);
    print_players(players, PLAYER_NUMBER);

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


    // test remove players
    printf("\ntest remove players\n");
    remove_players(players, PLAYER_NUMBER);

}
