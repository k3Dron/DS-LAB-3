#include <stdio.h>
#include <stdlib.h>

int preorder[] = {40, 32, 20, 34, 88, 47, 78, 64, 53, 73, 66, 81, 82, 92, 93};
int inorder[] = {20, 32, 34, 40, 47, 53, 64, 66, 73, 78, 81, 82, 88, 92, 93};
int postorder[] = {20, 34, 32, 53, 66, 64, 73, 82, 81, 78, 47, 93, 92, 88, 40};

struct ListNode {
    int data;
    struct ListNode *link;
};

struct ListNode* insert_at_end(struct ListNode* start, int data) {
    struct ListNode* temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->link = NULL;
    if (start == NULL) {
        return temp;
    }
    struct ListNode* p = start;
    while (p->link != NULL) {
        p = p->link;
    }
    p->link = temp;
    return start;
}

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *const_inpre(struct ListNode *inptr, struct ListNode *preptr, int num) {
    if (num == 0) return NULL;
    struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->data = preptr->data;
    temp->left = NULL;
    temp->right = NULL;
    if (num == 1) return temp;
    struct ListNode *q = inptr;
    int i;
    for (i = 0; q->data != preptr->data; i++) q = q->link;
    temp->left = const_inpre(inptr, preptr->link, i);
    for (int j = 1; j <= i + 1; j++) preptr = preptr->link;
    temp->right = const_inpre(q->link, preptr, num - i - 1);
    return temp;
}

struct TreeNode *const_inpost(struct ListNode *inptr, struct ListNode *postptr, int num) {
    if (num == 0) return NULL;
    struct ListNode *ptr = postptr;
    for (int i = 1; i < num; i++) ptr = ptr->link;
    struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->data = ptr->data;
    temp->left = NULL;
    temp->right = NULL;
    if (num == 1) return temp;
    struct ListNode *q = inptr;
    int i;
    for (i = 0; q->link != ptr->link; i++) q = q->link;
    temp->left = const_inpost(inptr, postptr, i);
    for (int j = 1; j <= i; j++) postptr = postptr->link;
    temp->right = const_inpost(q->link, postptr, num - i - 1);
    return temp;
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void tree_in_pre() {
    struct ListNode *inorderll = NULL;
    struct ListNode *preorderll = NULL;
    for (int i = 0; i < sizeof(inorder) / sizeof(inorder[0]); i++) {
        inorderll = insert_at_end(inorderll, inorder[i]);
        preorderll = insert_at_end(preorderll, preorder[i]);
    }
    struct TreeNode *tree = const_inpre(inorderll, preorderll, sizeof(inorder) / sizeof(inorder[0]));
    printf("\nInorder: ");
    inorderTraversal(tree);
    printf("\nPreorder: ");
    preorderTraversal(tree);
}

void tree_in_post() {
    struct ListNode *inorderll = NULL;
    struct ListNode *postorderll = NULL;
    for (int i = 0; i < sizeof(inorder) / sizeof(inorder[0]); i++) {
        inorderll = insert_at_end(inorderll, inorder[i]);
        postorderll = insert_at_end(postorderll, postorder[i]);
    }
    struct TreeNode *tree = const_inpost(inorderll, postorderll, sizeof(inorder) / sizeof(inorder[0]));
    printf("\nInorder: ");
    inorderTraversal(tree);
    printf("\nPostorder: ");
    postorderTraversal(tree);
}

int heigth(struct TreeNode *ptr) {
    int hleft, hright;
    if(ptr == NULL){
        return 0;
    }
    hleft = height(ptr->left);
    hright = height(ptr->right);
    if(hleft > hright) hleft++;
    else hright++;
}

int main() {
    printf("Name : Kedron Lucas\n");
    printf("Roll No : 23B-CO-031\n");
    int o;
    printf("Enter 1 to build tree from inorder and preorder\nEnter 2 to build tree from inorder and postorder\nEnter 3 to find height of tree created\nEnter 0 to exit\n");
    scanf("%d", &o);
    switch(o) {
        case 1: 
            tree_in_pre();
            break;
        case 2: 
            tree_in_post();
            break;
        case 3: 
            height();
            break;
        case 0: 
            exit(0);
            break;
        default: 
            printf("Enter the proper value");
    }
    return 0;
}
