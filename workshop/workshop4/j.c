#include <stdio.h>
#include <stdlib.h>


typedef struct stackStruct STACK;
typedef struct primeMinister PM;
struct stackStruct {
    void *data;
    STACK *nextNode;
};

struct primeMinister {
    int start;
    int end;
    char* who;
    char* party;
};


void printPM(PM pm){
    printf("%d,%d,%s,%s\n",pm.start , pm.end, pm.who, pm.party);
}

void printStandard(void* x){
    printf("%c", *(char *)x);
#include <stdio.h>                                                                                                            
#include <stdlib.h>


typedef struct stackStruct STACK;
typedef struct primeMinister PM; 
struct stackStruct {
    void *data;
    STACK *nextNode;
};

struct primeMinister {
    int start;
    int end;
    char* who;
    char* party;
};


void printPM(PM pm){
    printf("%d,%d,%s,%s\n",pm.start , pm.end, pm.who, pm.party);
}

void printStandard(void* x){ 
    printf("%c", *(char *)x);
}

STACK *newNode (void* info) {
    STACK *nNode = malloc(sizeof(STACK));
}

STACK *newNode (void* info) {
    STACK *nNode = malloc(sizeof(STACK));
    if (nNode != NULL) {
        nNode->data = (struct primeMinister*)info;
        nNode->nextNode = NULL;
    }
    return nNode;
}

PM* newPm(int start, int end, char* name, char* party){
    PM *pm = malloc(sizeof (PM));
    if (pm != NULL) {
        pm->start = start;
        pm->end = end;
        pm->who = name;
        pm->party = party;
    }
    return pm;
}

void push(STACK **stack, STACK* node){
    node->nextNode = *stack;
    *stack = node;

}

void* pop(STACK **stack){
    int success = *stack != NULL;
    void *value;

    if(success){
        STACK *p = *stack;
        *stack = (*stack)->nextNode;
        value = p->data;
        free(p);
        printPM(*(PM*)p->data);
    }

    return value;
}

FILE *openFile(){
    FILE *fp;
    fp = fopen("pm.txt","r");

    if (fp ==NULL){
        printf("Cannot open file for read access \n");
        return NULL;
    }
    return fp;
}


int main(){
    STACK *root = NULL;


    FILE *fp = openFile();

    int start, end;
    char* who = (char*)malloc(31);
    char* party = (char*)malloc(41);

    while (fscanf(fp, "%4d - %4d\t%30[^\t]\t%40[^\n]\n", &start, &end, who, party)){
        PM *pm = newPm(start,end,who,party);

        push(&root , newNode(pm));

        if (end == 2023){
            break;
        }

    }
    fclose(fp);
    free(who);
    free(party);

   printPM(*(PM*)pop(&root));

    return 0;
}



