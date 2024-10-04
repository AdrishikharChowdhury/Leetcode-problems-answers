#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

long long dividePlayers(int* skill, int skillSize) {
    // Sort the array
    qsort(skill, skillSize, sizeof(int), compare);
    
    // First team's total skill will be our target
    int targetSum = skill[0] + skill[skillSize-1];
    long long totalChemistry = 0;
    
    // Check each pair from both ends
    for (int i = 0; i < skillSize/2; i++) {
        int currentSum = skill[i] + skill[skillSize-1-i];
        // If any pair doesn't match target sum, return -1
        if (currentSum != targetSum) {
            return -1;
        }
        // Add chemistry of current pair to total
        totalChemistry += (long long)skill[i] * skill[skillSize-1-i];
    }
    
    return totalChemistry;
}