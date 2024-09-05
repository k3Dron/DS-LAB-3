#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct node {
    char info;
    struct node* link;
};

struct node* top = NULL;
struct node* front = NULL;
struct node* rear = NULL;

void qdisplay() {
    struct node* temp = front;
    printf("\n\n     FRONT");
    if(front == NULL) {
        printf("         REAR");
        printf("\n|-----------|  |-----------|\n|    NULL   |  |    NULL   |\n|-----------|  |-----------|");
        return;
    }while(temp->link!=NULL){
        printf("                              ");
        temp = temp->link;
    }printf("                       REAR");
    //printf("\n\n|-----------|\n|%11u|\n|-----------|", front);
    printf("\n\n|-----------|");
    temp=front;
    while(temp ->link!= NULL) {
        printf("                              ");
        temp = temp->link;
    }printf("                 |-----------|\n");
    printf("|%11u|",front);
    temp=front;
    while(temp->link!= NULL) {
        printf("                              ");
        temp = temp->link;
    }printf("                 |%11u|\n",rear);
    printf("|-----------|");
    temp=front;
    while(temp->link!= NULL) {
        printf("                              ");
        temp = temp->link;
    }printf("                 |-----------|");
    printf("\n        |     ");
    temp=front;
    while(temp->link!=NULL){
        printf("                              ");
        temp=temp->link;
    }
    printf("                    |\n        |     ");
    temp=front;
    while(temp->link!=NULL){
        printf("                              ");
        temp=temp->link;
    }printf("                    |\n        |");
    temp=front;
    while(temp->link!= NULL) {
        printf("     |--------------|         ");
        temp = temp->link;
    }printf("     |--------------|    |");
    temp = front;
    printf("\n        ----->");
    while(temp->link != NULL) {
        printf("|%2c |%10u|------------->", temp->info, temp->link); 
        temp = temp->link;
    }printf("|%2c |   NULL   |<----", temp->info); 
    temp = front;
    printf("\n");
    while(temp != NULL) {
        printf("              |--------------|");
        temp = temp->link;
    }
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
    while(temp->link != NULL) {
        printf("|%2c |%10u|------------->", temp->info, temp->link); 
        temp = temp->link;
    }
    printf("|%2c |   NULL   |", temp->info); 
    temp = top;
    printf("\n");
    while(temp != NULL) {
        printf("              |--------------|");
        temp = temp->link;
    }
}

void push(char item) {
    struct node* temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    temp->info = item;
    temp->link = top;
    top = temp;
    display();
}

char pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return CHAR_MIN;
    }

    char item = top->info; 
    struct node* p = top;
    top = top->link;
    free(p);
    display();
    return item;
}
void insert(char data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    temp->info = data;
    temp->link = NULL;
    if (front == NULL) {
        front = temp;
    } else {
        rear->link = temp;
    }
    rear = temp;
    qdisplay();
}

char delete() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return CHAR_MIN;
    }
    struct node* temp = front;
    char data = temp->info;
    front = front->link;
    free(temp);
    qdisplay();
    return data;
}
int palindrome(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        insert(str[i]);
        push(str[i]);
        i++;
    }
    while(top!=NULL && front!=NULL){
        char a=pop();
        char b=delete();
        if (a!=b){
            return 0;   
        }
    }
    if (top!=NULL && front!=NULL)
    {
        return 0;
    }

    return 1;
}
int main() {
    char str[100];
    printf("Name : Kedron Lucas\n");
    printf("Roll No : 23B-CO-031\n");
    printf("Enter the string to be checked :");
    scanf("%s", str);
    if (palindrome(str)) {
        printf("\n%s is a palindrome string\n", str);
    } else {
        printf("\n%s is not a palindrome string\n", str);
    }
    return 0;
}
