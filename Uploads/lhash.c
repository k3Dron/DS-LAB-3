#include <stdio.h>
#define TABLE_SIZE 10

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int hashTable[], int key) {
    int index = hash(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

void printTable(int hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("hashTable[%d] : ~ \n", i);
        } else {
            printf("hashTable[%d] : %d \n", i, hashTable[i]);
        }
    }
}

int main() {
    int hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    int keys[] = {12, 22, 32, 42, 52};
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        insert(hashTable, keys[i]);
    }

    printTable(hashTable);
    return 0;
}
