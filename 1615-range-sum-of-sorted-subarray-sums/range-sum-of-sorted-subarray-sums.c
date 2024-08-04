#include <stdlib.h>

#define MOD 1000000007

int compare(const void* a, const void* b) {
    return (*(long long*)a - *(long long*)b);
}

int rangeSum(int* nums, int numsSize, int n, int left, int right) {
    long long* sums = (long long*)malloc(sizeof(long long) * n * (n + 1) / 2);
    int index = 0;
    
    // Calculate all subarray sums
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            sums[index++] = sum;
        }
    }
    
    // Sort the sums
    qsort(sums, n * (n + 1) / 2, sizeof(long long), compare);
    
    // Calculate the range sum
    long long result = 0;
    for (int i = left - 1; i < right; i++) {
        result = (result + sums[i]) % MOD;
    }
    
    free(sums);
    return (int)result;
}