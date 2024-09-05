#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node *addToEmpty(struct node *last, int data) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    last = tmp;
    last->next = last;
    return last;
}

struct node *addAtEnd(struct node *last, int data) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = last->next;
    last->next = tmp;
    last = tmp;
    return last;
}

struct node *addAtBeg(struct node *last, int data) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = last->next;
    last->next = tmp;
    return last;
}

struct node *addAfter(struct node *last, int data, int item) {
    struct node *tmp, *p;
    p = last->next;
    do {
        if (p->data == item) {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->data = data;
            tmp->next = p->next;
            p->next = tmp;
            if (p == last)
                last = tmp;
            return last;
        }
        p = p->next;
    } while (p != last->next);
    printf("%d not present in the list\n", item);
    return last;
}

struct node *addBefore(struct node *last, int data, int item) {
    struct node *tmp, *p, *prev;
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (last->next->data == item) {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = data;
        tmp->next = last->next;
        last->next = tmp;
        return last;
    }
    prev = last->next;
    p = prev->next;
    do {
        if (p->data == item) {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->data = data;
            tmp->next = p;
            prev->next = tmp;
            return last;
        }
        prev = p;
        p = p->next;
    } while (p != last->next);
    printf("%d not present in the list\n", item);
    return last;
}

struct node *del(struct node *last, int data) {
    struct node *tmp, *p;
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (last->next == last && last->data == data) {
        tmp = last;
        last = NULL;
        free(tmp);
        return last;
    }
    if (last->next->data == data) {
        tmp = last->next;
        last->next = tmp->next;
        free(tmp);
        return last;
    }
    p = last->next;
    while (p->next != last) {
        if (p->next->data == data) {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
            return last;
        }
        p = p->next;
    }
    if (last->data == data) {
        tmp = last;
        p->next = last->next;
        last = p;
        free(tmp);
        return last;
    }
    printf("Element %d not found\n", data);
    return last;
}

struct node *reverse(struct node *last) {
    struct node *prev, *curr, *next, *first;
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    first = last->next;
    prev = last;
    curr = last->next;
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != first);
    last->next = prev;
    return last;
}

void display(struct node *last) {
    struct node *p;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    p = last->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("\n");
}

int countNodes(struct node *last) {
    struct node *p;
    int count = 0;
    if (last == NULL) {
        return 0;
    }
    p = last->next;
    do {
        count++;
        p = p->next;
    } while (p != last->next);
    return count;
}

int search(struct node *last, int data) {
    struct node *p;
    if (last == NULL) {
        return 0;
    }
    p = last->next;
    do {
        if (p->data == data) {
            return 1;
        }
        p = p->next;
    } while (p != last->next);
    return 0;
}

struct node *createList(struct node *last, int n) {
    int i, data;
    if (n == 0) {
        return last;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    last = addToEmpty(last, data);
    for (i = 2; i <= n; i++) {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        last = addAtEnd(last, data);
    }
    return last;
}

int main() {
    struct node *last = NULL;
    int choice, data, item, n;

    while (1) {
        printf("\n1. Create List\n");
        printf("2. Display\n");
        printf("3. Add to empty list\n");
        printf("4. Add at beginning\n");
        printf("5. Add at end\n");
        printf("6. Add after\n");
        printf("7. Add before\n");
        printf("8. Delete\n");
        printf("9. Reverse\n");
        printf("10. Count Nodes\n");
        printf("11. Search\n");
        printf("12. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                last = createList(last, n);
                break;
            case 2:
                display(last);
                break;
            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                last = addToEmpty(last, data);
                break;
            case 4:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                last = addAtBeg(last, data);
                break;
            case 5:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                last = addAtEnd(last, data);
                break;
            case 6:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &item);
                last = addAfter(last, data, item);
                break;
            case 7:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &item);
                last = addBefore(last, data, item);
                break;
            case 8:
                printf("Enter the element to be deleted: ");
                scanf("%d", &data);
                last = del(last, data);
                break;
            case 9:
                last = reverse(last);
                break;
            case 10:
                printf("Total nodes: %d\n", countNodes(last));
                break;
            case 11:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                if (search(last, data))
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;
            case 12:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}