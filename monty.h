typedef struct {
	int stack[MAX_STACK_SIZE];
	int top;
} Stack;
void push(Stack *stack, int value, int line_number);
void pall(const Stack *stack);

