#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct node {
    char info;
    struct node *link;
};

struct node *top = NULL;

void push(char x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("\nStack Overflow");
        exit(1);
    }
    temp->info = x;
    temp->link = top;
    top = temp;
}

char pop() {
    if(top == NULL) {
        printf("\nStack Underflow");
        exit(1);
    }
    struct node* temp = top;
    char item = temp->info;
    top = top->link;
    free(temp);
    return item;
}

char peek() {
    if(top == NULL) {
        printf("\nStack Underflow");
        exit(1);
    }
    return top->info;
}

void display() {
    struct node* temp = top;
    printf("\n\n     TOP");
    if(top == NULL) {
        printf("\n|-----------|\n|    NULL   |\n|-----------|");
        return;
    }
    printf("\n\n|-----------|\n|%11u|\n|-----------|", top);
    printf("\n        |\n        |");
    while(temp != NULL) {
        printf("     |--------------|         ");
        temp = temp->link;
    }
    temp = top;
    printf("\n        ----->");
    while(temp->link!= NULL) {
        printf("|%2c |%10u|------------->", temp->info, temp->link); 
        temp = temp->link;
    }printf("|%2c |   NULL   |", temp->info);
    temp = top;
    printf("\n");
    while(temp != NULL) {
        printf("              |--------------|");
        temp = temp->link;
    }
}

int main() {
    char ex[MAX];
    printf("Name : Kedron Lucas\n");
    printf("Roll No : 23B-CO-031\n");
    printf("\nEnter the expression: ");
    scanf("%s", ex);
    if(strlen(ex) >= MAX) {
        printf("\nExpression is too long");
        return 1;
    }

    for(int i = 0; i < strlen(ex); i++) {
        switch(ex[i]) {
            case '(':
            case '{':
            case '[':
                push(ex[i]);
                display();
                break;
            case ')':
                if(top != NULL && peek() == '(') {
                    pop();
                    display();
                } else {
                    printf("\nExpression is not balanced");
                    return 1;
                }
                break;
            case '}':
                if(top != NULL && peek() == '{') {
                    pop();
                    display();
                } else {
                    printf("\nExpression is not balanced");
                    return 1;
                }
                break;
            case ']':
                if(top != NULL && peek() == '[') {
                    pop();
                    display();
                } else {
                    printf("\nExpression is not balanced");
                    return 1;
                }
                break;
        }
    }

    if(top == NULL)
        printf("\nExpression is balanced");
    else
        printf("\nExpression is not balanced");

    return 0;
}
