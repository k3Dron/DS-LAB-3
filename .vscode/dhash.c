#include <stdio.h>
#define TABLE_SIZE 10

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void insert(int hashTable[], int key) {
    int index = hash1(key);
    int i = 0;
    while (hashTable[index] != -1) {
        index = (index + i * hash2(key)) % TABLE_SIZE;
        i++;
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
