#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue_arr[MAX];
int rear = -1;
int front = -1;

void insert(int item);
int del();
int peek();
int isFull();
int isEmpty();
void display();

void insert(int item) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue_arr[rear] = item;
}

int del() {
    int item;
    if (isEmpty()) {
        printf("Queue Underflow\n");
        exit(1);
    }
    item = queue_arr[front];
    front = front + 1;
    return item;
}

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front == rear + 1;
}

int peek() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        exit(1);
    }
    return queue_arr[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is:\n");
    for (int i = front; i <= rear; i++)
        printf("%d\n", queue_arr[i]);
    printf("\n");
}

int main() {
    int choice, item;
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display the element at the front\n");
        printf("4. Display all the elements of the queue\n");
        printf("5. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Input the element for adding in queue: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                item = del();
                printf("Deleted item is: %d\n", item);
                break;
            case 3:
                printf("Item at the front is: %d\n", peek());
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
