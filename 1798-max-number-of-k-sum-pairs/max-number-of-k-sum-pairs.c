#include <stdlib.h>

struct HashNode {
    int key;
    int value;
    struct HashNode* next;
};

struct HashMap {
    struct HashNode** buckets;
    int size;
};

struct HashMap* createHashMap(int size) {
    struct HashMap* map = (struct HashMap*)malloc(sizeof(struct HashMap));
    map->size = size;
    map->buckets = (struct HashNode**)calloc(size, sizeof(struct HashNode*));
    return map;
}

int hash(struct HashMap* map, int key) {
    return abs(key) % map->size;
}

void put(struct HashMap* map, int key, int value) {
    int index = hash(map, key);
    struct HashNode* node = map->buckets[index];
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
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

int get(struct HashMap* map, int key) {
    int index = hash(map, key);
    struct HashNode* node = map->buckets[index];
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return 0;
}

void freeHashMap(struct HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        struct HashNode* node = map->buckets[i];
        while (node != NULL) {
            struct HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

int maxOperations(int* nums, int numsSize, int k) {
    struct HashMap* map = createHashMap(numsSize);
    int operations = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int complement = k - nums[i];
        if (get(map, complement) > 0) {
            operations++;
            put(map, complement, get(map, complement) - 1);
        } else {
            put(map, nums[i], get(map, nums[i]) + 1);
        }
    }
    
    freeHashMap(map);
    return operations;
}