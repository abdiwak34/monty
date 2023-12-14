#include "monty.h"

void push(Stack *stack, int value) {
    if (stack->top == MAX_STACK_SIZE) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    stack->stack[stack->top++] = value;
}
