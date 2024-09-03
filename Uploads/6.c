#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

int top = -1;
char infix[MAX], postfix[MAX], stack[MAX];
int eval_stack[MAX];

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == MAX;
}

void push(char c) {
    if (!is_full())
        stack[++top] = c;
    else
        printf("Stack Overflow\n");
}

char pop() {
    if (!is_empty())
        return stack[top--];
    else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

char peek() {
    if (is_empty()) {
        printf("Stack Underflow\n");
        return '\0';
    } else
        return stack[top];
}

int in_stack_priority(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
        case '{':
        case '[':
            return 0;
        default:
            return -1; // Invalid character
    }
}

void infix_to_postfix() {
    int p = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char symbol = infix[i];
        switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                while (peek() != '(') {
                    char c = pop();
                    postfix[p++] = c;
                }
                pop(); // Remove '('
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!is_empty() && in_stack_priority(symbol) <= in_stack_priority(peek())) {
                    char c = pop();
                    postfix[p++] = c;
                }
                push(symbol);
                break;
            default:
                postfix[p++] = symbol;
        }
    }
    while (!is_empty()) {
        char c = pop();
        postfix[p++] = c;
    }
    postfix[p] = '\0'; // Null-terminate the postfix expression
}

void push_eval(int value) {
    if (top < MAX - 1)
        eval_stack[++top] = value;
    else
        printf("Stack Overflow\n");
}

int pop_eval() {
    if (top >= 0)
        return eval_stack[top--];
    else {
        printf("Stack Underflow\n");
        return -1;
    }
}

void evaluate_postfix() {
    int i = 0;
    while (postfix[i] != '\0') {
        char symbol = postfix[i];
        if (isdigit(symbol)) {
            push_eval(symbol - '0');
        } else {
            int b = pop_eval();
            int a = pop_eval();
            switch (symbol) {
                case '+':
                    push_eval(a + b);
                    break;
                case '-':
                    push_eval(a - b);
                    break;
                case '*':
                    push_eval(a * b);
                    break;
                case '/':
                    push_eval(a / b);
                    break;
                case '^':
                    push_eval((int)pow(a, b));
                    break;
            }
        }
        i++;
    }
    printf("Result of postfix evaluation: %d\n", pop_eval());
}

int main() {
    printf("Enter the infix expression: ");
    gets(infix);
    infix_to_postfix();
    printf("Postfix expression: %s\n", postfix);
    evaluate_postfix();
    return 0;
}
