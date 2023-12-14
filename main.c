#include "monty.h"

int main(int argc, char *argv[]) {
    char line[256];
     char *file_path = argv[1];
    FILE *file = fopen(file_path, "r");
     Stack stack;
    stack.top = 0;
    int line_number = 0;
     char opcode[16];
        int argument;
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

   
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

   

    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;

        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) == 0) {
            continue;
        }

       

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
