/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define SIZE 200001

struct Node {
    long long key;
    int val;
    struct Node* next;
};

struct HashMap {
    struct Node* table[SIZE];
};

int hash(long long key) {
    return (int)(key % SIZE);
}

int get(struct HashMap* map, long long key) {
    int index = hash(key);
    struct Node* curr = map->table[index];
    while (curr) {
        if (curr->key == key) return curr->val;
        curr = curr->next;
    }
    return 0;
}

void put(struct HashMap* map, long long key, int val) {
    int index = hash(key);
    struct Node* curr = map->table[index];
    
    while (curr) {
        if (curr->key == key) {
            curr->val = val;
            return;
        }
        curr = curr->next;
    }
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->val = val;
    newNode->next = map->table[index];
    map->table[index] = newNode;
}

int containsKey(struct HashMap* map, long long key) {
    int index = hash(key);
    struct Node* curr = map->table[index];
    while (curr) {
        if (curr->key == key) return 1;
        curr = curr->next;
    }
    return 0;
}

void freeMap(struct HashMap* map) {
    for (int i = 0; i < SIZE; i++) {
        struct Node* curr = map->table[i];
        while (curr) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int* queryResults(int limit, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    struct HashMap ballColors = {0};
    struct HashMap colorCounts = {0};
    int* result = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    int distinctCount = 0;
    
    for (int i = 0; i < queriesSize; i++) {
        int ball = queries[i][0];
        int newColor = queries[i][1];
        
        if (containsKey(&ballColors, ball)) {
            int oldColor = get(&ballColors, ball);
            int count = get(&colorCounts, oldColor);
            if (count == 1) {
                distinctCount--;
            }
            put(&colorCounts, oldColor, count - 1);
        }
        
        put(&ballColors, ball, newColor);
        int newCount = get(&colorCounts, newColor);
        if (newCount == 0) distinctCount++;
        put(&colorCounts, newColor, newCount + 1);
        
        result[i] = distinctCount;
    }
    
    freeMap(&ballColors);
    freeMap(&colorCounts);
    return result;
}