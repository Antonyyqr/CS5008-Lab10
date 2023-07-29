#include <stdio.h>
#include <stdlib.h>

// Define constants
#define EMPTY -1
#define DELETED -2

// Function to create a new hash table
int* createHashTable(int size) {
    int* hashTable = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        hashTable[i] = EMPTY;
    return hashTable;
}

// Function to insert using linear probing
void linearProbing(int* hashTable, int size, int value) {
    int index = value % size;
    while(hashTable[index] != EMPTY && hashTable[index] != DELETED) {
        index = (index + 1) % size;
    }
    hashTable[index] = value;
}

// Function to insert using quadratic probing
void quadraticProbing(int* hashTable, int size, int value) {
    int index = value % size;
    int i = 0;
    while(hashTable[index] != EMPTY && hashTable[index] != DELETED) {
        i++;
        index = (index + i*i) % size;
    }
    hashTable[index] = value;
}

// Function to insert using double hashing
void doubleHashing(int* hashTable, int size, int value) {
    int h1 = value % size;
    int h2 = 7 - (value % 7);
    int index = h1;
    int i = 0;
    while(hashTable[index] != EMPTY && hashTable[index] != DELETED) {
        i++;
        index = (h1 + i*h2) % size;
    }
    hashTable[index] = value;
}

// Function to print the hash table
void printHashTable(int* hashTable, int size) {
    for (int i = 0; i < size; i++) {
        if (hashTable[i] != EMPTY && hashTable[i] != DELETED)
            printf("Index[%d] -> %d\n", i, hashTable[i]);
        else
            printf("Index[%d] -> NULL\n", i);
    }
}

int main() {
    int size, num_values, value, probe_type;

    printf("Enter the size of the hash table: ");
    scanf("%d", &size);

    int* hashTable = createHashTable(size);

    printf("Enter the number of values to insert: ");
    scanf("%d", &num_values);

    printf("Choose probing method (1: Linear Probing, 2: Quadratic Probing, 3: Double Hashing): ");
    scanf("%d", &probe_type);

    for (int i = 0; i < num_values; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &value);
        switch (probe_type) {
            case 1:
                linearProbing(hashTable, size, value);
                break;
            case 2:
                quadraticProbing(hashTable, size, value);
                break;
            case 3:
                doubleHashing(hashTable, size, value);
                break;
            default:
                printf("Invalid probing method chosen. Exiting.\n");
                return -1;
        }
    }

    printHashTable(hashTable, size);

    return 0;
}
