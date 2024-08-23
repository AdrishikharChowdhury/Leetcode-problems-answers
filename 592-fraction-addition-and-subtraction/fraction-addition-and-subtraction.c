#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

char* fractionAddition(char* expression) {
    int A = 0, B = 1;
    int i = 0, n = strlen(expression);
    
    while (i < n) {
        int a = 0, b = 0, sign = 1;
        if (expression[i] == '-' || expression[i] == '+') {
            sign = expression[i++] == '+' ? 1 : -1;
        }
        while (i < n && expression[i] != '/') {
            a = a * 10 + (expression[i++] - '0');
        }
        i++;  // skip '/'
        while (i < n && expression[i] != '+' && expression[i] != '-') {
            b = b * 10 + (expression[i++] - '0');
        }
        a *= sign;
        
        A = A * b + a * B;
        B *= b;
        int g = gcd(abs(A), B);
        A /= g;
        B /= g;
    }
    
    char* result = (char*)malloc(20 * sizeof(char));
    sprintf(result, "%d/%d", A, B);
    return result;
}