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


/* read a .txt file line by line */
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

/* convert a string into an array of string
 * 1955 - 1957	Anthony Eden	Conservative
 * {"1955", "1957", "Anthony Eden", "Conservative"}
 */
char** stringToArr(char* line) {
	char s[] = "-	";

	char* token = strtok(line, s);

	int i = 0;
	char **array;
	int numOfItems = 4;
	array = malloc(numOfItems * sizeof(char*));

	while( token != NULL ) {
		array[i++] = token;
		token = strtok(NULL, s);
	}

	/*
	for (i = 0; i < numOfItems; i++) {
		printf("%s\n", array[i]);
	}
	*/
	return array;
}

/* convert an array of string into a struct */
struct PM* arrToStruct(char** arr) {
	struct PM *pm = (struct PM*) malloc(sizeof(struct PM));
	pm->start = atoi(arr[0]);
	pm->end = atoi(arr[1]);
	strcpy(pm->who, arr[2]);
	strcpy(pm->party, arr[3]);
	return pm;
}

/* push all the pms from fileName.txt */
Stack pushAllPM(char* fileName) {
	FILE* filePointer;
	int bufferLength = 255;
	cha toker buffer[bufferLength]; /* not ISO 90 compatible */

	filePointer = fopen(fileName, "r");

	Stack s = stackNew();

	while(fgets(buffer, bufferLength, filePointer)) {
		char** arr;
		arr = stringToArr(buffer);

		struct PM *pm;
		pm = arrToStruct(arr);

		s = push(s, pm);
	}

	fclose(filePointer);
	return s;
}

Stack popAllPM(Stack s) {
	while (s != NULL) {
		struct PM *pm = (struct PM*)s->data;
		printf("%4d - %4d\t%s\t%s\n", pm->start, pm->end, pm->who, pm->party);
		s = pop(s);
	}
	return s;
}


int main() {
	/*scanf("%4d - %4d\t%30[^\t]\t%40[^\n]\n", &start, &end, who, party); */

	/*
	struct PM demo;
	demo.start = 1868;
	demo.end = 1868;
	strcpy(demo.who, "Hello World");
	strcpy(demo.party, "Conservative");

	Stack s = stackNew();
	s = push(s, &demo);
	printStack(s);


	char str[] = "1955 - 1957	Anthony Eden	Conservative";
	char** arr;
	arr = stringToArr(str);

	struct PM *pm;
	pm = arrToStruct(arr);

	s = push(s, pm);
	printStack(s);
	*/

	Stack test = pushAllPM("pm.txt");
	/*
	printStack(test);
	*/
	test = popAllPM(test);
}
