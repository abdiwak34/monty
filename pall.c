#include "monty.h"

void pall(const Stack *stack) {
    int i;
    for (i = stack->top - 1; i >= 0; i--) {
        printf("%d\n", stack->stack[i]);
    }
}
