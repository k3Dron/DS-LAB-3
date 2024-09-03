#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int data) {
    struct node* start = (struct node*)malloc(sizeof(struct node));
    if (!start) {
        printf("Memory error\n");
        return NULL;
    }
    start->data = data;
    start->next = NULL;
    return start;
}

void insert_at_beg(struct node* start, int data) {
    struct node* temp = create(data);
    temp->next = start;
    start = temp;
}

void insert_at_end(struct node* start, int data) {
    struct node* temp = create(data);
    if (start == NULL) {
        start = temp;
        return;
    }
    struct node* p = start;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
}

void delete_at_start(struct node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = start;
    start = (start)->next;
    free(temp);
}

void delete_at_end(struct node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node * p = start;
    while(p->next->next != NULL) {
        p = p->next;
    }
    p->next = NULL;
    return start;
}

void display(struct node* start) {
    struct node* temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct node* start = NULL;

    return 0;
}
