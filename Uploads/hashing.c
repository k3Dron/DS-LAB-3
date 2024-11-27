#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* next;
};

#define TABLE_SIZE 10

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node* hashTable[], int key) {
    int index = key % TABLE_SIZE;
    struct Node* newNode = createNode(key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

struct Node* search(struct Node* hashTable[], int key) {
    int index = key % TABLE_SIZE;
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

void printTable(struct Node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("hashTable[%d]: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Node* hashTable[TABLE_SIZE] = {NULL};

    insert(hashTable, 12);
    insert(hashTable, 22);
    insert(hashTable, 32);
    insert(hashTable, 42);
    insert(hashTable, 52);

    printTable(hashTable);

    int key = 22;
    struct Node* result = search(hashTable, key);
    if (result != NULL)
        printf("\nKey %d found in hash table.\n", key);
    else
        printf("\nKey %d not found in hash table.\n", key);

    return 0;
}
