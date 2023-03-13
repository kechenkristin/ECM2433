/* llist.h
 * Generic Linked List
 */
/* llist.c
 * Generic Linked List implementation
 */

/*https://gist.github.com/meylingtaing/11018042#file-llist-h-L26*/

#include <stdlib.h>
#include <stdio.h>

#define COUNT  sizeof numbers / sizeof (int)
#define COUNT2 sizeof more_numbers / sizeof (int)

struct node {
    void *data;
    struct node *next;
};

typedef struct node *llist;

/* llist_create: Create a linked list */
llist *llist_create(void *data);

/* llist_free: Free a linked list */
void llist_free(llist *list);

/* llist_add_rear: Add to linked list to the rear */
int llist_add_rear(void *data, llist *list);

/* llist_add_front: Add to head of list */
void llist_add_front(llist *list, void *data);

/* llist_remove_front: remove and return head of linked list */
void *llist_remove_front(llist *list);

/* llist_print: print linked list */
void llist_print(llist *list, void (*print)(void *data));

llist *llist_create(void *new_data) {
    struct node *new_node;

    llist *new_list = (llist *) malloc(sizeof(llist));
    *new_list = (struct node *) malloc(sizeof(struct node));

    new_node = *new_list;
    new_node->data = new_data;
    new_node->next = NULL;
    return new_list;
}


/* create a llist from an integer array .*/
llist create_llist_from_array(int *numbers, int len) {
    llist *my_list = llist_create(NULL);

    int i;
    for (i = 0; i < len; i++) {
        llist_add_rear((void *) (numbers + i), my_list);
    }
    return my_list;
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
int llist_add_rear(void *data, llist *list) {
    struct node *new_node;
    struct node *curr;
    struct node *prev = NULL;

    if (list == NULL || *list == NULL) {
        fprintf(stderr, "llist_add_inorder: list is null\n");
        return 0;
    }

    curr = *list;
    if (curr->data == NULL) {
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

void llist_add_front(llist *list, void *data) {
    struct node *head;
    struct node *new_node;
    if (list == NULL || *list == NULL) {
        fprintf(stderr, "llist_add_inorder: list is null\n");
    }

    head = *list;

    // Head is empty node
    if (head->data == NULL)
        head->data = data;

        // Head is not empty, add new node to front
    else {
        new_node = malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = head;
        *list = new_node;
    }
}

void *llist_remove_front(llist *list) {
    void *popped_data;
    struct node *head = *list;

    if (list == NULL || head->data == NULL)
        return NULL;

    popped_data = head->data;
    *list = head->next;

    free(head);

    return popped_data;
}

void llist_print(llist *list, void (*print)(void *)) {
    struct node *curr = *list;
    while (curr != NULL) {
        print(curr->data);
        printf(" ");
        curr = curr->next;
    }
    putchar('\n');
}

void numprint(void *num) {
    int *pnum = (int *) num;
    if (num == NULL)
        return;

    printf("%d", *pnum);
}



