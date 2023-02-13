#ifndef STACK_H
#define STACK_H
typedef struct stack {
	void *data;
	struct stack *next;
} stack;
