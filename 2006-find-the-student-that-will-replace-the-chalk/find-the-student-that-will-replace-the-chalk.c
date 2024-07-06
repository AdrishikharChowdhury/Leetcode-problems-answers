int chalkReplacer(int* chalk, int chalkSize, int k) {
    long long sum = 0;
    for (int i = 0; i < chalkSize; i++) {
        sum += chalk[i];
    }
    
    k = k % sum;  // Reduce k to be within one complete cycle
    
    for (int i = 0; i < chalkSize; i++) {
        if (k < chalk[i]) {
            return i;
        }
        k -= chalk[i];
    }
    return 0;
}