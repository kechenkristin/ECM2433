#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};


typedef struct Node *List;


/* Create a new (empty) list */
List ListNew(void) { return NULL; }


/* add a string to an existing list at the beginning */
List list_add_front(List list, int val) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = val;
    node->next = list;
    return node;
}


/* add a string to an existing list at the rear */
List list_add_rear(List list, int val) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = val;
    struct Node *ptr;

    if (list == NULL) {
        list = node;
    } else {
        ptr = list;
        while (ptr -> next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = node;
    }
    return list;
}


List list_delete_front(List list) {
    struct Node *frontier = list;
    list = list->next;
    free(frontier);
    return list;
}


void printList(List list) {
    while (list != NULL) {
        printf("%d\n", list->value);
        list = list->next;
    }
}


int main() {

    /*
    List list = ListNew();
    list = list_add_beginning(list, 1);
    list = list_add_beginning(list, 2);
    list = list_add_beginning(list, 3);
    printList(list);
     */

    /*
    List list2 = ListNew();
    list2 = list_add_rear(list2, 1);
    list2 = list_add_rear(list2, 2);
    list2 = list_add_rear(list2, 3);
    list2 = list_add_rear(list2, 4);

    list2 = list_delete_front(list2);
    printList(list2);
     */

    List list3;
    list_add_front(&list3, 1);
    printList(list3);
}