#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} node_t;



void print_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void add_end(node_t *head, int val) {
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}


int remove_front(node_t *head) {
    int retval = -1;
    node_t *next_node = NULL;

    if (head == NULL) {
        return -1;
    }

    next_node = (head)->next;
    retval = (head)->val;
    // free(head);
    head = next_node;

    return retval;
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}


int main() {
    node_t node;

    add_end(&node, 1);
    add_end(&node, 2);
    add_end(&node, 3);

    node_t* ptr = &node;
    node_t ** pptr = &ptr;
    int ret = pop(pptr);
    printf("ret: %d\n", ret);


    /*
    add_front(&node, 1);
    add_front(&node, 2);
    add_front(&node, 3);
     */

    print_list(&node);
}