#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
	void *data;
	struct Node *next;
};

/* "Stack" is a pointer */
typedef struct Node *Stack;

/* Create a new (empty) list */
Stack stackNew(void) { return NULL; }

/* Add a string to an existing stack. */
Stack push(Stack stack, char *string) {
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));
	node->data = (char*) malloc(strlen(string) + 1);
	strcpy(node->data, string);
	node->next = stack;
	return node;
}

/* Pop an item from stack */
Stack pop(Stack stack) {
	struct Node *frontier = stack;
	stack = stack->next;
	free(frontier);
	return stack;
}


void printStack(Stack stack) {
	while (stack != NULL) {
		printf("%s\n",(char*)stack->data);
		stack = stack->next;
	}
}

int main() {
	Stack demo = stackNew();
	printf("put Q\n");
	char* q = "Q";
	demo = push(demo, q);
	printStack(demo);

	printf("put C\n");
	char* c = "C";
	demo = push(demo, c);
	printStack(demo);

	printf("put A\n");
	char* a = "A";
	demo = push(demo, a);
	printStack(demo);

	printf("pop the front item(A)\n");
	demo = pop(demo);
	printStack(demo);

	return 0;
}
