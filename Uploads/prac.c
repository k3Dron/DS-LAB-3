#include<iostream>
#include<stdlib>

struct node {
    struct node *lnood;
    int data;
    struct node *rnood;
}

struct node *stack[100];
int pos = -1;

void push(iint key) {
    if(pos == 100) {
        printf("stack is full");
        return;
    }
    stack[++pos] = key; 
}

struct node pop() {
    if(pos == -1) {
        printf("Stack is empty");
        return;
    }
    return stack[pos--];
}

void rpre(struct node root) {
    if(root == NULL) return;
    printf("%d", root->data);
    rpre(root->lnood);
    rpre(root->rnood);
}

void pre(struct node root) {
    struct node *ptr, *temp;
    ptr = root;
    if(ptr == NULL) {
        printf("Tree is empty");
        return;
    }
    push(ptr);
    while(!emptyStack()) {
        temp = pop();
        printf("%d", temp->data);
        if(ptr->rnode != NULL) {
            push(ptr->rnood);
        }
        if(ptr->lnood != NULL) {
            push(ptr->lnood);
        }
    }
    printf("\n");
}

void rin(struct node root) {
    if(root == NULL) {
        return;
    }
    rin(root->lnode);
    printf("%d", root->data);
    rin(root->rnode);
}

void in(struct node root) {
    
}