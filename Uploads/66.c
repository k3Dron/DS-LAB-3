#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
#define MAX 20

int stack_arr[MAX];
float fstack[MAX];
int top = -1;
int ftop=-1;
char postfix[30];
char infix[30];

void push(int x);
void fpush(float x);
int isFull();
int isEmpty();
int pop();
float fpop();
int whitespace(char symbol);
int in_stack_priority(char symbol);
int in_sym_priority(char symbol);
void infix_to_postfix();
void display();
long int eval_post();

void push(int x) {
    if (isFull()) {
        printf("\nStack Overflow");
        return;
    }
    top = top + 1;
    stack_arr[top] = x;
}

int pop() {
    return stack_arr[top--];
}
void fpush(float x) {
    if (isFull()) {
        printf("\nStack Overflow");
        return;
    }
    ftop = ftop + 1;
    fstack[ftop] = x;
}

float fpop() {
    return fstack[ftop--];
}

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack_arr[i]);
    }
}
void cdisplay() {
    for (int i = top; i >= 0; i--) {
        printf("%c ", stack_arr[i]);
    }
}
void fdisplay() {
    for (int i = ftop; i >= 0; i--) {
        printf("%f ", fstack[i]);
    }
}

int whitespace(char symbol) {
    return symbol == ' ' || symbol == '\t';
}

int in_stack_priority(char symbol) {
    switch (symbol) {
        case '+':
        case '-': return 1;
        case '/':
        case '*':
        case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int in_sym_priority(char symbol) {
    switch (symbol) {
        case '+':
        case '-': return 1;
        case '/':
        case '*':
        case '%': return 2;
        case '^': return 4;
        default: return 0;
    }
}

void infix_to_postfix() {
    int i, p = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        printf("\n%c\t", symbol);
        if (!whitespace(symbol)) {
            switch (symbol) {
                case '(': 
                    push(symbol);
                    break;
                case ')': 
                    while ((next = pop()) != '(') {
                        postfix[p++] = next;
                    }
                    break;
                case '+':
                case '-':
                case '/':
                case '*':
                case '%':
                case '^': 
                    while ((top != -1) && (in_stack_priority(stack_arr[top]) >= in_sym_priority(symbol))) {
                        postfix[p++] = pop();
                    }
                    push(symbol);
                    break;
                default: 
                    postfix[p++] = symbol;
            }
        }
        cdisplay();
        printf("\t%s", postfix);
    }
    while (!isEmpty()) {
        postfix[p++] = pop();
    }
    postfix[p] = '\0';
    printf("\n \t");
    cdisplay();
    printf("\t%s", postfix);
}

long int eval_post() {
    long int a, b, temp;float c, d, x;
    int i;
    printf("\nSymbol\tStack\tFStack");
    for (i = 0; i < strlen(postfix); i++) {
        printf("\n%c\t", postfix[i]);
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0');fpush(postfix[i]-'0');
        } else {
            a = pop(); c=fpop();
            b = pop(); d=fpop();
            switch (postfix[i]) {
                case '+': temp = b + a;x=c+d;
                 break;
                case '-': temp = b - a; x=d-c;
                break;
                case '*': temp = b * a; x=d*c;
                break;
                case '/': temp = b / a; x=d/c;
                break;
                case '%': temp = b % a; break;
                case '^': temp = (int)pow(b, a);x=pow(d, c); break;
                default: printf("\nInvalid operator encountered."); exit(1);
            }
            push(temp); fpush(x);
        }
        display();printf("\t");fdisplay();
    }
    return pop();
}

int main() {
    printf("Name : Kedron Lucas\n");
    printf("Roll No : 23B-CO-031\n");
    printf("\nEnter the infix expression to convert to postfix: ");
    scanf("%s", infix);
    printf("Symbol\tStack\tPostfix");
    infix_to_postfix();
    printf("\nThe postfix expression is: ");
    puts(postfix);
    printf("\nEnter postfix expression with values: ");
    scanf("%s", postfix);
    long int r = eval_post();
    float f= fpop();
    printf("\nThe result in int is: %ld\nThe result in float is: %f", r,f);
    return 0;
}




