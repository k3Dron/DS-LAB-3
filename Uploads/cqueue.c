#include<stdio.h>
#include<stdlib.h>

#define MAX 4

int front;
int rear;
int queue_arr[MAX];

void enqueue(int item);
void dequeue();
int isFull();
int isEmpty();
int peek();
void display();

void enqueue(int item){
    if(isFull()){
        printf("\n\nInsert(%d)",item);
        display();
        printf("\nQueue Overflow");
        return;
        }
    if(front==-1)
    front=0;
    rear=rear+1;
    queue_arr[rear]=item;
    printf("\n\nInsert(%d)",item);
    display();
}

void dequeue(){
    if(isEmpty()){
        printf("\n\nDelete()");
        display();
        printf("\nQueue Underflow");
        return;
        }
    int item=queue_arr[front];
    front=front+1;
    printf("\n\nDelete()");
    display();
    printf("\nItem = %d",item);
}
void cenqueue(int item){
    if(cisFull()){
        printf("\n\nInsert(%d)",item);
        cdisplay();
        printf("\nCircular Queue Overflow");
        return;
        }
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
    }else{
        rear=(rear+1)%MAX;
    }
    queue_arr[rear]=item;
    printf("\n\nInsert(%d)",item);
    cdisplay();
}

void cdequeue(){
    if(cisEmpty()){
        printf("\n\nDelete()");
        cdisplay();
        printf("\nCircular Queue Underflow");
        return;
        }
    int item=queue_arr[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    if(front==MAX-1)
        front=0;
    else
        front++;
    printf("\n\nDelete()");
    cdisplay();
    printf("\nItem = %d",item);
}

int isFull(){
    if(rear==MAX-1)
        return 1;
    else return 0;
}

int isEmpty(){
    if(front==-1||front==rear+1)
        return 1;
    else return 0;
}
int cisFull(){
    return ((front==rear+1)||(front==0 && rear==MAX-1));
}
int cisEmpty(){
    return (front==-1);
}

int peek(){
    if(isEmpty()){
        printf("\nQueue Underflow");
        exit(1);
        }
    return queue_arr[front];
}

void display(){
    if(MAX==0){
        printf("\nArray size is too small");
        return;
    }
    printf("\n          Front:%d Rear=%d",front,rear);
    printf("\n");
    printf("          ");
    for(int i=0;i<MAX;i++){
        printf("|---");
    }printf("|\n");
    printf("Queue_arr ");
    for(int i=0;i<MAX;i++){
        printf("|");
        if(i>=front && i<=rear){
            printf("%3d",queue_arr[i]);
        }
        else printf("   ");
    }printf("|\n");
     printf("          ");
     for(int i=0;i<MAX;i++){
        printf("|---");
    }printf("|\n");
     printf("          ");
    for(int i=0;i<MAX;i++){
        printf(" [%d]",i);
    }
}
void cdisplay(){
    if(MAX==0){
        printf("\nArray size is too small");
        return;
    }
    if(front<=rear){
        printf("\n           Front:%d Rear=%d",front,rear);
        printf("\n");
        printf("           ");
        for(int i=0;i<MAX;i++){
            printf("|---");
        }printf("|\n");
        printf("Cqueue_arr ");
        for(int i=0;i<MAX;i++){
            printf("|");
            if(i>=front && i<=rear){
                printf("%3d",queue_arr[i]);
            }
            else printf("   ");
        }printf("|\n");
        printf("           ");
        for(int i=0;i<MAX;i++){
            printf("|---");
        }printf("|\n");
        printf("           ");
        for(int i=0;i<MAX;i++){
            printf(" [%d]",i);
        }
    }
    else{
        printf("\n           Front:%d Rear=%d",front,rear);
        printf("\n");
        printf("           ");
        for(int i=0;i<MAX;i++){
            printf("|---");
        }printf("|\n");
        printf("Cqueue_arr ");
        for(int i=0;i<MAX;i++){
            printf("|");
            if(i<=rear){
                printf("%3d",queue_arr[i]);
            }
            else if(i>=front){
                printf("%3d",queue_arr[i]);
            }
            else printf("   ");
        }printf("|\n");
        printf("           ");
        for(int i=0;i<MAX;i++){
            printf("|---");
        }printf("|\n");
        printf("           ");
        for(int i=0;i<MAX;i++){
            printf(" [%d]",i);
        }
    }
}
        
int main(){
    printf("Name : Kedron Lucas\n");
    printf("Roll No : 23B-CO-031\n");
    printf("\n\nQUEUE:");
    front=-1;
    rear=-1;
    display();
    enqueue(12);
    enqueue(43);
    enqueue(100);
    enqueue(36);
    enqueue(100);
    dequeue();
    dequeue();
    dequeue();
    enqueue(27);
    dequeue();    
    printf("\n\nCIRCULAR QUEUE:");
    front=-1;
    rear=-1;
    cdisplay();
    cdequeue();
    cenqueue(66);
    cenqueue(86);
    cenqueue(4);
    cenqueue(68);
    cdequeue();
    cdequeue();
    cenqueue(54);
    cenqueue(90);
    cenqueue(6);
    cdequeue();
    return 0;
    }

