#include <stdio.h>

int tribonacci(int n) {
    // Handle base cases
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    // Initialize first three numbers
    int t0 = 0, t1 = 1, t2 = 1;
    int result;
    
    // Calculate tribonacci numbers iteratively
    for (int i = 3; i <= n; i++) {
        result = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = result;
    }
    
    return result;
}