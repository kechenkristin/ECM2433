#include <stdio.h>                                                                
#include <string.h>
#include <stdlib.h>

/* Struct for a Node in stack */
struct Node {
	void *data;
	struct Node *next;
};

/* "Stack" is a pointer */
typedef struct Node *Stack;


struct PM {
	int start;
	int end;
	char who[30];
	char party[41];
};



/* Create a new (empty) list */
Stack stackNew(void) { return NULL; }

/* Add a string to an existing stack. */
Stack push(Stack stack, struct PM *pm) {
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));
	node->data = (struct PM*) malloc(sizeof(struct PM)); 
	node->data = pm;
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
		struct PM *pm = (struct PM*)stack->data;
		printf("%4d - %4d\t%s\t%s\n", pm->start, pm->end, pm->who, pm->party);
		stack = stack->next;
	}   
}

void readFile(char* fileName) {
	FILE* filePointer;
	int bufferLength = 255;
	char buffer[bufferLength]; /* not ISO 90 compatible */

	filePointer = fopen(fileName, "r");

	while(fgets(buffer, bufferLength, filePointer)) {
		printf("%s\n", buffer);
	}

	fclose(filePointer);
}


/*
void constructStruct(char* line) {
	char s[] = " -	";

	char* token = strtok(line, s);

	while( token != NULL ) {
		printf( " %s\n", token );
		token = strtok(NULL, s);
	}
}
*/




int main() {
	int start, end;
	char who[31], party[41];

	/*scanf("%4d - %4d\t%30[^\t]\t%40[^\n]\n", &start, &end, who, party); */

	struct PM demo;
	demo.start = 1868;
	demo.end = 1868;
	strcpy(demo.who, "Hello World");
	strcpy(demo.party, "Conservative");

	Stack s = stackNew();
	s = push(s, &demo);
	printStack(s);

	/* readFile("pm.txt"); */

	char str[] = "1955 - 1957	Anthony Eden	Conservative";
	constructStruct(str);
}
