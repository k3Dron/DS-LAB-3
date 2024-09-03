#include<stdio.h>
#include<Stdlib.h>

struct node {
    int data;
    struct node * prev;
    struct node * next;
};

struct node* add_at_end(struct node* start, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL) {
        return temp;
    }

    struct node* p = start;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = temp;
    temp->prev = p;
    return start;
}

struct node * add_at_beg(struct node * start, int data) {
    struct node * temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = start;
    temp->prev = NULL;
    return temp;
}

struct node * add_after(struct node * start, int item, int data) {
    struct node * temp, * p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    p = start;
    while(p->data != item) {
        p = p->next;
    }
    temp->next = p->next;
    temp->prev = p;
    p->next = temp;
    return start;
}

struct node * add_before(struct node * start, int item, int data) {
    struct node * temp, * p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    p = start;
    while(p->next->data != item) {
        p = p->next;
    }
    temp->next = p->next;
    temp->prev = p;
    p->next = temp;
    return start;
}



int delete_at_end(struct node * start) {
    struct node * p;
    p = start;
    while(p->next != NULL) {
        p = p->next;
    }
    struct node * q = p->prev;
    int i = p->data;
    q->next = NULL;
    free(p);
    return i;
}

void display(struct node * start) {
    struct node * p;
    p = start;
    printf("\n");
    while(p != NULL) {
        printf("\0%d\0", p->data);
    }
    printf("\n");
}

int main() {
    struct node* start = NULL;
    start = add_at_beg(start, 1);
    start = add_at_end(start, 2);
    start = add_at_end(start, 3);
    start = add_at_end(start, 4);
    display(start);
    int deletedValue = delete_at_end(start);
    printf("Deleted value: %d\n", deletedValue);
    display(start);
    return 0;
}