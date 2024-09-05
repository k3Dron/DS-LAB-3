#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *create_list(struct node *last) {
    int i, n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    last = NULL;
    if (n == 0)
        return last;
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    last = addtoempty(last, data);
    for (i = 2; i <= n; i++) {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        last = addatend(last, data);
    }
    return last;
}

void display(struct node *last) {
    struct node *p;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    p = last->link;
    do {
        printf("%d ", p->info);
        p = p->link;
    } while (p != last->link);
    printf("\n");
}

struct node *addtoempty(struct node *last, int data) {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    last = tmp;
    last->link = last;
    return last;
}

struct node *addatend(struct node *last, int data) {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;
    return last;
}

struct node *addatbeg(struct node *last, int data) {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    return last;
}

struct node *addafter(struct node *last, int data, int item) {
    struct node *tmp, *p;
    p = last->link;
    do {
        if (p->info == item) {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            if (p == last)
                last = tmp;
            return last;
        }
        p = p->link;
    } while (p != last->link);
    printf("%d not present in the list\n", item);
    return last;
}

struct node *addbefore(struct node *last, int data, int item) {
    struct node *tmp, *p, *prev;
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (last->link->info == item) {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->link = last->link;
        last->link = tmp;
        return last;
    }
    prev = last->link;
    p = prev->link;
    do {
        if (p->info == item) {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p;
            prev->link = tmp;
            return last;
        }
        prev = p;
        p = p->link;
    } while (p != last->link);
    printf("%d not present in the list\n", item);
    return last;
}

struct node *del(struct node *last, int data) {
    struct node *tmp, *p;
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (last->link == last && last->info == data) {
        tmp = last;
        last = NULL;
        free(tmp);
        return last;
    }
    if (last->link->info == data) {
        tmp = last->link;
        last->link = tmp->link;
        free(tmp);
        return last;
    }
    p = last->link;
    while (p->link != last) {
        if (p->link->info == data) {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return last;
        }
        p = p->link;
    }
    if (last->info == data) {
        tmp = last;
        p->link = last->link;
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
    first = last->link;
    prev = last;
    curr = last->link;
    do {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    } while (curr != first);
    last->link = prev;
    return last;
}

int main() {
    struct node *last = NULL;
    int choice, data, item;
    while (1) {
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Add to empty list\n");
        printf("4. Add at beginning\n");
        printf("5. Add at end\n");
        printf("6. Add after\n");
        printf("7. Add before\n");
        printf("8. Delete\n");
        printf("9. Reverse\n");
        printf("10. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                last = create_list(last);
                break;
            case 2:
                display(last);
                break;
            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                last = addtoempty(last, data);
                break;
            case 4:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                last = addatbeg(last, data);
                break;
            case 5:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                last = addatend(last, data);
                break;
            case 6:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the element after which to be inserted: ");
                scanf("%d", &item);
                last = addafter(last, data, item);
                break;
            case 7:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the element before which to be inserted: ");
                scanf("%d", &item);
                last = addbefore(last, data, item);
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
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

