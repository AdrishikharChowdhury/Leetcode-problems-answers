#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 11  // Maximum digits for a 32-bit int, including sign

// Function to convert int to string
void intToStr(int num, char* str) {
    sprintf(str, "%d", num);
}

// Function to find the common prefix length between two strings
int commonPrefixLength(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i]) i++;
    return i;
}

// Compare function for qsort
int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Function to find the longest common prefix between two integer arrays
int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    // Allocate memory for string representations of arr1 and arr2
    char** str1 = (char**)malloc(arr1Size * sizeof(char*));
    char** str2 = (char**)malloc(arr2Size * sizeof(char*));

    // Convert integers to strings
    for (int i = 0; i < arr1Size; i++) {
        str1[i] = (char*)malloc((MAX_DIGITS + 1) * sizeof(char));
        intToStr(arr1[i], str1[i]);
    }
    for (int i = 0; i < arr2Size; i++) {
        str2[i] = (char*)malloc((MAX_DIGITS + 1) * sizeof(char));
        intToStr(arr2[i], str2[i]);
    }

    // Sort the string arrays
    qsort(str1, arr1Size, sizeof(char*), compare);
    qsort(str2, arr2Size, sizeof(char*), compare);

    int maxLength = 0;
    int i = 0, j = 0;

    // Use two-pointer approach to find the longest common prefix
    while (i < arr1Size && j < arr2Size) {
        int commonLength = commonPrefixLength(str1[i], str2[j]);
        if (commonLength > maxLength) {
            maxLength = commonLength;
        }

        // Move the pointer of the array with the smaller current element
        if (strcmp(str1[i], str2[j]) < 0) {
            i++;
        } else {
            j++;
        }
    }

    // Free allocated memory
    for (int i = 0; i < arr1Size; i++) free(str1[i]);
    for (int i = 0; i < arr2Size; i++) free(str2[i]);
    free(str1);
    free(str2);

    return maxLength;
}

