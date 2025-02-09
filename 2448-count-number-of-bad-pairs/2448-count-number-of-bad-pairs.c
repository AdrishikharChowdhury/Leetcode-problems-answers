#include <stdlib.h>
#include <string.h>

struct HashNode {
    long long key;
    long long count;
    struct HashNode* next;
};

struct HashMap {
    struct HashNode** buckets;
    int size;
};

// Initialize hash map
struct HashMap* createHashMap(int size) {
    struct HashMap* map = (struct HashMap*)malloc(sizeof(struct HashMap));
    map->size = size;
    map->buckets = (struct HashNode**)calloc(size, sizeof(struct HashNode*));
    return map;
}

// Hash function
int hash(long long key, int size) {
    return abs(key) % size;
}

// Get value from hash map
long long get(struct HashMap* map, long long key) {
    int index = hash(key, map->size);
    struct HashNode* current = map->buckets[index];
    
    while (current != NULL) {
        if (current->key == key) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

// Put value in hash map
void put(struct HashMap* map, long long key, long long value) {
    int index = hash(key, map->size);
    struct HashNode* current = map->buckets[index];
    
    // Check if key exists
    while (current != NULL) {
        if (current->key == key) {
            current->count = value;
            return;
        }
        current = current->next;
    }
    
    // Create new node
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->count = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

// Free hash map
void freeHashMap(struct HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        struct HashNode* current = map->buckets[i];
        while (current != NULL) {
            struct HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

long long countBadPairs(int* nums, int numsSize) {
    // Calculate total possible pairs
    long long n = numsSize;
    long long totalPairs = (n * (n - 1)) / 2;
    
    // Create hash map for frequency counting
    struct HashMap* freqMap = createHashMap(numsSize);
    
    // Count good pairs
    long long goodPairs = 0;
    for (int i = 0; i < numsSize; i++) {
        long long diff = (long long)nums[i] - i;
        long long freq = get(freqMap, diff);
        goodPairs += freq;
        put(freqMap, diff, freq + 1);
    }
    
    // Free hash map
    freeHashMap(freqMap);
    
    // Return total pairs minus good pairs
    return totalPairs - goodPairs;
}