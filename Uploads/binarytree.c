#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node *ninsert(struct Node* root, int data) {
    struct Node *p;
    p = root;
    while(p != NULL) {
        if(!search(root, data)) {
            if(data<root->data) {
                p = p->left;
            } else p = p->right;
        } else printf("already present");
    }
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int search(struct Node* root, int i) {
    if(root == NULL) return 0;
    if(root->data == i) return 1;
    else {
        if(root->data < i) {
            return search(root->right, i);
        } else return search(root->left, i);
    } 
}

struct Node* findMin(struct Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct Node* deleteNode(struct Node* root, int d) {
    if (root == NULL)
        return root;
    if (d < root->data)
        root->left = deleteNode(root->left, d);
    else if (d > root->data)
        root->right = deleteNode(root->right, d);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    printf("Name : Kedron Lucas\n");
    printf("Roll No : 23B-CO-031\n");
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 35);
    insert(root, 80);
    printf("\n");
    inorder(root);
    if(search(root, 30)) {
       printf("\nIt is present\n");
    } else {
        printf("\nIt is not present\n");
    }
    deleteNode(root, 70);
    printf("\n");
    inorder(root);
    return 0;
}