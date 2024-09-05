#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* prev;
    struct node* next;
};
struct node* addatbeg(struct node* start, int data){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=start;
    temp->prev=NULL;
    if(start!=NULL)
        start->prev=temp;
    start=temp;
    return start;
}
struct node* addatend(struct node* start, int data){
    struct node* temp, *p=start;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=NULL;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
    temp->prev=p;
    return start;
}
struct node* createlist(struct node* start){
    int i, n, data;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    if(n==0)
        return start;
    printf("\nEnter the data for node 1: ");
    scanf("%d",&data);
    start=addatbeg(start, data);
    for(i=2;i<=n;i++){
        printf("\nEnter the data for node %d: ",i);
        scanf("%d",&data);
        start=addatend(start, data);
    }
    return start;
}
struct node* swap(struct node* start){
    struct node* p=start, *q=start->next;
    if(p->next!=NULL){
        p->next=q->next;
        q->prev=NULL;
        q->next=p;
        p->prev=q;
        start=q;
        if(p->next!=NULL){
            p=p->next;
            p->prev=q->next;
            q=p->next;
            while(q!=NULL){
                p->next=q->next;
                q->prev=p->prev;
                p->prev->next=q;
                p->prev=q;
                q->next=p;
                if(p->next!=NULL){
                p=p->next;
                p->prev=q->next;
                q=p->next;
                }else break;
            }
        }
    }return start;
}
void display(struct node* start) {
    struct node* temp = start;
    printf("\n\n     START");
    if(start == NULL) {
        printf("\n|-----------|\n|    NULL   |\n|-----------|");
        return;
    }
    printf("\n\n|--------|\n|%8u|\n|--------|", start);
    printf("\n        |\n        |");
    while(temp != NULL) {
        printf("     |--------------------|         ");
        temp = temp->next;
    }
    temp = start;
    printf("\n        ----->");
    printf("|  NULL  |%2d|%8u|------------->", temp->info, temp->next); 
        temp = temp->next;
    while(temp->next != NULL) {
        printf("|%-8u|%2d|%8u|------------->",temp->prev, temp->info, temp->next); 
        temp = temp->next;
    }
    printf("|%-8u|%2d|  NULL  |",temp->prev, temp->info); 
        temp = temp->next;
    temp = start;
    printf("\n");
    printf("              |--------------------|");
        temp = temp->next;
    while(temp != NULL) {
        printf("<-------------|--------------------|");
        temp = temp->next;
    }
}

int main(){
    struct node * start=NULL;
    printf("Name : Kedron Lucas\n");
    printf("Roll No : 23B-CO-031\n");
    start=createlist(start);
    printf("\nOriginal List:");
    display(start);
    start= swap(start);
    printf("\nSwapped List:");
    display(start);
    return 0;
}
