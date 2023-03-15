/* llist.h
 * Generic Linked List
 */
/* llist.c
 * Generic Linked List implementation
 */

/*https://gist.github.com/meylingtaing/11018042#file-llist-h-L26*/

#include <stdlib.h>
#include <stdio.h>

#define EMPTY_VALUE -1

struct node {
    int data;
    struct node *next;
};

typedef struct node* llist;


llist* llist_create() {
    struct node *new_node;

    llist *new_list = (llist *) malloc(sizeof(llist));
    *new_list = (struct node *) malloc(sizeof(struct node));

    new_node = *new_list;
    // empty data is -1
    new_node->data = EMPTY_VALUE;
    new_node->next = NULL;
    return new_list;
}


void llist_free(llist *list) {
    struct node *curr = *list;
    struct node *next;

    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(list);
}

// Returns 0 on failure
int llist_add_rear(int data, llist *list) {
    struct node *new_node;
    struct node *curr;
    struct node *prev = NULL;

    if (list == NULL || *list == NULL) {
        fprintf(stderr, "llist_add_inorder: list is null\n");
        return 0;
    }

    curr = *list;
    // if empty
    if (curr->data == EMPTY_VALUE) {
        curr->data = data;
        return 1;
    }

    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;

    // Find spot in linked list to insert new node
    while (curr != NULL && curr->data != NULL) {
        prev = curr;
        curr = curr->next;
    }
    new_node->next = curr;

    if (prev == NULL)
        *list = new_node;
    else
        prev->next = new_node;

    return 1;
}


int llist_remove_front(llist *list) {
    int popped_data;
    struct node *head = *list;

    if (list == NULL || head->data == NULL)
        return 0;

    popped_data = head->data;
    *list = head->next;

    free(head);

    return popped_data;
}

void llist_print(llist *list) {
    struct node *curr = *list;
    while (curr != NULL) {
        if (curr-> data == EMPTY_VALUE) {
            printf(" ");
        } else {
            printf("%d ", curr->data);
        }
        printf(" ");
        curr = curr->next;
    }
    putchar('\n');
}


/* create a llist from an integer array .*/
llist *create_llist_from_array(int *numbers, int len) {
    llist *my_list = llist_create();

    int i;
    for (i = 0; i < len; i++)
        llist_add_rear(*(numbers + i), my_list);

    return my_list;
}

/* returns the length of the list. */
int llist_len(llist *list) {
    int len = 0;

    struct node *curr = *list;

    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}



