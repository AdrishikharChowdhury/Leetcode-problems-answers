#include <stdlib.h>
#include <string.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

struct HashNode {
    int key;
    int value;
    struct HashNode* next;
};

struct HashMap {
    struct HashNode** array;
    int size;
};

// Hash function
int hash(int key, int size) {
    int hash = key % size;
    return hash < 0 ? hash + size : hash;
}

// Initialize hash map
struct HashMap* createHashMap(int size) {
    struct HashMap* map = (struct HashMap*)malloc(sizeof(struct HashMap));
    map->size = size;
    map->array = (struct HashNode**)calloc(size, sizeof(struct HashNode*));
    return map;
}

// Put key-value pair in hash map
void put(struct HashMap* map, int key, int value) {
    int index = hash(key, map->size);
    struct HashNode* node = map->array[index];
    
    while (node != NULL) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->array[index];
    map->array[index] = newNode;
}

// Get value for key from hash map
int get(struct HashMap* map, int key, int* exists) {
    int index = hash(key, map->size);
    struct HashNode* node = map->array[index];
    
    while (node != NULL) {
        if (node->key == key) {
            *exists = 1;
            return node->value;
        }
        node = node->next;
    }
    *exists = 0;
    return -1;
}

// Free hash map memory
void freeHashMap(struct HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        struct HashNode* node = map->array[i];
        while (node != NULL) {
            struct HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(map->array);
    free(map);
}

int minSubarray(int* nums, int numsSize, int p) {
    int result = numsSize;
    long long total = 0;
    
    // Calculate target remainder
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    
    if (total % p == 0) return 0;
    int target = (int)(total % p);
    
    // Create hash map
    struct HashMap* map = createHashMap(numsSize * 2);
    put(map, 0, -1);
    
    int currSum = 0;
    for (int i = 0; i < numsSize; i++) {
        currSum = (int)((currSum + (long long)nums[i]) % p);
        int want = (currSum - target + p) % p;
        
        int exists;
        int prevIndex = get(map, want, &exists);
        if (exists) {
            result = MIN(result, i - prevIndex);
        }
        put(map, currSum, i);
    }
    
    freeHashMap(map);
    return result < numsSize ? result : -1;
}