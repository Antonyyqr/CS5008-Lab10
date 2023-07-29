#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int value;
    struct node *next;
} node;

// Function to create a new node
node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node into hash table
void insertNode(node** hashTable, int size, int value) {
    int index = value % size;
    node* newNode = createNode(value);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the hash table
void printHashTable(node** hashTable, int size) {
    for (int i = 0; i < size; i++) {
        printf("Chain[%d] -> ", i);
        node* temp = hashTable[i];
        while (temp) {
            printf("%d -> ", temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int size, num_values, value;

    printf("Enter the size of the hash table: ");
    scanf("%d", &size);

    node** hashTable = (node**)malloc(size * sizeof(node*));
    for (int i = 0; i < size; i++)
        hashTable[i] = NULL;

    printf("Enter the number of values to insert: ");
    scanf("%d", &num_values);

    for (int i = 0; i < num_values; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &value);
        insertNode(hashTable, size, value);
    }

    printHashTable(hashTable, size);

    return 0;
}

