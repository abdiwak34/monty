#include "monty.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    char *file_path = argv[1];
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    Stack stack;
    stack.top = 0;

    char line[256];
    int line_number = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;

        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Skip empty lines
        if (strlen(line) == 0) {
            continue;
        }

        char opcode[16];
        int argument;

        if (sscanf(line, "%15s %d", opcode, &argument) == 2) {
            if (strcmp(opcode, "push") == 0) {
                push(&stack, argument, line_number);
            } else {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(line, "pall") == 0) {
            pall(&stack);
        } else {
            fprintf(stderr, "L%d: invalid instruction: %s\n", line_number, line);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}
