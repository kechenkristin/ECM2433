#include <stdlib.h>
#include <stdio.h>

#define EMPTY_VALUE -1

struct node {
    int data;
    struct node *next;
};

typedef struct node* llist;

/* creat an ampty llist, return a pointer to the llist. */
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


/*
 * free the memory for a list
 *
 * llist *list: a pointer to the list to be freed
 */
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


/*
 * add an element to the rear of the list
 *
 * int data: element to be added
 * llist *list: the list to be added
 *
 * return 1 if sucesses, 0 failures
 */
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
    while (curr != NULL && curr->data != EMPTY_VALUE) {
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


/*
 * append another list to the rear of a list
 *
 * llist *formallist: the first list
 * llist *appendlist: the sencond list
 *
 * return 1 if sucesses, 0 failures
 */
int llist_append(llist *formallist, llist *appendlist) {
    struct node *curr;

    if (formallist == NULL || *formallist == NULL) {
        fprintf(stderr, "llist_append: list is null\n");
        return 0;
    }

    curr = *formallist;
    // if empty
    if (curr->data == EMPTY_VALUE) {
        *formallist = *appendlist;
        return 1;
    }

    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = *appendlist;
    return 1;
}


/* copy every element of formal list into copy list, return a pointer to the copy list */
llist *llist_copy(llist *formallist) {
    struct node *curr;

    if (formallist == NULL || *formallist == NULL) {
        fprintf(stderr, "llist_copy: list is null\n");
        return 0;
    }

    curr = *formallist;
    llist* copylist = llist_create();

    // if empty
    if (curr->data == EMPTY_VALUE) {
        return copylist;
    }

    while (curr->next != NULL) {
        llist_add_rear(curr->data, copylist);
        curr = curr->next;
    }
    return copylist;
}


/*
 * get the rear of a llist
 *
 * llist *list: the linked list
 *
 * return the rear element of the list
 */
int llist_get_rear(llist *list) {
    struct node *curr;

    if (list == NULL || *list == NULL) {
        fprintf(stderr, "llist_append: list is null\n");
        return 0;
    }

    curr = *list;
    // if empty
    if (curr->data == EMPTY_VALUE) {
        return -1;
    }

    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr->data;
}


/*
 * remove the front element of the list
 *
 * llist *list: the linked list
 *
 * return the front element
 */
int llist_remove_front(llist *list) {
    int popped_data;
    struct node *head = *list;

    if (list == NULL || head->data == EMPTY_VALUE)
        return 0;

    popped_data = head->data;
    *list = head->next;

    free(head);

    return popped_data;
}


/*
 * print the llist
 */
void llist_print(llist *list) {
    struct node *curr;
    curr = *list;
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


/*
 * create a llist from an integer array.
 *
 * int *numbers: array
 * int len: length of the array
 *
 * return: pointer of a llist
 */
llist *create_llist_from_array(int *numbers, int len) {
    llist *my_list = llist_create();

    int i;
    for (i = 0; i < len; i++)
        llist_add_rear(*(numbers + i), my_list);

    return my_list;
}


/*
 * returns the length of the list.
 *
 * llist *list: the linked list
 *
 * return: the length of the array
 */
int llist_len(llist *list) {
    int len = 0;

    struct node *curr = *list;

    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}


/*
 * whether the list is empty or not
 *
 * return 1 if it is empty, 0 not.
 */
int llist_is_empty(llist *list) {
    struct node *curr = *list;

    if (curr->data == -1) return 1;
    return 0;
}

