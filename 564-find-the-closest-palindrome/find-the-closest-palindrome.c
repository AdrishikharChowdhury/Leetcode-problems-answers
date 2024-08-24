#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

// Helper function to check if a number is a power of ten
int isPowerOfTen(long long num) {
    while (num > 1 && num % 10 == 0) {
        num /= 10;
    }
    return num == 1;
}

// Helper function to generate palindrome by adding 1s
long long generatePalindromeByAdding1s(int len) {
    return (long long)pow(10, len) + 1;
}

// Helper function to generate palindrome by subtracting 1s
long long generatePalindromeBySubtracting1s(int len) {
    return (long long)pow(10, len - 1) - 1;
}

// Helper function to generate palindrome from a given prefix
long long generatePalindrome(long long prefix, int isEven) {
    long long result = prefix;
    if (!isEven) {
        prefix /= 10;
    }
    while (prefix > 0) {
        result = result * 10 + (prefix % 10);
        prefix /= 10;
    }
    return result;
}

// Helper function to find the closest palindrome
long long getClosest(long long num, long long *candidates, int candidateCount) {
    long long closest = 0;
    long long minDiff = LLONG_MAX;
    for (int i = 0; i < candidateCount; i++) {
        long long candidate = candidates[i];
        if (candidate == num) continue;
        long long diff = llabs(candidate - num);
        if (diff < minDiff || (diff == minDiff && candidate < closest)) {
            closest = candidate;
            minDiff = diff;
        }
    }
    return closest;
}

char* nearestPalindromic(char* n) {
    long long num = atoll(n);
    int len = strlen(n);
    
    // Special case for "1"
    if (strcmp(n, "1") == 0) {
        char* result = (char*)malloc(2);
        strcpy(result, "0");
        return result;
    }
    
    // Handle single-digit numbers separately
    if (len == 1) {
        char* result = (char*)malloc(2);
        sprintf(result, "%lld", num - 1);
        return result;
    }
    
    // Edge cases for numbers like 10, 100, etc.
    if (isPowerOfTen(num)) {
        char* result = (char*)malloc(len + 1);
        sprintf(result, "%lld", num - 1);
        return result;
    }
    if (isPowerOfTen(num + 1)) {
        char* result = (char*)malloc(len + 2);
        sprintf(result, "%lld", num + 2);
        return result;
    }
    
    // Generate candidates
    long long candidates[5];
    candidates[0] = generatePalindromeByAdding1s(len);
    candidates[1] = generatePalindromeBySubtracting1s(len);
    
    long long prefix = atoll(strndup(n, (len + 1) / 2));
    int candidateCount = 2;
    
    for (long long i = prefix - 1; i <= prefix + 1; i++) {
        candidates[candidateCount++] = generatePalindrome(i, len % 2 == 0);
    }
    
    // Find the closest palindrome
    long long closest = getClosest(num, candidates, candidateCount);
    
    // Prepare result as a string
    char* result = (char*)malloc(len + 2);
    sprintf(result, "%lld", closest);
    return result;
}

