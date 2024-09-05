#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* t1 = head1;
    while (t1 != NULL) {
        struct Node* t2 = head2;
        while (t2 != NULL) {
            if (t1->data == t2->data) {
                insert(&result, t1->data);
                break;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return result;
}

struct Node* getDifference(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* t1 = head1;
    while (t1 != NULL) {
        struct Node* t2 = head2;
        int found = 0;
        while (t2 != NULL) {
            if (t1->data == t2->data) {
                found = 1;
                break;
            }
            t2 = t2->next;
        }
        if (!found) {
            insert(&result, t1->data);
        }
        t1 = t1->next;
    }
    return result;
}

int main() {
    struct Node* L1 = NULL;
    struct Node* L2 = NULL;
    struct Node* intersection = NULL;
    struct Node* differenceL1L2 = NULL;
    struct Node* differenceL2L1 = NULL;

    insert(&L1, 20);
    insert(&L1, 15);
    insert(&L1, 10);
    insert(&L1, 5);

    insert(&L2, 10);
    insert(&L2, 5);
    insert(&L2, 2);
    insert(&L2, 1);

    printf("List L1: ");
    printList(L1);

    printf("List L2: ");
    printList(L2);

    intersection = getIntersection(L1, L2);
    printf("Intersection of L1 and L2: ");
    printList(intersection);

    differenceL1L2 = getDifference(L1, L2);
    printf("Difference L1 - L2: ");
    printList(differenceL1L2);

    differenceL2L1 = getDifference(L2, L1);
    printf("Difference L2 - L1: ");
    printList(differenceL2L1);

    return 0;
}
