//queue
#include<stdio.h>
#define MAX 10;

int stack[10];
int front = -1;
int rear = -1;

int isEmpty() {
    if(front == -1) return 1;
    return 0;
}

int isFull() {
    if(front == 9 && rear == 9) return 1;
    return 0;
}

void enqueue(int item) {
    if(!isFull()) {
        if(isEmpty) 
        front = 0;
        stack[++rear] = item;
    }
}

int dequeue() {
    int r;
    if(!isEmpty) r = stack[front];
    if(!isFull()) {
    front++;
    }
    return r;
}

int peek() {
    return stack[front];
}

int main() {
    int i = -1;
    while(i != 0) {
        printf("Press 1 Enqueue\nPress 2 Dequeue\nPress 3 to SEEK\nPress 0 to EXIT\n");
        scanf("%d", i);
        switch(i) {
            case 1: printf("Enter the item to be inserted : ");
                    int j;
                    scanf("$d", &j);
                    enqueue(j);
                    break;
            case 2: int k = dequeue();
                    printf("item removedd is : %d", k);
                    break;
            case 3: int l = peek();
                    printf("item at the top is : %d", l);
                    break;
            default: printf("Invalid value entered. Code has been exited.");
        }
    }
    printf("All elements of queue : \n");
    printf("---------------------");
    for(int i = front; i <= rear; i++) {
        int j = stack[i];
        printf("|\t%d\t|", j);
    }
    printf("---------------------");
}
