long long calSteps(long long n, long long n1, long long n2);
long long findKthNumber(int n, int k) {
    long long curr = 1;
    k--;  // Since we start with 1, which is the first number
    
    while (k > 0) {
        long long steps = calSteps(n, curr, curr + 1);
        if (steps <= k) {
            curr += 1;
            k -= steps;
        } else {
            curr *= 10;
            k--;
        }
    }
    return curr;
}

long long calSteps(long long n, long long n1, long long n2) {
    long long steps = 0;
    while (n1 <= n) {
        steps += fmin(n + 1, n2) - n1;
        n1 *= 10;
        n2 *= 10;
    }
    return steps;
}