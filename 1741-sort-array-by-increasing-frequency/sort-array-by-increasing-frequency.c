/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUM 201

typedef struct {
    int num;
    int freq;
} Pair;

int compare(const void* a, const void* b) {
    Pair* pairA = (Pair*)a;
    Pair* pairB = (Pair*)b;
    if (pairA->freq != pairB->freq) {
        return pairA->freq - pairB->freq;
    }
    return pairB->num - pairA->num;
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int freq[MAX_NUM] = {0};
    Pair pairs[numsSize];
    int count = 0;
    
    // Count frequencies
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + 100]++;
    }
    
    // Create pairs
    for (int i = 0; i < MAX_NUM; i++) {
        if (freq[i] > 0) {
            pairs[count].num = i - 100;
            pairs[count].freq = freq[i];
            count++;
        }
    }
    
    // Sort pairs
    qsort(pairs, count, sizeof(Pair), compare);
    
    // Create result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    int index = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < pairs[i].freq; j++) {
            result[index++] = pairs[i].num;
        }
    }
    
    *returnSize = numsSize;
    return result;
}