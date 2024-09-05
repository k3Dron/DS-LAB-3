#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList(int n) {
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Unable to allocate memory.");
        exit(0);
    }
    printf("Enter the data of node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;
    for (i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Unable to allocate memory.");
            break;
        }
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void traverse() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

void insertAtFront(int data) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(int data, int position) {
    struct node *newNode, *temp;
    int i;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    temp = head;
    for (i = 2; i <= position - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            break;
        }
    }
    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFirst() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteEnd() {
    struct node *temp, *prevNode;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next != NULL) {
            prevNode = temp;
            temp = temp->next;
        }
        free(temp);
        prevNode->next = NULL;
    }
}

void deletePosition(int position) {
    struct node *temp, *positionNode;
    int i;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    } else {
        temp = head;
        for (i = 2; i <= position - 1; i++) {
            temp = temp->next;
            if (temp == NULL) {
                break;
            }
        }
        if (temp != NULL && temp->next != NULL) {
            positionNode = temp->next;
            temp->next = positionNode->next;
            free(positionNode);
        }
    }
}

void maximum() {
    struct node *temp;
    int max;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    max = temp->data;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    printf("Maximum value: %d\n", max);
}

void mean() {
    struct node *temp;
    int sum = 0, count = 0;
    float mean;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    mean = (float)sum / count;
    printf("Mean value: %.2f\n", mean);
}

void sort() {
    struct node *current = head, *index = NULL;
    int temp;
    if (head == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void reverseLL() {
    struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void search(int key) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found in the list.\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list.\n", key);
}

int main() {
    int choice, data, position, n;
    while (1) {
        printf("1. Create List\n");
        printf("2. Traverse\n");
        printf("3. Insert at Front\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete First\n");
        printf("7. Delete End\n");
        printf("8. Delete Position\n");
        printf("9. Maximum\n");
        printf("10. Mean\n");
        printf("11. Sort\n");
        printf("12. Reverse\n");
        printf("13. Search\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                traverse();
                break;
            case 3:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(data, position);
                break;
            case 6:
                deleteFirst();
                break;
            case 7:
                deleteEnd();
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletePosition(position);
                break;
            case 9:
                maximum();
                break;
            case 10:
                mean();
                break;
            case 11:
                sort();
                break;
            case 12:
                reverseLL();
                break;
            case 13:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 14:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
