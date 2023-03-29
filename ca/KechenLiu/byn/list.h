#include <stdlib.h>
#include <stdio.h>

#define EMPTY_VALUE -1

struct node {
    int data;
    struct node *next;
};

typedef struct node* llist;

/* creat an ampty llist, return a pointer to the llist. */
llist* llist_create();

/*
 * free the memory for a list
 *
 * llist *list: a pointer to the list to be freed
 */
void llist_free(llist *list);

/*
 * add an element to the rear of the list
 *
 * int data: element to be added
 * llist *list: the list to be added
 *
 * return 1 if sucesses, 0 failures
 */
int llist_add_rear(int data, llist *list);

/*
 * append another list to the rear of a list
 *
 * llist *formallist: the first list
 * llist *appendlist: the sencond list
 *
 * return 1 if sucesses, 0 failures
 */
int llist_append(llist *formallist, llist *appendlist);

/* copy every element of formal list into copy list, return a pointer to the copy list */
llist *llist_copy(llist *formallist);

/*
 * get the rear of a llist
 *
 * llist *list: the linked list
 *
 * return the rear element of the list
 */
int llist_get_rear(llist *list);

/*
 * remove the front element of the list
 *
 * llist *list: the linked list
 *
 * return the front element
 */
int llist_remove_front(llist *list);

/*
 * print the llist
 */
void llist_print(llist *list);

/*
 * create a llist from an integer array.
 *
 * int *numbers: array
 * int len: length of the array
 *
 * return: pointer of a llist
 */
llist *create_llist_from_array(int *numbers, int len);

/*
 * returns the length of the list.
 *
 * llist *list: the linked list
 *
 * return: the length of the array
 */
int llist_len(llist *list);

/*
 * whether the list is empty or not
 *
 * return 1 if it is empty, 0 not.
 */
int llist_is_empty(llist *list);
