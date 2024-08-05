#include <string.h>
#include <stdlib.h>

char * kthDistinct(char ** arr, int arrSize, int k){
    int* frequency = (int*)calloc(arrSize, sizeof(int));
    
    // Count the frequency of each string
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (strcmp(arr[i], arr[j]) == 0) {
                frequency[i]++;
            }
        }
    }
    
    // Find the kth distinct string
    int distinctCount = 0;
    for (int i = 0; i < arrSize; i++) {
        if (frequency[i] == 1) {
            distinctCount++;
            if (distinctCount == k) {
                free(frequency);
                return arr[i];
            }
        }
    }
    
    // If there are fewer than k distinct strings
    free(frequency);
    return "";
}