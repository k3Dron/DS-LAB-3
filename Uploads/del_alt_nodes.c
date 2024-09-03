#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};
struct node* addatend(struct node* last, int data);
struct node* addtoempty(struct node* last, int data);
struct node* createlist(struct node* last){
    int n, data;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    if(n==0){
        return NULL;
    }
    printf("\nEnter the data for node 1: ");
    scanf("%d",&data);
    last=addtoempty(last, data);
    for(int i=1;i<n;i++){
        printf("\nEnter the data for node %d: ",i+1);
        scanf("%d",&data);
        last=addatend(last, data);
    }
    return last;
}
struct node* addtoempty(struct node* last, int data){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    last = temp;
    last->link=last;
    return last;
}
struct node* addatend(struct node* last, int data){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=last->link;
    last->link=temp;
    last=temp;
    return last;
}
struct node* delalternodes(struct node* last){
    struct node* temp, *p;
    if(last==NULL){
        printf("\nList is empty ");
        exit(1);
    }
    if(last->link==last)
        return last;
    temp=last->link;
    if(temp->link==last){
        temp->link=temp;
        free(last);
        last=temp;
        return last;
    }
    while(temp!=last){
        if(temp->link!=last){
            p=temp->link;
            temp->link=p->link;
            temp=temp->link;
            free(p);
        }
        else{
            p=temp->link;
            temp->link=p->link;
            free(p);
            last=temp;
        }
    }
    return last;
}
void display(struct node* last) {
    struct node* temp;
    if(last==NULL){
        printf("\n  LAST");
        printf("\n|------|\n| NULL |\n|------|\n");
        return;
    }
    int n=0;
    temp=last->link;
    do{
        n++;
        temp=temp->link;
    }while(temp!=last->link);
    temp=last->link;
    printf("\n");
    for(int j=0;j<n;j++){
        printf("                 ");
    }printf("    LAST\n");
    for(int j=0;j<n;j++){
        printf("                 ");
    }printf("|--------|\n");
    for(int j=0;j<n;j++){
        printf("                 ");
    }printf("|%8u|\n",last);
    for(int j=0;j<n;j++){
        printf("                 ");
    }printf("|--------|\n");
    for(int j=0;j<n;j++){
        printf("                 ");
    }printf("   |\n");
    for(int j=0;j<n;j++){
        printf("|-----------|    ");
    }printf("<--|\n");
    for(int j=0;j<n-1;j++){
        printf("|%2d|%8u|--->",temp->info,temp->link);
        temp=temp->link;
    }printf("|%2d|%8u|     \n",temp->info,temp->link);
    for(int j=0;j<n;j++){
        printf("|-----------|    ");
    }printf("\n");
    printf("  ^");
    for(int j=0;j<n-1;j++){
        printf("                 ");
    }printf("     |");
    printf("\n");
    printf("  |");
    for(int j=0;j<n-1;j++){
        printf("-----------------");
    }printf("-----|\n");
}

int main(){
    printf("Name : Kedron Lucas\n");
    printf("Roll No : 23B-CO-031\n");
    struct node * list1=NULL;
    list1=createlist(list1);
    printf("\nOriginal List: \n");
    display(list1);
    list1=delalternodes(list1);
    printf("\nList after Deletion: \n");
    display(list1);
}