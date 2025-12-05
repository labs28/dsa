#include <stdio.h>

#define SIZE 10     // hash table size

int hashTable[SIZE];

// Function to initialize hash table with -1 (meaning empty)
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using Linear Probing
void insert(int key) {
    int index = hash(key);

    // If collision happens, probe linearly
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;   // move to next index
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Search element
int search(int key) {
    int index = hash(key);

    // Linear probing search
    int start = index;  // to avoid infinite loop
    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;

        index = (index + 1) % SIZE;

        if (index == start)   // came back to starting point
            return -1;
    }

    return -1;
}

int main() {
    init();

    insert(23);
    insert(43);
    insert(13);
    insert(27);

    int key;
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    int pos = search(key);

    if (pos != -1)
        printf("Element %d found at index %d\n", key, pos);
    else
        printf("Element %d not found in hash table\n", key);

    return 0;
}
