#include <stdlib.h>
#include <stdio.h>

#define PACK_LEN 13
#define SHUFFLE_TIMES 11

#include "riffle.h"
#include "player.h"

/*
 * deal cards for players
 *
 * int Nplayers: number of players
 * int *deck: cards to be dealed
 * Player *players: array of players
 */
void deal_card_for_player(int Nplayers, int *deck, Player *players);

/* 
 * automatically generate an integer deck[2, 3 ..., 14] * 4 , after the procedure, the deck will become a standard 52 deck.
 */
void init_deck_number(int *deck);

/*
 * shuffle the deck, using macro paras.
 */
void shuffle_deck(int *deck);


/*
 * init and return a shuffled deck array 
 */
int *init_deck_array();

/* init and return a llist pile */
llist *init_pile();

/*
 * set up players, after this procedure, an array of players will be created
 * and cards from deck will be dealt for players.
 *
 * int Nplayers: number of players
 * int* deck: deck for dealing cards for players
 *
 * return: an array of players with dealt cards.
 */
Player *setup_player(int Nplayers, int *deck);

/* 
 * determine whether the card_val is penalty value or not.
 * if the card_val is a penalty, then return non-zero number(how many cards should next player pays) 
 */
int is_penalty_cards(int card_val);

/* 
 * print out a single turn
 *
 * Player *players: array of players
 * llist: pile
 * int Nplayers: number of players
 * int currPlayerId: the id of the current player
 * int turnNum: the number of the current turn
 */
void print_turn(Player *players, llist pile, int Nplayers, int currPlayerId, int turnNum);

int single_turn(Player *player, llist *pile);

int penalty_turn(Player *player, llist *pile, int penalty_cards_num);

/* return the index of the previous player */
int get_previous_player_id(int id, int Nplayers, Player *players);

/* player get bonus cards, and set the pile to be empty. */
void get_bonus_cards(Player *player, llist *pile);

/* 
 * determine whether the game has finished or not
 *
 * Player *players : a pointer to an array of players in the game
 * int Nplayers: number of players
 *
 * returns true (non-zero) if one player has all the cards and the others have none 
 */
int finished(Player *players, int Nplayers);

/* 
 * play a single game of beggar-your-neighbour with Nplayers using the shuffled deck of cards. 
 *
 * int Nplayers: number of players
 * int *deck: the deck
 * int talktive: If the argument talkative is not zero, your function should print details of what it is doing, similar to the excerpt above. 
 *
 *  return the number of turns that it takes for the game to finish.
 */
int beggar(int Nplayers, int *deck, int talkative);
