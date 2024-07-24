/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct {
    int originalValue;
    long long mappedValue;
    int originalIndex;
} NumberInfo;

long long getMappedValue(int num, int* mapping) {
    if (num == 0) return mapping[0];
    long long mappedValue = 0;
    long long multiplier = 1;
    while (num > 0) {
        int digit = num % 10;
        mappedValue += (long long)mapping[digit] * multiplier;
        multiplier *= 10;
        num /= 10;
    }
    return mappedValue;
}

int compare(const void* a, const void* b) {
    NumberInfo* numA = (NumberInfo*)a;
    NumberInfo* numB = (NumberInfo*)b;
    if (numA->mappedValue != numB->mappedValue) {
        return numA->mappedValue > numB->mappedValue ? 1 : -1;
    }
    return numA->originalIndex - numB->originalIndex;
}

int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize) {
    NumberInfo* numberInfos = (NumberInfo*)malloc(numsSize * sizeof(NumberInfo));
    for (int i = 0; i < numsSize; i++) {
        numberInfos[i].originalValue = nums[i];
        numberInfos[i].mappedValue = getMappedValue(nums[i], mapping);
        numberInfos[i].originalIndex = i;
    }

    qsort(numberInfos, numsSize, sizeof(NumberInfo), compare);

    int* result = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        result[i] = numberInfos[i].originalValue;
    }

    *returnSize = numsSize;
    free(numberInfos);
    return result;
}