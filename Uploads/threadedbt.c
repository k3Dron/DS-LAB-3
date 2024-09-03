#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    bool rightThread;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->rightThread = false;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    struct Node* parent = NULL;
    struct Node* current = root;
    while (current != NULL) {
        if (data == current->data) {
            printf("Duplicate key!\n");
            return root;
        }
        parent = current;
        if (data < current->data) {
            if (current->left == NULL) break;
            current = current->left;
        } else {
            if (current->rightThread) break;
            current = current->right;
        }
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->rightThread = true;
    if (parent == NULL) {
        root = newNode;
    } else if (data < parent->data) {
        newNode->right = parent;
        parent->left = newNode;
    } else {
        newNode->right = parent->right;
        parent->right = newNode;
        parent->rightThread = false;
    }

    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    struct Node* parent = NULL;
    struct Node* current = root;
    while (current != NULL && current->data != key) {
        parent = current;
        if (key < current->data) {
            current = current->left;
        } else {
            if (current->rightThread) break;
            current = current->right;
        }
    }
    if (current == NULL || current->data != key) {
        printf("Key not found!\n");
        return root;
    }
    if (current->left == NULL && (current->right == NULL || current->rightThread)) {
        if (parent == NULL) {
            root = NULL;
        } else if (current == parent->left) {
            parent->left = NULL;
        } else {
            parent->right = current->right;
            parent->rightThread = true;
        }
        free(current);
    }
    else if (current->left == NULL || (current->right == NULL || current->rightThread)) {
        struct Node* child = (current->left != NULL) ? current->left : current->right;
        if (parent == NULL) {
            root = child;
        } else if (current == parent->left) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(current);
    }
    else {
        struct Node* successor = current->right;
        struct Node* successorParent = current;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
            successorParent->rightThread = true;
        }
        free(successor);
    }

    return root;
}

struct Node* leftMost(struct Node* node) {
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}

struct Node* search(struct Node* root, int key) {
    struct Node* current = leftMost(root);
    while (current != NULL) {
        if (current->data == key)
            return current;
        if (current->rightThread)
            current = current->right;
        else
            current = leftMost(current->right);
    }
    return NULL;
}

void display(struct Node* root) {
    struct Node* current = leftMost(root);
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->rightThread)
            current = current->right;
        else
            current = leftMost(current->right);
    }
}

int main() {
    int o = 1, c, i;
    struct Node* root = NULL;
    while(o != 0) {
        printf("\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 to search\nEnter 4 to display\nEnter 0 to Exit\n");
        scanf("%d", &c);
        switch(c) {
            case 1:
                printf("Enter element to be added: ");
                scanf("%d", &i);
                root = insert(root, i);
                break;
            case 2: 
                printf("Enter element to be deleted: ");
                scanf("%d", &i);
                root = deleteNode(root, i);
                break;
            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &i);
                struct Node* result = search(root, i);
                if (result != NULL)
                    printf("Element %d found in the tree.\n", i);
                else
                    printf("Element %d not found in the tree.\n", i);
                break;
            case 4:
                display(root);
                printf("\n");
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}
