bool canMakeSubsequence(char *str1, char *str2) {
    int i = 0, j = 0;
    int len1 = strlen(str1), len2 = strlen(str2);

    while (i < len1 && j < len2) {
        // Check for direct match or single cyclic increment
        if (str1[i] == str2[j] || (str1[i] - 'a' + 1) % 26 + 'a' == str2[j]) {
            j++;
        }
        i++;
    }

    // Return true only if all characters in str2 are matched
    return j == len2;
}