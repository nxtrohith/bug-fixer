//Project Description: Bug Fixer for C language Code
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Include for malloc and free
#define BUFFER_SIZE 10000000  // Define buffer size for code reading

#define MAX_STACK_SIZE 1000

// Enhanced Stack structure with more flexibility
typedef struct {
    char items[MAX_STACK_SIZE];
    int line_numbers[MAX_STACK_SIZE];
    int top;
} Stack;

// Stack operations
void init_stack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char item, int line_number) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->top++;
        s->items[s->top] = item;
        s->line_numbers[s->top] = line_number;
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        return s->top--;
    }
    return -1;
}

// Bracket matching function
int check_brackets(const char *code) {
    Stack s;
    init_stack(&s);
    int line = 1;
    int error_found = 0;

    for (int i = 0; code[i] != '\0'; i++) {
        char c = code[i];
        
        // Track line numbers
        if (c == '\n') line++;

        // Opening brackets
        if (c == '(' || c == '{' || c == '[') {
            push(&s, c, line);
        } 
        // Closing brackets
        else if (c == ')' || c == '}' || c == ']') {
            // No opening bracket to match
            if (s.top == -1) {
                printf("Error: Unmatched closing '%c' at line %d\n", c, line);
                error_found = 1;
                break;
            }

            char last_open = s.items[s.top];
            int last_line = s.line_numbers[s.top];

            // Mismatched brackets
            if ((last_open == '(' && c != ')') || 
                (last_open == '{' && c != '}') || 
                (last_open == '[' && c != ']')) {
                printf("Error: Mismatched '%c' at line %d with '%c' at line %d\n", 
                       last_open, last_line, c, line);
                error_found = 1;
                break;
            }

            // Matched, so pop
            pop(&s);
        }
    }

    // Check for any unclosed brackets
    while (s.top != -1) {
        printf("Error: Unmatched opening '%c' at line %d\n", 
               s.items[s.top], s.line_numbers[s.top]);
        pop(&s);
        error_found = 1;
    }

    return !error_found;
}

static char code[10000000];

int main() {
    //this is the main function for our project: Bug Fixer for C language
    FILE *fp = fopen("testcase.txt", "r"); // Change "input.c" to your actual filename
    if (fp == NULL) {
        printf("Error: Could not open the file.\n");
        return 1;
    }

    size_t bytesRead = fread(code, sizeof(char), BUFFER_SIZE - 1, fp);
    code[bytesRead] = '\0'; // Null-terminate the string
    fclose(fp);

    printf("---Bug Fixer for C language Code---\n\n");
    printf("------ Original Code ------\n");
    printf("%s\n", code);  // Print to ensure it's read correctly
    printf("---------------------------\n\n");
    
    //Opeartions to be performed:
    //1. Check if the code is correct
    //2. If not, find the bugs
    //2.1 Bracket matching
    //2.2 Semicolon matching
    //2.3 Variable matching
    //2.4 Function matching
    //2.5 Type matching
    //2.6 Syntax matching
    //2.7 Logical matching
    //2.8 Memory matching
    //2.9 Pointer matching
    //2.10 File matching
    //3. Fix the bugs
    //4. Return the fixed code
    //5. Print the fixed code
    
    // Perform bracket checking
    if (check_brackets(code)) {
        printf("All brackets are correctly matched.\n");
    } else {
        printf("Bracket matching errors found.\n");
    }

    free(code);
    return 0;
}   
