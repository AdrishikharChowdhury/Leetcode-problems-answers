// C Solution
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare strings for qsort
int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Function to check if str1 is prefix of str2
int isPrefix(char* str1, char* str2) {
    int len1 = strlen(str1);
    if (len1 >= strlen(str2)) return 0;
    
    // Check if str2 starts with str1 and has '/' after
    return strncmp(str1, str2, len1) == 0 && str2[len1] == '/';
}

char** removeSubfolders(char** folder, int folderSize, int* returnSize) {
    if (folderSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // Sort the array of strings
    qsort(folder, folderSize, sizeof(char*), compare);
    
    // Allocate memory for result
    char** result = (char**)malloc(folderSize * sizeof(char*));
    *returnSize = 0;
    
    // Add first folder to result
    result[(*returnSize)++] = folder[0];
    
    // Check each folder
    for (int i = 1; i < folderSize; i++) {
        int isSubfolder = 0;
        
        // Compare with all parent folders in result
        for (int j = 0; j < *returnSize; j++) {
            if (isPrefix(result[j], folder[i])) {
                isSubfolder = 1;
                break;
            }
        }
        
        // If not a subfolder, add to result
        if (!isSubfolder) {
            result[(*returnSize)++] = folder[i];
        }
    }
    
    return result;
}

