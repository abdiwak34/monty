#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1024

typedef struct {
	int stack[MAX_STACK_SIZE];
	int top;
} Stack;
void pall(const Stack *stack);

