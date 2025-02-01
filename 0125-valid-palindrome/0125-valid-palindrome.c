#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isAlphaNum(char ch) {
    return (ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z');
}

bool isPalindrome(char* s) {
    int st = 0, end = strlen(s) - 1;
    
    while (st < end) {
        if (!isAlphaNum(s[st])) {
            st++;
            continue;
        }
        if (!isAlphaNum(s[end])) {
            end--;
            continue;
        }
        if (tolower(s[st]) != tolower(s[end])) {
            return false;
        }
        st++;
        end--;
    }
    return true;
}
