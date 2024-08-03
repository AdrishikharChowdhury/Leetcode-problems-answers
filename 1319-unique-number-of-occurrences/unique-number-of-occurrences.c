#define MAX_NUM 1000

bool uniqueOccurrences(int* arr, int arrSize) {
    // Step 1: Count occurrences
    int countMap[2001] = {0};  // Handles range -1000 to 1000
    for (int i = 0; i < arrSize; i++) {
        countMap[arr[i] + 1000]++;
    }
    
    // Step 2: Check if counts are unique
    bool seenCounts[MAX_NUM + 1] = {false};
    for (int i = 0; i < 2001; i++) {
        if (countMap[i] > 0) {
            if (seenCounts[countMap[i]]) {
                return false;
            }
            seenCounts[countMap[i]] = true;
        }
    }
    
    return true;
}