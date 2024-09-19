#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LEN 100

// Custom comparison function
int compare(const void* a, const void* b) {
    char str1[MAX_LEN * 2] = {0};
    char str2[MAX_LEN * 2] = {0};
    sprintf(str1, "%d%d", *(int*)a, *(int*)b);
    sprintf(str2, "%d%d", *(int*)b, *(int*)a);
    return strcmp(str2, str1);
}

char* largestNumber(int* nums, int numsSize) {
    // Sort the array using custom comparison
    qsort(nums, numsSize, sizeof(int), compare);
    
    // If the largest number is 0, the entire number is 0
    if (nums[0] == 0) {
        char* result = malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }
    
    // Calculate the total length needed for the result string
    int totalLen = 0;
    for (int i = 0; i < numsSize; i++) {
        int len = snprintf(NULL, 0, "%d", nums[i]);
        totalLen += len;
    }
    
    // Allocate memory for the result string
    char* result = malloc((totalLen + 1) * sizeof(char));
    char* ptr = result;
    
    // Build the largest number string
    for (int i = 0; i < numsSize; i++) {
        ptr += sprintf(ptr, "%d", nums[i]);
    }
    
    return result;
}