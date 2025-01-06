int binarySearch(int* potions, int m, long long spell, long long success) {
    int left = 0, right = m;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if ((long long)spell * potions[mid] >= success) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    *returnSize = spellsSize;
    int* pairs = (int*)malloc(spellsSize * sizeof(int));
    
    // Sort potions array
    qsort(potions, potionsSize, sizeof(int), compare);
    
    // For each spell, binary search for minimum valid potion
    for (int i = 0; i < spellsSize; i++) {
        int pos = binarySearch(potions, potionsSize, spells[i], success);
        pairs[i] = potionsSize - pos;
    }
    
    return pairs;
}