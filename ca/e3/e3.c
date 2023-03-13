#include <stdlib.h>
#include <stdio.h>

#define DECK_LEN 52

#include "shuffle.c"
#include "player.c"


/* that returns true (non-zero) if one player has all the cards and the others have none */
int finished(Player *players, int Nplayers);

/* play a single game of beggar-your-neighbour with Nplayers using the shuffled deck of cards. If the argument talkative
is not zero, your function should print details of what it is doing, similar to the excerpt above. Your
function should return the number of turns that it takes for the game to finish.*/
int beggar(int Nplayers, int *deck, int talkative);



/*
void deal_card_for_player(int Nplayers, int *deck, Player *players) {
    int player_handcard_number = 52 / Nplayers;
    int i;
    int player_size = get_player_size();
    for (i = 0; i < player_handcard_number * Nplayers; i++) {
        llist_print((players + (i % Nplayers) * player_size)->cards, numprint);
        printf("%d ", deck + i);
        // llist_add_rear((deck + i * 4), (players + (i % Nplayers) * player_size)->cards);
    }
}
 */


/* automatically generate an integer deck[2, 3 ..., 14] * 4 */
void init_deck(int *deck) {
    int i;
for (i = 0; i < 52; i++)
        // if ((i % 14) == 0) continue;
        *deck++ = (i % 13) + 2;


}

void shuffle_deck(int *deck) {
    riffle(deck, 52, 4, 11);
}

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


int main() {
    int deck[52];
    init_deck(deck);
    printIntDeck(deck, 52);

    printf("\nshuffle deck\n");
    shuffle_deck(deck);
    printIntDeck(deck, 52);

    // printf("\ndeal cards for players\n");
    // deal_card_for_player(4, deck, )

    // test create a llist using array
    printf("\ntest create a llist using array\n");
    llist deck_llist = create_llist_from_array(deck, 52);
    llist_print(deck_llist, numprint);

    // test create a player
    printf("\ntest create a player\n");
    Player *player_test = create_single_player(1, deck_llist);
    // test print player
    print_single_player(player_test);

    // test init_player_cards_from_deck
    printf("\ntest init_player_cards_from_deck\n");
    int *player1_cards = init_player_cards_from_deck(1, deck, 17);
    printIntDeck(player1_cards, 17);

    // test create_players
    printf("\ntest create_players\n");
    Player *players = create_Nplayers(3, deck);
    print_players(players, 3);

    // test get_player_by_id
    printf("get_player_by_id\n");
    Player *player1 = get_player_by_id(1, players);
    print_single_player(player1);

    // test init pile
    printf("\ntest init pile\n");
    llist pile_llist = init_pile(3, deck);
    llist_print(pile_llist, numprint);



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



}