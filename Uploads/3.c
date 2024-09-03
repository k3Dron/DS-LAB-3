#include<stdio.h>
#include<stdlib.h>
//CO031

struct node {
    int data;
    struct node *link;
};

//add at end
struct node *add_at_end(struct node *start, int data) {
    struct node *p, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    p = start;
    if (start == NULL) {
        start = temp;
    } else {
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = temp;
    }
    return start;
}

//check if a node is already present
int if_present(struct node *start, int data) {
    struct node *p = start;
    while (p != NULL) {
        if (p->data == data) {
            return 1;
        }
        p = p->link;
    }
    return 0;
}

//union of two linked lists
struct node *find_Union(struct node *n1, struct node *n2) {
    struct node *p, *n, *s;
    n = NULL;
    s = n1;
    p = n2;
    while (s != NULL) {
        n = add_at_end(n, s->data);
        s = s->link;
    }
    while (p != NULL) {
        if (!if_present(n1, p->data)) {
            n = add_at_end(n, p->data);
        }
        p = p->link;
    }
    return n;
}

//intersection of two linked lists
struct node *find_Intersection(struct node *n1, struct node *n2) {
    struct node *p, *n;
    n = NULL;
    p = n2;
    while (p != NULL) {
        if (if_present(n1, p->data)) {
            n = add_at_end(n, p->data);
        }
        p = p->link;
    }
    return n;
}

//subtraction of two linked lists
struct node *find_Subtraction(struct node *uni, struct node *inter) {
    struct node *u, *i;
    struct node *n = NULL;
    u = uni;
    i = inter;
    while (u != NULL) {
        if (!if_present(i, u->data)) {
            n = add_at_end(n, u->data);
        }
        u = u->link;
    }
    return n;
}

//create a linked list
struct node *create_SLL() {
    int n, data;
    struct node *start = NULL;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the data of %d th element: ", i);
        scanf("%d", &data);
        start = add_at_end(start, data);
    }
    return start;
}

//display
void disp_LL(struct node *n) {
    struct node *p = n;
    printf("{ ");
    while (p != NULL) {
        printf("%d ", p->data);
        if(p->link != NULL) printf(", ");
        p = p->link;
    }
    printf(" }\n");
}

int main() {
    printf("Name : Kedron Lucas\n");
    printf("Roll No : 23B-CO-031\n");
    //create a linked list
    struct node * start1 = create_SLL();
    //crete another linnked list
    struct node * start2 = create_SLL();
    struct node * startuni = find_Union(start1, start2);
    struct node * startinter = find_Intersection(start1, start2);
    struct node * startsub = find_Subtraction(startuni, startinter);
    printf("First set : \n");
    disp_LL(start1);
    printf("Second set : \n");
    disp_LL(start2);
    printf("union of the two sets : \n");
    disp_LL(startuni);
    printf("intersection of the two sets : \n");
    disp_LL(startinter);
    printf("subtraction of the two sets : \n");
    disp_LL(startsub);
    return 0;
}

