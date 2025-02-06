// Hash table implementation for C
#define MAX_SIZE 500000

struct HashNode {
    int key;
    int count;
    struct HashNode* next;
};

struct HashTable {
    struct HashNode* table[MAX_SIZE];
};

int hash(int key) {
    return abs(key) % MAX_SIZE;
}

void insert(struct HashTable* ht, int key) {
    int index = hash(key);
    struct HashNode* current = ht->table[index];
    
    while (current != NULL) {
        if (current->key == key) {
            current->count++;
            return;
        }
        current = current->next;
    }
    
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int getCount(struct HashTable* ht, int key) {
    int index = hash(key);
    struct HashNode* current = ht->table[index];
    
    while (current != NULL) {
        if (current->key == key) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

void freeHashTable(struct HashTable* ht) {
    for (int i = 0; i < MAX_SIZE; i++) {
        struct HashNode* current = ht->table[i];
        while (current != NULL) {
            struct HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int tupleSameProduct(int* nums, int numsSize) {
    struct HashTable ht = {0};
    int result = 0;
    
    // Count products
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int product = nums[i] * nums[j];
            insert(&ht, product);
        }
    }
    
    // Calculate tuples
    for (int i = 0; i < MAX_SIZE; i++) {
        struct HashNode* current = ht.table[i];
        while (current != NULL) {
            int count = current->count;
            if (count > 1) {
                result += 8 * (count * (count - 1) / 2);
            }
            current = current->next;
        }
    }
    
    freeHashTable(&ht);
    return result;
}