#define MAX_ROWS 300
#define MAX_COLS 300

// Hash function for string
unsigned long hash(char* str, int len) {
    unsigned long hash = 5381;
    for (int i = 0; i < len; i++) {
        hash = ((hash << 5) + hash) + str[i];
    }
    return hash;
}

// Hash table structure
typedef struct {
    char key[MAX_COLS + 1];
    int count;
} HashEntry;

int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize) {
    HashEntry hashTable[MAX_ROWS * 2];
    int hashTableSize = 0;
    int maxEqualRows = 0;
    
    for (int i = 0; i < matrixSize; i++) {
        char original[MAX_COLS + 1] = {0};
        char flipped[MAX_COLS + 1] = {0};
        
        // Create original and flipped patterns
        for (int j = 0; j < matrixColSize[0]; j++) {
            original[j] = matrix[i][j] + '0';
            flipped[j] = (1 - matrix[i][j]) + '0';
        }
        
        // Choose lexicographically smaller pattern
        char* key = strcmp(original, flipped) <= 0 ? original : flipped;
        
        // Find or add to hash table
        int found = 0;
        for (int j = 0; j < hashTableSize; j++) {
            if (strcmp(hashTable[j].key, key) == 0) {
                hashTable[j].count++;
                maxEqualRows = fmax(maxEqualRows, hashTable[j].count);
                found = 1;
                break;
            }
        }
        
        // If not found, add new entry
        if (!found) {
            strcpy(hashTable[hashTableSize].key, key);
            hashTable[hashTableSize].count = 1;
            maxEqualRows = fmax(maxEqualRows, 1);
            hashTableSize++;
        }
    }
    
    return maxEqualRows;
}