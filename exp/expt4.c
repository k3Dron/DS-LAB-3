#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack_arr[MAX];
int top = -1;

void push(int item);
int pop();
int peek();
int isFull();
int isEmpty();
void display();

void push(int item) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack_arr[top] = item;
}

int pop() {
    int item;
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    item = stack_arr[top];
    top = top - 1;
    return item;
}

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

int peek() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[top];
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack_arr[i]);
    }
}

int main() {
    int choice, item;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display the top element\n");
        printf("4. Display all the stack elements\n");
        printf("5. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                printf("Popped item is: %d\n", item);
                break;
            case 3:
                printf("Item at the top is: %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
